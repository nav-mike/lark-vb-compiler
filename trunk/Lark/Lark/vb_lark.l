%option noyywrap
%option never-interactive

%{
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  
  FILE* file;
  char literal[100];
  int num = 0;
%}

DIGIT  [0-9]
LETTER [A-Za-z]

%x COMMENT
%x STRING

%%

[à-ÿÀ-ß]+                { fprintf(file, "\nIncorrect characters\n"); getchar(); exit(1);               }
Dim                      { fprintf(file,"\nKeyword \"Dim\" has found\n");                               }
As                       { fprintf(file,"\nKeyword \"As\" has found\n");                                }
If                       { fprintf(file,"\nKeyword \"If\" has found\n");                                }
Then                     { fprintf(file,"\nKeyword \"Then\" has found\n");                              }
ElseIf                   { fprintf(file,"\nKeyword \"ElseIf\" has found\n");                            }
Else                     { fprintf(file,"\nKeyword \"Else\" has found\n");                              }
(End[[:space:]]If)       { fprintf(file,"\nKeywords \"End If\" has found\n");                           }
Function                 { fprintf(file,"\nKeyword \"Function\" has found\n");                          }
ByVal                    { fprintf(file,"\nKeyword \"ByVal\" has found\n");                             }
Return                   { fprintf(file,"\nKeyword \"Return\" has found\n");                            }
(End[[:space:]]Function) { fprintf(file,"\nKeywords \"End Function\" has found\n");                     }
Sub                      { fprintf(file,"\nKeyword \"Sub\" has found\n");                               }
(End[[:space:]]Sub)      { fprintf(file,"\nKeywords \"End Sub\" has found\n");                          }
Try                      { fprintf(file,"\nKeywords \"Try\" has found\n");                              }
Catch                    { fprintf(file,"\nKeywords \"Catch\" has found\n");                            }
(End[[:space:]]Try)      { fprintf(file,"\nKeywords \"End Try\" has found\n");                          }
Throw                    { fprintf(file,"\nKeywords \"Throw\" has found\n");                            }
And                      { fprintf(file,"\nKeyword \"And\" has found\n");                               }
Boolean                  { fprintf(file,"\nKeyword \"Boolean\" has found\n");                           }
Integer                  { fprintf(file,"\nKeyword \"Integer\" has found\n");                           }
New                      { fprintf(file,"\nKeyword \"New\" has found\n");                               }
ByRef                    { fprintf(file,"\nKeyword \"ByRef\" has found\n");                             }
Call                     { fprintf(file,"\nKeyword \"Call\" has found\n");                              }
Case                     { fprintf(file,"\nKeyword \"Case\" has found\n");                              }
Char                     { fprintf(file,"\nKeyword \"Char\" has found\n");                              }
Const                    { fprintf(file,"\nKeyword \"Const\" has found\n");                             }
Select                   { fprintf(file,"\nKeyword \"Select\" has found\n");                            }
(Do[[:space:]]While)     { fprintf(file,"\nKeywords \"Do While\" has found\n");                         }
(Do[[:space:]]Until)     { fprintf(file,"\nKeywords \"Do Until\" has found\n");                         }
Module                   { fprintf(file,"\nKeyword \"Module\" has found\n");                            }
Do                       { fprintf(file,"\nKeyword \"Do\" has found\n");                                }
Enum                     { fprintf(file,"\nKeyword \"Enum\" has found\n");                              }
(End[[:space:]]Enum)     { fprintf(file,"\nKeywords \"End Enum\" has found\n");                         }
(End[[:space:]]Module)   { fprintf(file,"\nKeywords \"End Module\" has found\n");                       }
(End[[:space:]]Select)   { fprintf(file,"\nKeywords \"End Select\" has found\n");                       }
(End[[:space:]]While)    { fprintf(file,"\nKeywords \"End While\" has found\n");                        }
Loop                     { fprintf(file,"\nKeyword \"End While\" has found\n");                         }
(For[[:space:]]Each)     { fprintf(file,"\nKeywords \"For Each\" has found\n");                         }
For                      { fprintf(file,"\nKeyword \"For\" has found\n");                               }
To                       { fprintf(file,"\nKeyword \"To\" has found\n");                                }
Next                     { fprintf(file,"\nKeyword \"Next\" has found\n");                              }
In                       { fprintf(file,"\nKeyword \"In\" has found\n");                                }
String                   { fprintf(file,"\nKeyword \"String\" has found\n");                            }
Mod                      { fprintf(file,"\nKeyword \"Mod\" has found\n");                               }
ParamArray               { fprintf(file,"\nKeyword \"ParamArray\" has found\n");                        }
Console                  { fprintf(file,"\nKeyword \"Console\" has found\n");                           }
Write                    { fprintf(file,"\nKeyword \"Write\" has found\n");                             }
WriteLine                { fprintf(file,"\nKeyword \"WriteLine\" has found\n");                         }
Read                     { fprintf(file,"\nKeyword \"Read\" has found\n");                              }
ReadLine                 { fprintf(file,"\nKeyword \"ReadLine\" has found\n");                          }
ReadKey                  { fprintf(file,"\nKeyword \"ReadKey\" has found\n");                           }
System                   { fprintf(file,"\nKeyword \"System\" has found\n");                            }
Exception                { fprintf(file,"\nKeyword \"Exception\" has found\n");                         }

