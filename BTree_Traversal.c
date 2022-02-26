#include<stdio.h>
#include<stdlib.h>

struct Node{
	char data;
	struct Node *rptr;
	struct Node *lptr;
};



void Preorder(struct Node *T)
{
	if(T == NULL)
	{
		printf("Empty Tree\n");
		return;
	}

	else
	{
		printf("%c ", T->data);
	}

	if(T->lptr != NULL)
	{
		Preorder(T->lptr);
	}

	if(T->rptr != NULL)
	{
		Preorder(T->rptr);
	}


}

void Inorder(struct Node *T)
{
	if(T == NULL)
	{
		printf("Empty Tree\n");
		return;
	}


	if(T->lptr != NULL)
	{
		Preorder(T->lptr);
	}

	printf("%c ", T->data);
	
	if(T->rptr != NULL)
	{
		Preorder(T->rptr);
	}


}

void Postorder(struct Node *T)
{
	if(T == NULL)
	{
		printf("Empty Tree\n");
		return;
	}


	if(T->lptr != NULL)
	{
		Preorder(T->lptr);
	}

	if(T->rptr != NULL)
	{
		Preorder(T->rptr);
	}
	
	
	printf("%c ", T->data);


}


int main()
{
	struct Node* a = (struct Node*)malloc(sizeof(struct Node));
	struct Node* b = (struct Node*)malloc(sizeof(struct Node));
	struct Node* c = (struct Node*)malloc(sizeof(struct Node));
	struct Node* d = (struct Node*)malloc(sizeof(struct Node));
	struct Node* e = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f = (struct Node*)malloc(sizeof(struct Node));
	struct Node* g = (struct Node*)malloc(sizeof(struct Node));

	a->data = 'A';
	a->rptr = d;
	a->lptr = b;

	b->data = 'B';
	b->rptr = NULL;
	b->lptr = c;

	c->data = 'C';
	c->rptr = NULL;
	c->lptr = NULL;

	d->data = 'D';
	d->rptr = g;
	d->lptr = e;

	e->data = 'E';
	e->rptr = f;
	e->lptr = NULL;

	f->data = 'F';
	f->rptr = NULL;
	f->lptr = NULL;

	g->data = 'G';
	g->rptr = NULL;
	g->lptr = NULL;

	printf("Preorder :\t");
	Preorder(a);

	printf("\nInorder :\t");
	Inorder(a);

	printf("\nPostorder :\t");
	Postorder(a);


	return 0;
}

