%{
      #include<stdio.h>
      #include<string.h>
      struct quad
      {
        char op[5];
        char arg1[10];
        char arg2[10];
        char result[10];
      }
      QUAD[30];
      int i=0,j;
%}


%union
{
    char exp[10];
}


%token <exp> VAR
%type <exp> S E T F

%%
S: E       { 
              printf("\n List of Quadruples are: \n");
              for(j=0;j&lt;i;j++)
                printf("%s\t%s\t%s\t%s\n",QUAD[j].op,QUAD[j].arg1,Q
                UAD[j].arg2,QUAD[j].result);
            };
E: E'+'T    {
                strcpy(QUAD[i].op,"+");
                strcpy(QUAD[i].arg1,$1);
                strcpy(QUAD[i].arg2,$3);
                strcpy(QUAD[i].result,$$);
                i++;
            }
| T { }
;
T: T'*'F    {
                strcpy(QUAD[i].op,"*");
                strcpy(QUAD[i].arg1,$1);
                strcpy(QUAD[i].arg2,$3);
                strcpy(QUAD[i].result,$$);
            }
| F { }
;
F: VAR {}
;


%%
main()
{
      yyparse();
}
yyerror(char *s)
{
      printf(&quot;%s&quot;,s);
}
