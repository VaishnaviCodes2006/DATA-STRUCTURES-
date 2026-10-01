#include <stdio.h>
#include <stdlib.h>

void infixtoprefix(STACK *s, char infixc[20])
{
    int i, j = 0;
    char symbol, temp, prefix[20];
    for(i= strlen(infix)-1; i>=0; i--)
    {
        symbol = infix[i];
        if(isalnum(symbol))
            prefix[j++] = symbol;
        else{
            switch (symbol)
            {
                case : ')'
                push(s, symbol);
                break;
                case '('; temp= pop(s);
                while(temp!=')')
                {
                    prefix[j++]= temp;
                    temp = pop(s);
                }
                break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '^': if (s->top==1) || s->data[s->top]>=
                                push
            }
        }
    }
}
