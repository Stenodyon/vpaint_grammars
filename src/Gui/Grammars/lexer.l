%{
#include <iostream>
#include <cstring>
#include <string>
#include "parser.y.h"
#define YY_DECL extern "C" int yylex()

unsigned int line_number = 1;
%}
%%
terminal {
    return TERMINAL;
}

non\-terminal {
    return NONTERMINAL;
}

axiom {
    return AXIOM;
}

color {
    return COLOR;
}

parent\.x {
    return PARENTX;
}

parent\.y {
    return PARENTY;
}

parent\.rotation {
    return PARENTROTATION;
}

[ \t] ;
\n { line_number++; }

[A-Z][a-zA-Z0-9_]* {
    yylval.sval = new std::string(strdup(yytext));
    return STRING;
}

[a-z_]+ {
     yylval.sval = new std::string(strdup(yytext));
     return ATTRIBUTENAME;
}

\-?[0-9]+(\.[0-9]*)? {
    yylval.sval = new std::string(strdup(yytext));
    return NUMBER;
}

\-> {
    return ARROW;
}

";" { return SEMICOLON; }
"(" { return LPAR; }
")" { return RPAR; }
"," { return COMMA; }
"|" { return VERT; }
"[" { return LBRA; }
"]" { return RBRA; }
"+" { return PLUS; }
"*" { return TIMES; }
"=" { return EQUAL; }
%%
