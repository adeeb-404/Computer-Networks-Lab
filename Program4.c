// Question: Simulate the working of distance vector routing algorithm using Bellman-Ford’s algorithm.
#include<stdio.h>
#include<limits.h>

#define INF 1e7

int main(){
	
	int n ;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	int graph[n][n];
	
	//initializing the graph with infinity
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) graph[i][j]=0;
			else graph[i][j]=INF;
		}
	}
	
	int e;
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	
	printf("Enter the edges in format of u v w \n");
	for(int i=0;i<e;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		graph[u][v]= w;
		graph[v][u]=w;
	}
	
	//Algo start
	int src;
	printf("Enter the source node\n");
	scanf("%d",&src);
	
	int distance[n];
	for(int i=0;i<n;i++)
		distance[i]=INF;
	distance[src]=0;
	
	for(int k=0;k<n-1;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(graph[i][j]!=INF && distance[i]+graph[i][j]<distance[j])
					distance[j]= distance[i]+ graph[i][j];
			}
		}
	}
    
    
    for(int i=0;i<n;i++)
    	printf("%d ",distance[i]);
    
    
    return 0;
}

//Enter number of nodes
//5
//Enter the number of edges
//7
//Enter the edges in format of u v w
//0 1 3
//0 2 3
//0 3 4
//2 1 10
//2 3 6
//3 1 3
//1 4 2
//Enter the source node
//2
//3 6 0 6 8
//----------