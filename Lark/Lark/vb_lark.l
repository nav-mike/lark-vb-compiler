%option noyywrap
%option never-interactive

%{
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  #include "vb_lark.tab.h"
  
  extern int yyparse(void);
  extern int print_tree();
  
  //extern FILE* file;
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

[‡-ˇ¿-ﬂ]+                {
                          // fprintf(file, "\nIncorrect characters:");
						   //fprintf(file, " %d:%d\n", yylloc.first_line, yylloc.first_column);
						   getchar();
						   exit(1);
						 }

\n+                      {
                          //fprintf(file, "\nEnd line has found\n");
						   return ENDL;
						   yylineno++;
						 }

Dim                      {
                          //fprintf(file,"\nKeyword \"Dim\" has found\n");
						   return DIM;
						 }
						 
(Sub[[:space:]]Main\(\)) {
                          //fprintf(file,"\nKeyword \"Dim\" has found\n");
						   return SUB_MAIN;
						 }
						 
As                       {
                           //fprintf(file,"\nKeyword \"As\" has found\n");
						   return AS;
						 }
						 
True                     {
                           //fprintf(file,"\nKeyword \"True\" has found\n");
						   return TRUE;
						 }
						 
False                    {
                           //fprintf(file,"\nKeyword \"False\" has found\n");
						   return FALSE;
						 }
						 
If                       {
                           printf("\nKeyword \"If\" has found\n");
						   return IF;
						 }
						 
Then                     {
                           printf("\nKeyword \"Then\" has found\n");
						   return THEN;
						 }
						 
ElseIf                   {
                           printf("\nKeyword \"ElseIf\" has found\n");
						   return ELSEIF;
						 }
						 
Else                     {
                           printf("\nKeyword \"Else\" has found\n");
						   return ELSE;
						 }
						 
(End[[:space:]]If)       {
                           printf("\nKeywords \"End If\" has found\n");
						   return END_IF;
						 }
						 
Function                 {
                           //fprintf(file,"\nKeyword \"Function\" has found\n");
						   return FUNCTION;
						 }
						 
ByVal                    {
                           //fprintf(file,"\nKeyword \"ByVal\" has found\n");
						   return BYVAL;
						 }

ByRef                    {
							//fprintf(file,"\nKeyword \"ByVal\" has found\n");
							return BYREF;
						 }
						 
Return                   {
                           //fprintf(file,"\nKeyword \"Return\" has found\n");
						   return RETURN;
						 }
						 
(End[[:space:]]Function) {
                           //fprintf(file,"\nKeywords \"End Function\" has found\n");
						   return END_FUNCTION;
						 }
						 
Sub                      {
                           //fprintf(file,"\nKeyword \"Sub\" has found\n");
						   return SUB;
						 }
						 
(End[[:space:]]Sub)      {
                          // fprintf(file,"\nKeywords \"End Sub\" has found\n");
						   return END_SUB;
						 }
						 
Try                      {
                          // fprintf(file,"\nKeywords \"Try\" has found\n");
						   return TRY;
						 }
						 
Catch                    {
                           //fprintf(file,"\nKeywords \"Catch\" has found\n");
						   return CATCH;
						 }
						 
(End[[:space:]]Try)      {
                           //fprintf(file,"\nKeywords \"End Try\" has found\n");
						   return END_TRY;
						 }
						 
Throw                    {
                           //fprintf(file,"\nKeywords \"Throw\" has found\n");
						   return THROW;
						 }
						 
Boolean                  {
                           //fprintf(file,"\nKeyword \"Boolean\" has found\n");
						   return BOOLEAN;
						 }
						 
Integer                  {
                           //fprintf(file,"\nKeyword \"Integer\" has found\n");
						   return INTEGER;
						 }
						 
New                      {
                           //fprintf(file,"\nKeyword \"New\" has found\n");
						   return NEW;
						 }
						 
Case                     {
                           //fprintf(file,"\nKeyword \"Case\" has found\n");
						   return CASE;
						 }
						 
Char                     {
                           //fprintf(file,"\nKeyword \"Char\" has found\n");
						   return CHAR;
						 }
						 
Const                    {
                           //fprintf(file,"\nKeyword \"Const\" has found\n");
						   return CONST;
						 }
						 
Select                   {
                           //fprintf(file,"\nKeyword \"Select\" has found\n");
						   return SELECT;
						 }
						 
(While)     {
                           //fprintf(file,"\nKeywords \"Do While\" has found\n");
						   return WHILE;
						 }
						 
(Until)     {
                          // fprintf(file,"\nKeywords \"Do Until\" has found\n");
						   return UNTIL;
						 }
						 
Module                   {
                           //fprintf(file,"\nKeyword \"Module\" has found\n");
						   return MODULE;
						 }
						 
Do                       {
                           //fprintf(file,"\nKeyword \"Do\" has found\n");
						   return DO;
						 }
Enum                     {
                          // fprintf(file,"\nKeyword \"Enum\" has found\n");
						   return ENUM;
						 }
						 
(End[[:space:]]Enum)     {
                          // fprintf(file,"\nKeywords \"End Enum\" has found\n");
						   return END_ENUM;
						 }
						 
(End[[:space:]]Module)   {
                           //fprintf(file,"\nKeywords \"End Module\" has found\n");
						   return END_MODULE;
						 }
						 
(End[[:space:]]Select)   {
                          // fprintf(file,"\nKeywords \"End Select\" has found\n");
						   return END_SELECT;
						 }
						 
(End[[:space:]]While)    {
                          // fprintf(file,"\nKeywords \"End While\" has found\n");
						   return END_WHILE;
						 }
						 
Loop                     {
                          // fprintf(file,"\nKeyword \"End While\" has found\n");
						   return LOOP;
						 }
						 
Step                     {
                         //  fprintf(file,"\nKeyword \"Step\" has found\n");
						   return STEP;
						 }
						 
(For[[:space:]]Each)     {
                         //  fprintf(file,"\nKeywords \"For Each\" has found\n");
						   return FOR_EACH;
						 }
						 
For                      {
                        //   fprintf(file,"\nKeyword \"For\" has found\n");
						   return FOR;
						 }
						 
To                       {
                       //    fprintf(file,"\nKeyword \"To\" has found\n");
						   return TO;
						 }
						 
Next                     {
                        //   fprintf(file,"\nKeyword \"Next\" has found\n");
						   return NEXT;
						 }
						 
In                       {
                          // fprintf(file,"\nKeyword \"In\" has found\n");
						   return IN;
						 }
						 
String                   {
                          // fprintf(file,"\nKeyword \"String\" has found\n");
						   return STRING_T;
						 }
						 
Mod                      {
                          // fprintf(file,"\nKeyword \"Mod\" has found\n");
						   return MOD;
						 }
						 
Console                  {
                          // fprintf(file,"\nKeyword \"Console\" has found\n");
						   return CONSOLE;
						 }
						 
Write                    {
                           //fprintf(file,"\nKeyword \"Write\" has found\n");
						   return WRITE;
						 }
						 
WriteLine                {
                          // fprintf(file,"\nKeyword \"WriteLine\" has found\n");
						   return WRITELINE;
						 }
						 
Read                     { 
                          // fprintf(file,"\nKeyword \"Read\" has found\n");
						   return READ;
						 }
						 
ReadLine                 {
                          // fprintf(file,"\nKeyword \"ReadLine\" has found\n");
						   return READLINE;
						 }
						 						 
System                   {
                          // fprintf(file,"\nKeyword \"System\" has found\n");
						   return SYSTEM;
						 }
						 
Exception                {
                          // fprintf(file,"\nKeyword \"Exception\" has found\n");
						   return EXCEPTION;
						 }

\=                       {
                          // fprintf(file,"\nOperator \"=\" has found\n");
						   return '=';
						 }
						 
\+                       {
                         //  fprintf(file,"\nOperator \"+\" has found\n");
						   return '+';
						 }
						 
\-                       {
                          // fprintf(file,"\nOperator \"-\" has found\n");
						   return '-';
						 }
						 
\*                       {
                         //  fprintf(file,"\nOperator \"*\" has found\n");
						   return '*';
						 }
						 
\\                       {
                       //    fprintf(file,"\nOperator \"\\\" has found\n");
						   return '\\';
						 }
						 
\/                       {
                         //  fprintf(file,"\nOperator \"/\" has found\n");
						   return '/';
						 }
						 
\^                       {
                          // fprintf(file,"\nOperator \"^\" has found\n");
						   return '^';
						 }
						 
\>                       {
                         //  fprintf(file,"\nOperator \">\" has found\n");
						   return '>';
						 }
						 
\<                       {
                         //  fprintf(file,"\nOperator \"<\" has found\n");
						   return '<';
						 }
						 
\>\=                     {
                         //  fprintf(file,"\nOperator \">=\" has found\n");
						   return MORE_OR_EQUAL;
						 }
						 
\<\=                     {
                        //   fprintf(file,"\nOperator \"<=\" has found\n");
						   return LESS_OR_EQUAL;
						 }
						 
\<\>                     {
                        //   fprintf(file,"\nOperator \"<>\" has found\n");
						   return NONEQUAL;
						 }

\(                       {
                         //  fprintf(file,"\nOperator \"(\" has found\n");
						   return '(';
						 }
						 
\)                       {
                         //  fprintf(file,"\nOperator \")\" has found\n");
						   return ')';
						 }
						 
\{                       {
                         //  fprintf(file,"\nOperator \"{\" has found\n");
						   return '{';
						 }
						 
\}                       {
                          // fprintf(file,"\nOperator \"}\" has found\n");
						   return '}';
						 }

\,                       {
                         //  fprintf(file,"\nOperator \",\" has found\n");
						   return ',';
						 }
						 
\.                       {
                         //  fprintf(file,"\nOperator \".\" has found\n");
						   return '.';
						 }
						 
\:						 {
                          // fprintf(file,"\nOperator \":\" has found\n");
						   return ':';
						 }

"\'"                     { BEGIN(COMMENT);                                                              }
<COMMENT>\n              { /*fprintf(file,"\nComment\n"); BEGIN(INITIAL);*/                                 }
<COMMENT>.*              {                                                                              }

\"                       {
                           strcpy(literal,"");
						   BEGIN(STRING);
						 }
						 
