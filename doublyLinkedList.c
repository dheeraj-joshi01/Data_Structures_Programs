//program for doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *lptr, *rptr;
};



struct Node* Insert(struct Node* L, struct Node* R, int new_data)
{
	struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
	
	new_node->data = new_data;
	
	
	
	if(L == NULL)
	{
		new_node->rptr = NULL;
		new_node->lptr = NULL;
		
		L = new_node;
		R = L;
				
		return L;
	}
	
	
	if(L == R)
	{
		new_node->lptr = L;
		L->rptr = L;
		new_node->rptr = NULL;
		R = new_node;
		
		printf("%d\n", L->data);
		printf("%d\n", R->data);
		return L;
	}
	
	else
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		
		temp = L;
		
		while(temp->rptr != NULL)
		{
			temp = temp->rptr;
		}
		
		new_node->lptr = temp;
		temp->rptr = new_node;
		new_node->rptr = NULL;
		
		printf("%d ", L->data);	
		return L;
	}
		
}


struct Node* delete(struct Node* L, struct Node* R, int val)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	if(L == NULL)
	{
		printf("Underflow\n");
		return NULL;
	}
	
	if(L->rptr == NULL && L->data == val)
	{
		L = NULL;
		R = L;
		
		return L;
	}
	
	if(L->data == val)
	{
		L = L->rptr;
		L->lptr = NULL;
		
		return L;
		
	}
	
	if(R->data == val)
	{
		R = R->lptr;
		R->rptr = NULL;
		
		return L;
	}
	
	else
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		
		temp = L;
		
		while(temp->data != val)
		{
			temp = temp->rptr;
		}
		
		if(temp->data != val)
		{
			printf("Not found\n");
			return L;
		}
		
		(temp->lptr)->rptr = temp->rptr;
		(temp->rptr)->lptr = temp->lptr;
		
		temp->lptr = NULL;
		temp->rptr = temp->lptr;
		
		free(temp);
				
		return L;
		
	}
}




int display(struct Node *lp, struct Node *rp)
{
	
	if(lp == NULL)
	{	
		printf("Empty\n");
		return 0;
	}
	
	printf("%d ", lp->data);
	
	while(lp->rptr != NULL)
 	{
 		lp = lp->rptr;
		printf("%d ", lp->data);
			
  	}
		
	return 0;
}


void main()
{
	int value, new, opt, flag = 1;
	int del_num;
	
	struct Node *L = NULL;
	struct Node *R ;// = (struct Node*) malloc(sizeof(struct Node));	
	struct Node* lp = (struct Node*) malloc(sizeof(struct Node));
	struct Node* rp = (struct Node*) malloc(sizeof(struct Node));
	
	
	
	while(flag != 0)
	{
		
		printf("Select the operation you want to perform :\n1. Insert\n2. Delete\n3. display\n4. exit\n");
		
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
			printf("Enter the value you want to insert : ");
			scanf("%d", &new);
			L = Insert(L, R, new);
			break;

			case 2:
			printf("Enter the number you want to delete : ");
			scanf("%d", &del_num);
			L = delete(L, R, del_num);
			break;

			case 3:
			lp = L;
			rp = R;
			printf("List : ");
			display(lp, rp);
			printf("\n");
			break;

			case 4:
			flag = 0;
			break;
		}
	
		

	}


}
