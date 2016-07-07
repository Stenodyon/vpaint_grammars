/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_GUI_GRAMMARS_PARSER_Y_H_INCLUDED
# define YY_YY_SRC_GUI_GRAMMARS_PARSER_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 14 "../../src/Gui/Grammars/parser.y" /* yacc.c:1909  */

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

#line 62 "../../src/Gui/Grammars/parser.y.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TERMINAL = 258,
    NONTERMINAL = 259,
    AXIOM = 260,
    COLOR = 261,
    ARROW = 262,
    SEMICOLON = 263,
    LPAR = 264,
    RPAR = 265,
    COMMA = 266,
    VERT = 267,
    LBRA = 268,
    RBRA = 269,
    PLUS = 270,
    TIMES = 271,
    EQUAL = 272,
    PARENTX = 273,
    PARENTY = 274,
    PARENTROTATION = 275,
    NUMBER = 276,
    STRING = 277,
    ATTRIBUTENAME = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 73 "../../src/Gui/Grammars/parser.y" /* yacc.c:1909  */

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

#line 114 "../../src/Gui/Grammars/parser.y.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_GUI_GRAMMARS_PARSER_Y_H_INCLUDED  */
