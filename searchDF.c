#include<stdio.h>
#include<stdlib.h>
#include "Item.h"
#include "STACK.h"
#define M 7
int graph[M][M];
int visited[M];
int goal;

int searchDF(int start, int goal){
    STACKinit(M);
    STACKpush(start);
    int node, next;
    while(STACKempty() == 0){
        node = STACKpop();
        if(visited[node] == 1) continue;
        printf("%d ", node);
        visited[node] = 1;
        if(visited[goal] == 1){
            return 1;
        }
        for(next = M-1; 0 <= next; next--){
            if(graph[node][next] == 1 && visited[next] == 0){
        STACKpush(next);
            }
        }
    }
    return 0;
}

void main(int argc,char* argv[]){
int i, j;
goal = atoi(argv[1]);
    for(i = 0; i < M; i++)
        for(j = 0; j < M; j++) graph[i][j] = 0;
    while(scanf("%d %d", &i, &j) == 2) graph[i][j] = 1;
    if(searchDF(0, goal))
    printf("\nThe goal %d is found\n", goal);
    else
    printf("\nNot Found\n");
}
