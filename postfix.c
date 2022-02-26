//INFIX to POSTFIX USING STACK


#include<stdio.h>
#include<ctype.h>                        
                                     
char stack[30];
int top = -1;

void push(char x)
{
	top += 1;
    stack[top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int preced(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
	if (x =='^')
 	 	return 3;

    return 0;
}

int main()
{
    char infx[30];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",infx);
    printf("\n");
    e = infx;
   
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        
	else if(*e == '(')
            push(*e);
        
	else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        
	else
        {
            while(preced(stack[top]) >= preced(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
   
    while(top != -1)
    {
        printf("%c ",pop());
    }

	return 0;
}

