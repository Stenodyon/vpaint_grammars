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

#include "production.h"
#include "attributeexpr.h"

typedef grammar::Production::result_structure restruct;
typedef std::pair<std::string, std::list<unsigned int>*> str_type;
typedef std::list<restruct*> prod_type;
typedef std::pair<std::string, grammar::AttributeExpr*> attribute_t;
typedef std::list<attribute_t*> attrlist;
}

%code top {
    /* Goes into the .cpp I think */
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

#include <QString>

#include "Grammars/grammar.h"
#include "Grammars/production.h"
#include "Grammars/medusatype.h"

typedef std::shared_ptr<grammar::MedusaType> type_ptr;
typedef std::pair<std::string, std::list<unsigned int>*> str_type;
typedef grammar::Production::result_structure restruct;
typedef std::list<restruct*> prod_type;
typedef std::shared_ptr<grammar::Production> prod_ptr;
typedef std::shared_ptr<restruct> restruct_ptr;
typedef std::pair<std::string, grammar::AttributeExpr*> attribute_t;
typedef std::list<attribute_t*> attrlist;

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
    double fval;
    std::string * sval;
    std::list<unsigned int> * ilistval;
    str_type * strval;
    std::list<restruct*> * strlistval;
    std::list<prod_type*> * prodlistval;
    Eigen::Vector2d * vecval;
    std::list<Eigen::Vector2d*> * veclistval;
    grammar::AttributeExpr * exprval;
    attribute_t * attrval;
    attrlist * attrlistval;
    restruct * restructval;
}

%token TERMINAL NONTERMINAL AXIOM COLOR
%token ARROW
%token SEMICOLON LPAR RPAR COMMA VERT LBRA RBRA
%token PLUS TIMES EQUAL
%token PARENTX PARENTY PARENTROTATION

%token <sval> NUMBER
%token <sval> STRING
%token <sval> ATTRIBUTENAME

%type <ilistval> INTS
%type <vecval> VECTOR
%type <veclistval> VECTORS

%type <strval> structure
%type <restructval> attributedstructure
%type <strlistval> production
%type <prodlistval> productions

%type <attrlistval> attributes
%type <attrval> attribute

