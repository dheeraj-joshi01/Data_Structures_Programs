int PUSH(char stack[], char element, int *top, int size)			//PUSH FUNCTION
{
	if(*top >= size)
	{
		//printf("Stack Overflow\n");
		
		return 0;
	}

	else
	{
		*top = *top + 1;
		stack[*top] = element;
		
		return 1;
	}

}

char POP(char stack[],int *top)					//POP FUNCTION
{
	if(*top == 0)
	{
		//printf("Stack Underflow\n");
		
		return 0;
	}

	else
	{
		*top = *top - 1;
				
		return stack[*top + 1];
	}

}

char PEEP(char stack[], int *top, int index)				//PEEP FUNCTION
{

	if(*top - index + 1  <= 0)
	{
		//printf("Stack Underflow\n");
		
		return 0;
	}

	else
	{
		return stack[*top - index + 1];
	}

}

int CHANGE(char stack[], char new, int *top, int index)					//CHANGE FUNCTION
{
	
	if(*top - index + 1 <= 0)
	{
		printf("Stack Underflow\n");
		
		return 0;
	}

	else
	{
		stack[*top - index + 1] = new;
				
		return 1;
	}

}
