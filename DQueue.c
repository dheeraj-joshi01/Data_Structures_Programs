#include<stdio.h>


int DQ_InsertRear(char q[], int *f, int *r, int size, char element)			//Insert to Rear
{
	if(*r >= size)
	{
		printf("Stack Overflow\n");
		
		return 0;
	}
	
	if(*f == 0)
	{
		*f = 1;
	}

	
	*r = *r + 1;
	q[*r] = element;
	
	
	return 1;
	

}

int DQ_InsertFront(char q[], int *f, int *r, int size, char element)			//Insert to Front
{
	if(*f == 0)
	{
		printf("Queue is Empty\n");
		
		return 0;
	}
	
	if(*f == 1)
	{
		printf("Queue Overflow\n");
		
		return 0;
	}

	
	*f = *f - 1;
	q[*f] = element;
	
	
	return 1;
	

}

char DQ_DeleteFront(char q[],int *f, int *r)					//Delete from Front
{
	if(*f == 0)
	{
		printf("Stack Underflow\n");
		
		return 0;
	}

	char y = q[*f];

	if(*f == *r)
	{
		*f = 0, *r = 0;
	}
	
	else
	{
		*f += 1;
	}

	return y;

}


char DQ_DeleteRear(char q[],int *f, int *r)					//Delete from Rear
{
	if(*r == 0)
	{
		printf("Queue Underflow\n");
		
		return 0;
	}

	char y = q[*r];

	if(*f == *r)
	{
		*f = 0, *r = 0;
	}
	
	else
	{
		*r -= 1;
	}

	return y;

}



void main()
{
	char dequeue[5], value;
	int f = 0, r = 0, opt, flag = 1;

	while(flag != 0)
	{
		printf("Select the operation you want to perform :\n1. Insert to front\n2. Insert to rear\n3. Delete from front\n4. Delete from rear\n5. exit\n");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
			printf("Enter the value you want to insert to front : ");
			scanf(" %c", &value);
			DQ_InsertFront(dequeue, &f, &r, 5, value);
			break;

			case 2:
			printf("Enter the value you want to insert to rear : ");
			scanf(" %c", &value);
			DQ_InsertRear(dequeue, &f, &r, 5, value);
			break;

			case 3:
			printf("Deleted from front : %c\n", DQ_DeleteFront(dequeue, &f, &r));
			break;

			case 4:
			printf("Deleted from rear: %c\n", DQ_DeleteRear(dequeue, &f, &r));
			break;

			case 5:
			flag = 0;
			break;
		}

	}

}
