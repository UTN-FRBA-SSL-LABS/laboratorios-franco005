%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int  yylex(void);
void yyerror(const char *msg) { fprintf(stderr, "Error: %s\n", msg); }
%}

%token NUM
%token POW
%token UMINUS   /* token ficticio para el menos unario */

/* Declaraciones de precedencia (de menor a mayor precedencia) */
%left '+' '-'           /* TODO 1: Menor precedencia */
%left '*' '/'           /* TODO 2: Mayor precedencia que + y - */
%right POW              /* TODO 3: Mayor precedencia que * y / */
%right UMINUS           /* TODO 4: Mayor precedencia de todas */

%%

input:
    /* vacío */
  | input linea
  ;

linea:
    exp '\n'    { printf("= %d\n", $1); }
  ;

exp:
    exp '+' exp           { $$ = $1 + $3; }
  | exp '-' exp           { $$ = $1 - $3; }
  | exp '*' exp           { $$ = $1 * $3; }
  | exp '/' exp           { $$ = $1 / $3; }
  | exp POW exp           { $$ = (int)pow($1, $3); }
  | '-' exp %prec UMINUS  { $$ = -$2; } /* TODO 5: Cambia el signo de la expresión ($2) */
  | '(' exp ')'           { $$ = $2; }
  | NUM                   { $$ = $1; }
  ;

%%

int main(void) {
    return yyparse();
}