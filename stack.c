//RECOGNIZE STRING USING STACK

#include<stdio.h>
#include<string.h>
#include "stackGen.h" 


int main()
{
	int top = 0;
	char str[] = "aaabbb";
	int n = strlen(str);
	char a[(n+1)/2];

	int i=0;
	for(int i = 0; i<n; i++)
	{
		while(str[i] != 'b')
		{
			PUSH(a, str[i], &top, n);
			i++;
		}

		POP(a, &top);
		
	}			
		

	
	if(top == 0)
			{
				printf("The string is valid\n");
			}
	
	else
	{
		printf("The string is not valid\n");
	}



	return 0;
}