%type <exprval> expression
%type <exprval> term
%type <exprval> factor

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
    TERMINAL STRING LPAR NUMBER RPAR LBRA VECTORS RBRA SEMICOLON {
        /*std::cout << "New terminal: \"" << *$2 << "\" of arity "*/
                  /*<< $4 << std::endl;*/
        unsigned int arity = std::stoi(*$4);
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
    NONTERMINAL STRING LPAR NUMBER RPAR SEMICOLON {
        /*std::cout << "New non-terminal: \"" << *$2 << "\" of arity "*/
                  /*<< $4 << std::endl;*/
        unsigned int arity = std::stoi(*$4);
        type_ptr type = std::make_shared<grammar::MedusaType>(*$2);
        _type_dict[*$2] = type;
        delete $2;
        _grammar->addMedusaType(type);
    }
    ;
axiomdef:
    AXIOM STRING SEMICOLON {
        if( _grammar->getAxiom() )
        {
            delete $2;
            throw std::invalid_argument("Axiom defined twice");
        }
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
    structure NUMBER ARROW productions SEMICOLON {
        unsigned int newNodes = std::stoi(*$2);
        add_production($1, newNodes, $4, _grammar);
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
    attributedstructure COMMA production {
        $3->push_back($1);
        $$ = $3;
    }
    | attributedstructure {
        std::list<restruct*> * lst = new std::list<restruct*>();
        lst->push_back($1);
        $$ = lst;
    }
    ;
attributedstructure:
    STRING LPAR INTS VERT attributes RPAR {
        type_ptr type = _type_dict[*$1];
        restruct * rs = new restruct(type, $3);
        for(auto attribute : *$5)
        {
            std::string name = attribute->first;
            if(name == "x")
            {
                rs->x_expr = attribute->second;
                continue;
            }
            else if(name == "y")
            {
                rs->y_expr = attribute->second;
                continue;
            }
            else if(name == "rotation")
            {
                rs->rotation = attribute->second;
                continue;
            }
            std::ostringstream stream;
            stream << "Unknown attribute \"" << name << "\"";
            throw std::invalid_argument(stream.str());
        }
        $$ = rs;
    }
    | STRING LPAR attributes RPAR {
        std::vector<unsigned int> empty;
        type_ptr type = _type_dict[*$1];
        restruct * rs = new restruct(type, &empty);
        for(auto attribute : *$3)
        {
            std::string name = attribute->first;
            if(name == "x")
            {
                rs->x_expr = attribute->second;
                continue;
            }
            else if(name == "y")
            {
                rs->y_expr = attribute->second;
                continue;
            }
            else if(name == "rotation")
            {
                rs->rotation = attribute->second;
                continue;
            }
            std::ostringstream stream;
            stream << "Unknown attribute \"" << name << "\"";
            throw std::invalid_argument(stream.str());
        }
        $$ = rs;
    }
    | STRING LPAR INTS RPAR {
        type_ptr type = _type_dict[*$1];
        $$ = new restruct(type, $3);
    }
    | STRING LPAR RPAR {
        std::vector<unsigned int> empty;
        type_ptr type = _type_dict[*$1];
        $$ = new restruct(type, &empty);
    }
    ;
structure:
    STRING LPAR INTS RPAR {
        $$ = new str_type(*$1, $3);
    }
    | STRING LPAR RPAR {
        $$ = new str_type(*$1, new std::list<unsigned int>());
    }
    ;
INTS:
    INTS COMMA NUMBER {
        $1->push_back(std::stoi(*$3));
        $$ = $1;
    }
    | NUMBER {
        std::list<unsigned int> * lst = new std::list<unsigned int>();
        lst->push_back(std::stoi(*$1));
        $$ = lst;
    }
    ;
VECTOR:
    LPAR NUMBER COMMA NUMBER RPAR {
        $$ = new Eigen::Vector2d(std::stoi(*$2),std::stoi(*$4));
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
attributes:
    attribute COMMA attributes {
        $3->push_back($1);
        $$ = $3;
    }
    | attribute {
        attrlist * lst = new attrlist();
        lst->push_back($1);
        $$ = lst;
    }
    ;
attribute:
    COLOR EQUAL STRING
    | ATTRIBUTENAME EQUAL expression {
        $$ = new attribute_t(*$1, $3);
    }
    ;
expression:
    expression PLUS term {
        $$ = new grammar::AddAttributeExpr($1,$3);
    }
    | term {
        $$ = $1;
    }
    ;
term:
    term TIMES factor {
        $$ = new grammar::MultAttributeExpr($1,$3);
    }
    | factor {
        $$ = $1;
    }
    ;
factor:
    NUMBER {
        $$ = new grammar::ConstantAttributeExpr(std::stod(*$1));
    }
    | PARENTX {
        $$ = new grammar::InheritedXAttributeExpr();
    }
    | PARENTY {
        $$ = new grammar::InheritedYAttributeExpr();
    }
    | PARENTROTATION {
        $$ = new grammar::InheritedRotationAttributeExpr();
    }
    | LPAR expression RPAR {
        $$ = $2;
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
        throw initialization_error("No axiom specified");
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
        for(restruct * structure : *prod)
        {
            for(unsigned int index = 0;
                index < structure->size();
                index++)
            {
                unsigned int value = (*structure)[index];
                if( !(value < nodeCount) )
                {
                    std::ostringstream stream;
                    stream << value << " out of range";
                    throw std::invalid_argument(stream.str());
                }
                if( map[value] == -1 )
                    map[value] = map_index++;
                (*structure)[index] = map[value];
            }
            restruct_ptr body = std::shared_ptr<restruct>(structure);
            newprod->addBodyStructure(body);
        }
        grammar->addProduction(newprod);
    }
}

void yyerror(const char * s)
{
    std::ostringstream sstream;
    sstream << line_number << ": " << s << " on token \"" << yytext << "\""
            << std::endl;
    throw std::invalid_argument(sstream.str());
}
