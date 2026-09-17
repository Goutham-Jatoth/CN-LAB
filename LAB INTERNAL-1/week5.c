#include <stdio.h>

#define INF 9999
#define MAX 10

int main()
{
    int n,c[MAX][MAX],v[MAX]={0};
    int i,j,e=1,a,b,min,total=0;

    printf("=== Computer Network Simulation ===\n");
    printf("Broadcast Tree Construction using Spanning Tree Algorithm\n\n");

    printf("Enter number of hosts (nodes) in the subnet: ");
    scanf("%d",&n);

    printf("\nEnter the cost adjacency matrix (Enter 9999 if no direct link):\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&c[i][j]);

    v[0]=1;

    printf("\nSimulating Broadcast Tree Formation...\n");
    printf("----------------------------------------\n");

    while(e<n)
    {
        min=INF;

        for(i=0;i<n;i++)
            if(v[i])
                for(j=0;j<n;j++)
                    if(!v[j] && c[i][j]<min)
                        min=c[i][j],a=i,b=j;

        printf("Step %d: Connect Host %d --> Host %d | Link Cost = %d\n",
               e,a+1,b+1,min);

        total+=min;
        v[b]=1;
        e++;
    }

    printf("----------------------------------------\n");
    printf("Total Cost of Broadcast Tree = %d\n",total);
    printf("Simulation Complete: Broadcast Tree Formed Successfully.\n");

    return 0;
}