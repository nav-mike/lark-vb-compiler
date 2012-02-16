%option noyywrap
%option never-interactive

%{
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  #include "vb_lark.tab.h"
  
  extern int yyparse(void);
  extern int print_tree();
  
  char literal[100];
  int num = 0;
  
  #define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

%}
%option yylineno

DIGIT  [0-9]
LETTER [A-Za-z]

%x COMMENT
%x STRING

%%

[à-ÿÀ-ß]+                {
						   getchar();
						   exit(1);
						 }

Dim                      {
						   return DIM;
						 }
						 
(Sub[[:space:]]Main\(\)) {
						   return SUB_MAIN;
						 }
						 
As                       {
						   return AS;
						 }
						 
True                     {
						   return TRUE;
						 }
						 
False                    {
						   return FALSE;
						 }
						 
If                       {
						   return IF;
						 }
						 
Then                     {
						   return THEN;
						 }
						 
ElseIf                   {
						   return ELSEIF;
						 }
						 
Else                     {
						   return ELSE;
						 }
						 
(End[[:space:]]If)       {
						   return END_IF;
						 }
						 
Function                 {
						   return FUNCTION;
						 }
						 
ByVal                    {
						   return BYVAL;
						 }

ByRef                    {
							return BYREF;
						 }
						 
Return                   {
						   return RETURN;
						 }
						 
(End[[:space:]]Function) {
						   return END_FUNCTION;
						 }
						 
Sub                      {
						   return SUB;
						 }
						 
(End[[:space:]]Sub)      {
						   return END_SUB;
						 }
						 
Try                      {
						   return TRY;
						 }
						 
Catch                    {
						   return CATCH;
						 }
						 
(End[[:space:]]Try)      {
						   return END_TRY;
						 }
						 
Throw                    {
						   return THROW;
						 }
						 
Boolean                  {
						   return BOOLEAN;
						 }
						 
Integer                  {
						   return INTEGER;
						 }
						 
New                      {
						   return NEW;
						 }
						 
Case                     {
						   return CASE;
						 }
						 
Char                     {
						   return CHAR;
						 }
						 
Const                    {
						   return CONST;
						 }
						 
Select                   {
						   return SELECT;
						 }
						 
(While)					 {
						   return WHILE;
						 }
						 
(Until)					 {
						   return UNTIL;
						 }
						 
Module                   {
						   return MODULE;
						 }
						 
Do                       {
						   return DO;
						 }
						 
Enum                     {
						   return ENUM;
						 }
						 
(End[[:space:]]Enum)     {
						   return END_ENUM;
						 }
						 
(End[[:space:]]Module)   {
						   return END_MODULE;
						 }
						 
(End[[:space:]]Select)   {
						   return END_SELECT;
						 }
						 
(End[[:space:]]While)    {
						   return END_WHILE;
						 }
						 
Loop                     {
						   return LOOP;
						 }
						 
Step                     {
						   return STEP;
						 }
						 
(For[[:space:]]Each)     {
						   return FOR_EACH;
						 }
						 
For                      {
						   return FOR;
						 }
						 
To                       {
						   return TO;
						 }
						 
Next                     {
						   return NEXT;
						 }
						 
In                       {
						   return IN;
						 }
						 
String                   {
						   return STRING_T;
						 }
						 
Mod                      {
						   return MOD;
						 }
						 
Console                  {
						   return CONSOLE;
						 }
						 
Write                    {
						   return WRITE;
						 }
						 
WriteLine                {
						   return WRITELINE;
						 }
						 
Read                     { 
						   return READ;
						 }
						 
ReadLine                 {
						   return READLINE;
						 }
						 						 
System                   {
						   return SYSTEM;
						 }
						 
Exception                {
						   return EXCEPTION;
						 }

\=                       {
						   return '=';
						 }
						 
\+                       {
						   return '+';
						 }
						 
\-                       {
						   return '-';
						 }
						 
\*                       {
						   return '*';
						 }
						 
\\                       {
						   return '\\';
						 }
						 
\/                       {
						   return '/';
						 }
						 
\^                       {
						   return '^';
						 }
						 
\>                       {
						   return '>';
						 }
						 
\<                       {
						   return '<';
						 }
						 
\>\=                     {
						   return MORE_OR_EQUAL;
						 }
						 
\<\=                     {
						   return LESS_OR_EQUAL;
						 }
						 
\<\>                     {
						   return NONEQUAL;
						 }

\(                       {
						   return '(';
						 }
						 
\)                       {
						   return ')';
						 }
						 
\{                       {
						   return '{';
						 }
						 
\}                       {
						   return '}';
						 }

\,                       {
						   return ',';
						 }
						 
\.                       {
						   return '.';
						 }
						 
\:						 {
						   return ':';
						 }

\'                       { BEGIN(COMMENT);				 }

<COMMENT>\n              { BEGIN(INITIAL); return ENDL;  }

<COMMENT>.+              {								 }

\"                       {
                           strcpy(literal,"");
						   BEGIN(STRING);
						 }
						 
<STRING>[^\"\n]+         {
                           strcat(literal,yytext);
						 }
						 
<STRING>\n               {
						   BEGIN(INITIAL);
						   return ENDL;
						 }
						 
<STRING>\"\"             {
                           strcat(literal,"\"");
						 }
						 
<STRING>[à-ÿÀ-ß]+        {
                           printf("\nIncorrect characters in a string!\n");
						   getchar();
						   exit(1);
						 }
						 
<STRING>\"               {
						   BEGIN(INITIAL);
						   yylval.s_const = (char*)malloc(strlen(literal)+1);
						   strcpy(yylval.s_const, literal);
						   return STRING_CONST;
						 }
						 
vbCrLf                   {
						   yylval.c_const = '\n';
						   return CHAR_CONST;
						 }
						 
vbTab                    {
						   yylval.c_const = '\t';
						   return CHAR_CONST;
						 }
						 
NullChar                 {
						   yylval.c_const = '\0';
						   return CHAR_CONST;
						 }

[a-zA-Z_][_a-zA-Z0-9]*   {
						   yylval.s_const = (char*)malloc(strlen(yytext)+1);
						   strcpy(yylval.s_const, yytext);
						   return ID;
						 }

{DIGIT}+                 {
						   yylval.i_const = atoi(yytext);
						   return INT_CONST;
						 }
						 
\&H[0-9A-F]+             {
                           sscanf(yytext, "%h", &num);
						   yylval.i_const = num;
						   return INT_CONST;
						 }
						 
\&O[0-7]+                {
                           sscanf(yytext, "%o", &num);
						   yylval.i_const = num;
						   return INT_CONST;
						 }
						 
\n+                      {
						   return ENDL;
						   yylineno++;
						 }
%%