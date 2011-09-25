%option noyywrap
%option never-interactive

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
%}
%x COMMENT
%%

Dim { printf("Special word \"Dim\" has found\n"); }
As { printf("Special word \"As\" has found\n"); }
If { printf("Special word \"If\" has found\n"); }
Then { printf("Special word \"Then\" has found\n"); }
ElseIf { printf("Special word \"ElseIf\" has found\n"); }
Else { printf("Special word \"Else\" has found\n"); }
(End[[:space:]]If) { printf("Special words \"End If\" has found\n"); }
Function { printf("Special word \"Function\" has found\n"); }
ByVal { printf("Special word \"ByVal\" has found\n"); }
Return { printf("Special word \"Return\" has found\n"); }
(End[[:space:]]Function) { printf("Special words \"End Function\" has found\n"); }
Sub { printf("Special word \"Sub\" has found\n"); }
(End[[:space:]]Sub) { printf("Special words \"End Sub\" has found\n"); }
Try { printf("Special words \"Try\" has found\n"); }
Catch { printf("Special words \"Catch\" has found\n"); }
(End[[:space:]]Try) { printf("Special words \"End Try\" has found\n"); }
Throw { printf("Special words \"Throw\" has found\n"); }
"\'" { printf("Comment:\n"); BEGIN(COMMENT); }
<COMMENT>\n { printf("End of comment\n"); BEGIN(INITIAL); }
[a-zA-Z_][_a-zA-Z0-9]* { printf("ID %s has found\n", yytext); }
%%
int main()
{
  yyin = fopen("sortArray.vb", "r");
  yylex();
  getchar();
}