%{
typedef struct yy_buffer_state * YY_BUFFER_STATE;

extern "C" int yylex();
extern "C" int yyparse();
extern YY_BUFFER_STATE yy_scan_string(const char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
extern unsigned int line_number;
extern char * yytext;
void yyerror(const char * s);
%}


%code requires {
    /* Goes into the .h I think */
    #include <list>
    #include <memory>
    #include <string>

    #include "Eigen/Eigen"
typedef std::pair<std::string, std::list<unsigned int>*> str_type;
typedef std::list<str_type*> prod_type;
}

%code top {
    /* Goes into the .cpp I think */
#include <iostream>
#include <list>
#include <map>
#include <string>

#include <QString>

#include "Grammars/grammar.h"
#include "Grammars/production.h"
#include "Grammars/medusatype.h"

typedef std::shared_ptr<grammar::MedusaType> type_ptr;
typedef std::pair<std::string, std::list<unsigned int>*> str_type;
typedef std::list<str_type*> prod_type;
typedef std::shared_ptr<grammar::Production> prod_ptr;
typedef std::pair<type_ptr, std::vector<unsigned int>> restruct;
typedef std::shared_ptr<restruct> restruct_ptr;

void parse_grammar(QString string, grammar::Grammar * grammar);
void add_production(str_type * initial, int newnodes,
                    std::list<prod_type*> * prod_list,
                    grammar::Grammar * grammar);

grammar::Grammar * _grammar;
std::map<std::string,type_ptr> _type_dict;

class initialization_error : public std::invalid_argument
{
   public:
      initialization_error(const char * s)
          : std::invalid_argument(s)
      {}
};
}

%union
{
    int ival;
    std::string * sval;
    std::list<unsigned int> * ilistval;
    str_type * strval;
    std::list<str_type*> * strlistval;
    std::list<prod_type*> * prodlistval;
    Eigen::Vector2d * vecval;
    std::list<Eigen::Vector2d*> * veclistval;
}

%token TERMINAL NONTERMINAL AXIOM
%token ARROW
%token SEMICOLON LPAR RPAR COMMA VERT LBRA RBRA

%token <ival> INT
%token <sval> STRING

%type <ilistval> INTS
%type <vecval> VECTOR
%type <veclistval> VECTORS

%type <strval> structure
%type <strlistval> production
%type <prodlistval> productions

%%

grammar:
    statements
    ;
statements:
    statements statement
    | statement
    ;
statement:
    termdef
    | nontermdef
    | axiomdef
    | proddef
    ;
termdef:
    TERMINAL STRING LPAR INT RPAR LBRA VECTORS RBRA SEMICOLON {
        /*std::cout << "New terminal: \"" << *$2 << "\" of arity "*/
                  /*<< $4 << std::endl;*/
        type_ptr type = std::make_shared<grammar::MedusaType>(*$2);
        for( Eigen::Vector2d * point : *$7 )
        {
            type->points.push_back(*point);
        }
        delete $7;
        _type_dict[*$2] = type;
        delete $2;
        _grammar->addMedusaType(type);
    }
    ;
nontermdef:
    NONTERMINAL STRING LPAR INT RPAR SEMICOLON {
        /*std::cout << "New non-terminal: \"" << *$2 << "\" of arity "*/
                  /*<< $4 << std::endl;*/
        type_ptr type = std::make_shared<grammar::MedusaType>(*$2);
        _type_dict[*$2] = type;
        delete $2;
        _grammar->addMedusaType(type);
    }
    ;
axiomdef:
    AXIOM STRING SEMICOLON {
        if( _grammar->getAxiom() )
            throw std::invalid_argument("Axiom defined twice");
        try
        {
            type_ptr type = _type_dict.at(*$2);
            _grammar->setAxiom(type);
        }
        catch(const std::out_of_range & exception)
        {
            std::ostringstream sstream;
            sstream << "Undefined element \"" << *$2 << "\"";
            delete $2;
            throw initialization_error(sstream.str().c_str());
        }
        delete $2;
    }
    ;
proddef:
    structure INT ARROW productions SEMICOLON {
        add_production($1, $2, $4, _grammar);
        delete $1;
        delete $4;
    }
    ;
productions:
    production VERT productions {
        $3->push_back($1);
        $$ = $3;
    }
    | production {
        std::list<prod_type*> * lst = new std::list<prod_type*>();
        lst->push_back($1);
        $$ = lst;
    }
    ;
production:
    structure COMMA production {
        $3->push_back($1);
        $$ = $3;
    }
    | structure {
        std::list<str_type*> * lst = new std::list<str_type*>();
        lst->push_back($1);
        $$ = lst;
    }
    ;
structure:
    STRING LPAR INTS RPAR {
        $$ = new str_type(*$1,$3);
    }
    | STRING LPAR RPAR {
        $$ = new str_type(*$1, new std::list<unsigned int>());
    }
    ;
INTS:
    INTS COMMA INT {
        $1->push_back($3);
        $$ = $1;
    }
    | INT {
        std::list<unsigned int> * lst = new std::list<unsigned int>();
        lst->push_back($1);
        $$ = lst;
    }
    ;
VECTOR:
    LPAR INT COMMA INT RPAR {
        $$ = new Eigen::Vector2d($2,$4);
    }
    ;
VECTORS:
    VECTORS COMMA VECTOR {
        $1->push_back($3);
        $$ = $1;
    }
    | VECTOR {
        std::list<Eigen::Vector2d *> * lst = new std::list<Eigen::Vector2d *>();
        lst->push_back($1);
        $$ = lst;
    }
    ;

%%

void parse_grammar(QString string, grammar::Grammar * grammar)
{
    _grammar = grammar;
    YY_BUFFER_STATE buffstate = yy_scan_string(string.toStdString().c_str());
    yyparse();
    yy_delete_buffer(buffstate);
    if( !_grammar->getAxiom() )
        throw initialization_error("No axiom selected");
}

void add_production(str_type *initial, int newnodes,
                    std::list<prod_type *> *prod_list,
                    grammar::Grammar * grammar)
{
    type_ptr head = _type_dict[initial->first];
    unsigned int nodeCount = initial->second->size() + newnodes;
    std::vector<int> _map(nodeCount, -1);
    auto iterator = initial->second->begin();
    for(unsigned int index = 0; index < initial->second->size(); index++)
    {
        _map[*iterator] = index;
        iterator++;
    }
    for(prod_type * prod : *prod_list)
    {
        prod_ptr newprod =
                std::make_shared<grammar::Production>(head, newnodes);
        unsigned int map_index = initial->second->size();
        std::vector<int> map(_map);
        for(str_type * structure : *prod)
        {
            type_ptr body_type = _type_dict[structure->first];
            std::vector<unsigned int> aps;
            for(unsigned int value : *(structure->second))
            {
                if( !(value < nodeCount) )
                {
                    std::ostringstream stream;
                    stream << value << " out of range";
                    throw std::invalid_argument(stream.str());
                }
                if( map[value] == -1 )
                    map[value] = map_index++;
                aps.push_back(map[value]);
            }
            restruct_ptr body = std::make_shared<restruct>(body_type,
                                                           aps);
            newprod->addBodyStructure(body);
        }
        grammar->addProduction(newprod);
    }
}

void yyerror(const char * s)
{
    std::cout << line_number << ": " << s << " on token \"" << yytext << "\""
              << std::endl;
}
