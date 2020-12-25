#include <stdio.h>
#include <stdlib.h>
//括号匹配
int match_kuohao(char c[])
{
    int i = 0;
    seq_stack S;
    init(&S);
    while(c[i] != '#'){
        switch(c[i])
        {
            case '{':
            case '[':
            case '(':push(&S,c[i]);
                break;
            case '}':if(!empty(S) && readTopStack(S) == '{'){
                    pop(&S);
                    break;
                }else
                return 0;
            case ']':if(!empty(S) && readTopStack(S) == '['){
                    pop(&S);
                    break;
                }else
                return 0;
            case ')':if(!empty(S) && readTopStack(S) == '('){
                    pop(&S);
                    break;
                }else
                return 0;
        }
        i++;
    }
    return (empty(S));
}
