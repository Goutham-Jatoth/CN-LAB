#include <stdio.h>

#define INF 9999
#define MAX 10

void dijkstra(int g[MAX][MAX], int n, int s)
{
    int d[MAX], v[MAX]={0}, i,j,min,u;

    for(i=0;i<n;i++)
        d[i]=g[s][i]?g[s][i]:INF;

    d[s]=0;
    v[s]=1;

    for(i=1;i<n-1;i++)
    {
        min=INF;
        for(j=0;j<n;j++)
            if(!v[j] && d[j]<min)
                min=d[j],u=j;

        v[u]=1;

        for(j=0;j<n;j++)
            if(!v[j] && min+(g[u][j]?g[u][j]:INF)<d[j])
                d[j]=min+(g[u][j]?g[u][j]:INF);
    }

    for(i=0;i<n;i++)
        printf("\nDistance from node %d to %d: %d",s,i,d[i]);
}

int main()
{
    int g[MAX][MAX]={
        {0,4,0,0,0,8,0},
        {4,0,8,0,0,11,0},
        {0,8,0,7,0,4,0},
        {0,0,7,0,9,14,0},
        {0,0,0,9,0,10,2},
        {0,0,4,14,10,0,2},
        {0,0,0,0,2,2,0}
    };

    dijkstra(g,7,1);
    return 0;
}