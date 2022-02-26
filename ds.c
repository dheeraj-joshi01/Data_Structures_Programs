#include<stdio.h>

//Deciding whether sparse matrix is better or linear representation	

int main()
{
	int n, m, nz=0;
	int maj;
	
	printf("Enter the total rows\ntotal columns\n");
	scanf("%d%d",&n,&m);

	int sparse[n][m];

	printf("Enter the elements of the matrix\n");
	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			scanf("%d", &sparse[i][j]);
			
			if(sparse[i][j] != 0)
			{
				nz++;
			}
		}
	}

	int linear[3][nz];
	int k=0;
	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(sparse[i][j] != 0)
			{
				while(k<nz)
				{
					linear[0][k] = i;
					linear[1][k] = j;
					linear[2][k] = sparse[i][j];
					k++;
				}
			}
		}
	}

	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<nz;j++)
		{
			printf("%d ",linear[i][j]);
		}
		
		printf("\n");
	}
	

	return 0;

}














/*
	//Deciding whether sparse matrix is better or linear representation	

int main()
{
	int n, m, e;
	int maj;
	
	printf("Enter the total rows\ntotal columns\nno. of non zero elements:\n");
	scanf("%d %d %d",&n,&m,&e);

	if(e*3 > n*m)
	{
		printf("Sparse matrix is better\n");
	}
	
	else
	{
		printf("Linear representation is better\n");
	}
	

	return 0;

}*/









/*
	//Calculation of element address in 2-D array	


int main()
{
	int base, n, m, i, j, c,add;
	int maj;
	
	printf("Enter the base address,\ntotal rows\ntotal columns\nelement row index\nelement column index\nsize of each element:\n");
	scanf("%d %d %d %d %d %d",&base,&n,&m,&i,&j,&c);
	
	printf("Enter 1 for row major or,\n0 for column major\n");
	scanf("%d",&maj);

	if(maj == 0)
	{
		add = base + ((j-1)*n + (i-1))*c;
		printf("The address of element is: %d\n",add);

	}
	
	else//if(maj == 'r')
	{
		add = base + ((i-1)*m + (j-1))*c;
		printf("The address of element is: %d\n",add);

	}
	
	
	
	return 0;
}*/



/*
	//Calculation of element address in 1-D array

int main()
{
	int base,i,c,add;
	
	printf("Enter the base address, element location and size of each element:\n");
	scanf("%d%d%d",&base,&i,&c);

	add = base + (i-1)*c;
	printf("The address of %d element is: %d\n",i,add);
	
	return 0;
}*/