<STRING>[^\"\n]+         {
                           strcat(literal,yytext);
						 }
						 
<STRING>\n               {
                           //printf(file,"\nString has ended by \\n \"%s\"\n", literal);
						   BEGIN(INITIAL);
						 }
						 
<STRING>\"\"             {
                           strcat(literal,"\"");
						 }
						 
<STRING>[‡-ˇ¿-ﬂ]+        {
                          // fprintf(file, "\nIncorrect characters:");
						   //fprintf(file, " %d:%d\n", yylloc.first_line, yylloc.first_column);
						   getchar();
						   exit(1);
						 }
						 
<STRING>\"               {
                          // fprintf(file,"\nString literal \"%s\"",literal);
						   BEGIN(INITIAL);
						   yylval.s_const = (char*)malloc(strlen(literal)+1);
						   strcpy(yylval.s_const, literal);
						   return STRING_CONST;
						 }
						 
vbCrLf                   {
                           //fprintf(file,"\nSymbol \"\\n\" has found");
						   yylval.c_const = '\n';
						   return CHAR_CONST;
						 }
						 
vbTab                    {
                          // fprintf(file,"\nSymbol \"\\t\" has found");
						   yylval.c_const = '\t';
						   return CHAR_CONST;
						 }
						 
NullChar                 {
                          // fprintf(file,"\nSynbol \"\\0\" has found");
						   yylval.c_const = '\0';
						   return CHAR_CONST;
						 }

