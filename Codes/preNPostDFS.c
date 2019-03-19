#include<stdio.h>

void DFS(int,int pp[]);
int G[10][10],visited[10],n;    //n is no of vertices and graph is sorted in array G[10][10]
int counter = 1;

void show(int pp[])
{
    int i;
    printf("\nCounter: %d \n",counter);
    for(i=0;i<2*n;i+=2)
        printf("%d  and %d \n",pp[i],pp[i+1]);
}
void main()
{
    int i,j;
    printf("Enter number of vertices:");

	scanf("%d",&n);

    //read the adjecency matrix
	printf("\nEnter adjecency matrix of the graph:\n");

	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);


    int pp[2*n];

    for(i=0;i<2*n;i++)
        pp[i] = 0;
    //visited is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;

    int first = 0;
    pp[first] = counter++;
    //printf("Before DFS: ");
    //show(pp);
    DFS(first,pp);
    pp[first+1] = counter++;

    for(i=0;i<n;i++)
    {
        if(!visited[i]){
            pp[2*i] = counter++;
            DFS(i,pp);
            pp[2*i+1] = counter++;

        }
    }

    j=0;
    printf("\n");

    for(i=0;i<2*n;i=i+2){

        printf("a[%d], Pre = %d Post = %d\n",j,pp[i],pp[i+1]);
        j++;
    }
}

void DFS(int i, int pp[])
{
    int j;
	printf("\nCovered node: %d",i);
	show(pp);
    visited[i]=1;

	for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
        {

            pp[j*2] = counter++;

            printf("Pre: %d \n",j);
            show(pp);
             DFS(j,pp);


    printf("Post %d \n",(j*2)+1);
    show(pp);
    pp[(j*2)+1]= counter++;
        }
        show(pp);

}
