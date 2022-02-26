//INFIX to PREFIX USING STACK


#include<stdio.h>
#include<string.h>
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
	char rev[30];
		
	int i = strlen(infx) - 1, j=0;
	
	while(i>0)
    {
		while(infx[i] != '\0')
		{
			if(infx[i] == ')')
            		rev[j] = '(';
        
			else if(infx[i] == '(')
				rev[j] = ')';
	
			else
				rev[j] = infx[i];

			j++;
			i--;
		}
		i--;
	}
		
    printf("\n");
    e = rev;
   char post[30];
	i=0;
	
    while(*e != '\0')
    {
        if(isalnum(*e))
		{
            post[i] = *e;
		i++;
		}
        
	else if(*e == '(')
            push(*e);
        
	else if(*e == ')')
        {
            while((x = pop()) != '(')
			{
                post[i] = x;
			i++;
		}
        }
        
	else
        {
            while(preced(stack[top]) >= preced(*e))
           {     post[i] = pop();
		i++;}

            push(*e);
        }
	e++;
	}

	while(top != -1)
	{
	post[i] = pop();
		i++;
	}


	char pre[30];
		
	i = strlen(post) - 1, j=0;
	
	while(i>0)
    {
		while(post[i] != '\0')
		{
			pre[j] = post[i];

			j++;
			i--;
		}
		i--;
	}

	printf("%s\n",pre);

	return 0;
}