[a-zA-Z_][_a-zA-Z0-9]*   {
                          // fprintf(file,"\nID %s has found\n", yytext);
						   yylval.s_const = (char*)malloc(strlen(yytext)+1);
						   strcpy(yylval.s_const, yytext);
						   return ID;
						 }

{DIGIT}+                 {
                         //  fprintf(file,"\nNumber %d has found\n", atoi(yytext));
						   yylval.i_const = atoi(yytext);
						   return INT_CONST;
						 }
						 
\&H[0-9A-F]+             {
                           sscanf(yytext, "%h", &num);
						  // fprintf(file,"\nNumber %d has found\n", num);
						   yylval.i_const = num;
						   return INT_CONST;
						 }
						 
\&O[0-7]+                {
                           sscanf(yytext, "%o", &num);
						  // fprintf(file,"\nNumber %d has found\n", num);
						   yylval.i_const = num;
						   return INT_CONST;
						 }


%%


//int main (int argc, char* argv[])
//{
//	file = fopen("result.txt", "wt");
//	yyin = fopen(argv[1], "r");
//	
//	//yylex();	// «¿Ã≈Õ≈Õ≈ÕŒ
//	
//	yyparse();
//	
//	print_tree();		// ¬˚‚Ó‰ ‰ÂÂ‚‡
//	
//	fclose(file);
//	getchar();
//	return 0;
//}

// œ≈–≈Õ≈—≈ÕŒ ¬ ¡»«ŒÕŒ¬— »… ”-‘¿…À!!!

//int main(int argc, char* argv[])
//{
//  file = fopen("result.txt", "wt");
//  yyin = fopen(argv[1], "r");
//  yylex();
//  //yyparse();
//  fclose(file);
//  getchar();
//  return 0;
//}