\=                       { fprintf(file,"\nOperator \"=\" has found\n");                                }
\+                       { fprintf(file,"\nOperator \"+\" has found\n");                                }
\-                       { fprintf(file,"\nOperator \"-\" has found\n");                                }
\*                       { fprintf(file,"\nOperator \"*\" has found\n");                                }
\\                       { fprintf(file,"\nOperator \"\\\" has found\n");                               }
\/                       { fprintf(file,"\nOperator \"/\" has found\n");                                }
\^                       { fprintf(file,"\nOperator \"^\" has found\n");                                }
\+\=                     { fprintf(file,"\nOperator \"+=\" has found\n");                               }
\-\=                     { fprintf(file,"\nOperator \"-=\" has found\n");                               }
\*\=                     { fprintf(file,"\nOperator \"*=\" has found\n");                               }
\\\=                     { fprintf(file,"\nOperator \"\\=\" has found\n");                              }
\/\=                     { fprintf(file,"\nOperator \"/=\" has found\n");                               }
\>                       { fprintf(file,"\nOperator \">\" has found\n");                                }
\<                       { fprintf(file,"\nOperator \"<\" has found\n");                                }
\>\=                     { fprintf(file,"\nOperator \">=\" has found\n");                               }
\<\=                     { fprintf(file,"\nOperator \"<=\" has found\n");                               }

\(                       { fprintf(file,"\nOperator \"(\" has found\n");                                }
\)                       { fprintf(file,"\nOperator \")\" has found\n");                                }
\{                       { fprintf(file,"\nOperator \"{\" has found\n");                                }
\}                       { fprintf(file,"\nOperator \"}\" has found\n");                                }

\,                       { fprintf(file,"\nOperator \",\" has found\n");                                }
\.                       { fprintf(file,"\nOperator \".\" has found\n");                                }

"\'"                     { BEGIN(COMMENT);                                                              }
<COMMENT>\n              { fprintf(file,"\nComment\n"); BEGIN(INITIAL);                                 }
<COMMENT>.*              {                                                                              }

\"                       { strcpy(literal,""); BEGIN(STRING);                                           }
<STRING>[^\"\n]+         { strcat(literal,yytext);                                                      }
<STRING>\n               { fprintf(file,"\nString has ended by \\n \"%s\"\n", literal); BEGIN(INITIAL); }
<STRING>\"\"             { strcat(literal,"\"");                                                        }
<STRING>[à-ÿÀ-ß]+        { fprintf(file, "\nIncorrect characters\n"); getchar(); exit(1);               }
<STRING>\"               { fprintf(file,"\nString literal \"%s\"",literal); BEGIN(INITIAL);             }
vbCrLf                   { fprintf(file,"\nSymbol \"\\n\" has found");                                  }
vbTab                    { fprintf(file,"\nSymbol \"\\t\" has found");                                  }
NullChar                 { fprintf(file,"\nSynbol \"\\0\" has found");                                  }

[a-zA-Z_][_a-zA-Z0-9]*   { fprintf(file,"\nID %s has found\n", yytext);                                 }

{DIGIT}+                 { fprintf(file,"\nNumber %d has found\n", atoi(yytext));                       }
\&H[0-9A-F]+             { sscanf(yytext, "%h", &num); fprintf(file,"\nNumber %d has found\n", num);    }
\&O[0-7]+                { sscanf(yytext, "%o", &num); fprintf(file,"\nNumber %d has found\n", num);    }


%%
int main(int argc, char* argv[])
{
  file = fopen("result.txt", "wt");
  yyin = fopen(argv[1], "r");
  yylex();
  fclose(file);
  getchar();
  return 0;
}