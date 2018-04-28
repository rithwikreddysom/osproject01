#include<stdio.h>
#include<stdlib.h>
int processes,resources;
int inst[5],available_instances[3];
int alloc_matrix[5][3],max_matrix[5][3],need_matrix[5][3],work[3],finish[5];
void disp()
{
	printf("============================================BANKER's ALGORITHM TO FIND SAFE STATE=====================================\n");
	int i,j;
	printf("Number of process are %d \n",processes);
	printf("Number of resources are %d \n",resources);
    	printf("\n========================================================================================================================\n");	
	for(i=0;i<resources;i++)
	{
		printf("\nTotal Instances for\t");
		printf("%c = %d ",i+65,inst[i]);
	}
		printf("\n========================================================================================================================\n");
	for(i=0;i<resources;i++)
	{
		printf("\nAvailable Instances for\t");
		printf("%c = %d ",i+65,available_instances[i]);
	}
	printf("\n========================================================================================================================\n");
	printf("                                            allocated Resource matrix table");
	printf("\n========================================================================================================================\n");
	for(i=0;i<processes;i++)
	{	
		printf("\nP%d\t",i);
		for(j=0;j<resources;j++)
		{
			printf("%c = %d\t",j+65,alloc_matrix[i][j]);		
		}
	}
	printf("\n========================================================================================================================\n");
	printf("                                            maximum matrix ");
	printf("\n========================================================================================================================\n");
	for(i=0;i<processes;i++)
	{	
		printf("\nP%d\t",i);
		for(j=0;j<resources;j++)
		{
			printf("%c->%d\t",j+65,max_matrix[i][j]);		
		}
	}
	printf("\n========================================================================================================================\n");
	printf("                                            need matrix");
	printf("\n========================================================================================================================\n");
	for(i=0;i<processes;i++)
	{	
	
		printf("\nP%d\t",i);
		for(j=0;j<resources;j++)
		{
			printf("%c=%d\t\t",j+65,need_matrix[i][j]);		
		}
	}	
}
void find()
{	
	printf("\n");
	int i,j,count;
	for(i=0;i<processes;i++)
	{
		count=0;
		if(finish[i]==0)
		{
			for(j=0;j<resources;j++)
			{
				if(need_matrix[i][j]<=work[j])
				count++;
			}
			if(count==resources)
			{
				printf(" P%d \t\t",i);
				finish[i]=1;
				for(j=0;j<resources;j++)
				{	
					work[j]=work[j]+alloc_matrix[i][j];
				}
				i=-1;
			}
		}
	}
	count=0;
	for(i=0;i<processes;i++)
	{
		if(finish[i]==1)
		{
			count++;
		}
	}
	if(count==processes)
	{
		printf("\nSafe State\n");
	}
	else
	printf("\nUnsafe state\n");
}
int main()
{	
int i,j;processes=5;resources=3;
inst[0]=10;inst[1]=5;inst[2]=7;
available_instances[0]=3;available_instances[1]=3;available_instances[2]=2;
alloc_matrix[0][0]=0;alloc_matrix[0][1]=1;alloc_matrix[0][2]=0;
max_matrix[0][0]=7;max_matrix[0][1]=5;max_matrix[0][2]=3;
alloc_matrix[1][0]=2;alloc_matrix[1][1]=0;alloc_matrix[1][2]=0;
max_matrix[1][0]=3;max_matrix[1][1]=2;max_matrix[1][2]=2;
alloc_matrix[2][0]=3;alloc_matrix[2][1]=0;alloc_matrix[2][2]=2;
max_matrix[2][0]=9;max_matrix[2][1]=0;max_matrix[2][2]=2;
alloc_matrix[3][0]=2;alloc_matrix[3][1]=1;alloc_matrix[3][2]=1;
max_matrix[3][0]=2;max_matrix[3][1]=2;max_matrix[3][2]=2;
alloc_matrix[4][0]=0;alloc_matrix[4][1]=0;alloc_matrix[4][2]=2;
max_matrix[4][0]=4;max_matrix[4][1]=3;max_matrix[4][2]=3;
for(i=0;i<processes;i++)
	{	
	finish[i]=0;
	for(j=0;j<resources;j++)
		{
		work[j]=available_instances[j];
		if(max_matrix[i][j]>inst[j])
				{
					printf("Please enter valid resources");
					exit(0);
				}
		need_matrix[i][j]=max_matrix[i][j]-alloc_matrix[i][j];
		}
	}
		disp();
		find();
	
    
}


