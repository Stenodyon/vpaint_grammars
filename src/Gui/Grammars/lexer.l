%{
#include <iostream>
#include <cstring>
#include "parser.h"
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

[ \t] ;
\n { line_number++; }

[A-Z][a-zA-Z0-9_]* {
        yylval.sval = new std::string(strdup(yytext));
        return STRING;
}

[0-9]+ {
    yylval.ival = atoi(yytext);
    return INT;
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
%%
