int PUSH(char a[],int *t,int n)			//PUSH FUNCTION
{
	char x;
	
	printf("Enter the no.\n");
	scanf(" %c",&x);
	if(*t>=n)
	{
		printf("Stack Overflow\n");
		return 0;
	}

	else
	{
		*t=*t+1;
		a[*t] = x;
		printf("top = %d\nValue Entered %c\n",*t, a[*t]);
		return 1;
	}

}

int POP(char a[],int *t)					//POP FUNCTION
{
	if(*t==0)
	{
		printf("Stack Underflow\n");
		return 0;
	}

	else
	{
		printf("Deleted %c\n", a[*t]);
		*t=*t-1;
		printf("top = %d\n", *t);
		
		return 1;
	}

}

int PEEP(char a[],int *t)				//PEEP FUNCTION
{
int i;
	
	printf("Enter the index of the no.\n");
	scanf("%d",&i);

	if(*t-i+1 <= 0)
	{
		printf("Stack Underflow\n");
		return 0;
	}

	else
	{
		printf("The value at %d position is %c\n", i, a[*t-i+1]);
		
		return 1;
	}

}

int CHANGE(char a[],int *t)					//CHANGE FUNCTION
{
	int i;
	char new;
	
	printf("Enter the index of the no.\n");
	scanf("%d",&i);

	printf("Enter the value you want to replace\n");
	scanf(" %c",&new);

	if(*t-i+1 <= 0)
	{
		printf("Stack Underflow\n");
		return 0;
	}

	else
	{
		a[*t-i+1] = new;
		printf("Value at %d position replaced\n",i);
		
		return 1;
	}

}
