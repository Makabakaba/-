/*
Floyd算法： 
#include<stdio.h>
#include<stdlib.h>
#define max 1000000000
 
int d[1000][1000],path[1000][1000];
int main()
{
    int i,j,k,m,n;
    int x,y,z;
    scanf("%d%d",&n,&m);
     
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            d[i][j]=max;
            path[i][j]=j;
    }
     
    for(i=1;i<=m;i++) {
            scanf("%d%d%d",&x,&y,&z);
            d[x][y]=z;
            d[y][x]=z;
    }
     
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++) {
                if(d[i][k]+d[k][j]<d[i][j]) {
                    d[i][j]=d[i][k]+d[k][j];
                    path[i][j]=path[i][k];
                }
            }
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
          if (i!=j) printf("%d->%d:%d\n",i,j,d[i][j]);
    int f, en;
    scanf("%d%d",&f,&en);
    while (f!=en) {
        printf("%d->",f);
        f=path[f][en];
    }
    printf("%d\n",en);
    return 0;
}
*/

//Dijkstra算法： 
#include <climits>
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

const int INFI = 1000;
int v, m; 

void dijkstra(int v0, int map[][100], int parent[], int distance[], int visited[]){
    for (int i = 1; i <= v; i++){
        visited[i] = 0;
        if (map[v0][i] < INFI)
            parent[i] = v0;
        else
            parent[i] = -1;
        distance[i] = map[v0][i];
    }
    visited[v0] = 1; 
    parent[v0] = -1; 

    //dijkstra算法核心
    for (int k = 1; k < v; k++){
        int minDis = INFI; 
        int minIndex = -1;
        for (int i = 1; i <= v; i++) {
            if (!visited[i] && distance[i] < minDis){
                minIndex = i;
                minDis = distance[i];
            }
        }
        if (minIndex == -1)
            break;
        visited[minIndex] = 1; 

        for (int i = 1; i <= v; i++) {
            if (!visited[i] && distance[i] > minDis + map[minIndex][i]) {
                distance[i] = minDis + map[minIndex][i];
                parent[i] = minIndex;
            }
        }
    }
}

void print_shortestPath(int start, int end, int parent[]){
    stack<int> s;
    if(parent[end]==-1){
        printf("不能从源点%d到底终点%d", start, end);
        return;
    }
        
    s.push(end);
    int k = parent[end];
    while(k!=-1){
        s.push(k);
        k = parent[k];
    }

    printf("从点 %d 到点 %d 的最短路径为:", start, end);
    while(!s.empty()){
        int top = s.top();
        cout << top << "->";
        s.pop();
    }
    cout << endl;
}

int main()
{
    cin >> v >> m;

    int map[100][100];
    int visited[v + 1];
    int parent[v + 1];
    int distance[v + 1];

    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
        {
            map[i][j] = INFI;
            map[i][i] = 0;
        }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
    }

    dijkstra(1, map, parent, distance, visited);

    cout << "distance数组（源点到各个点的最短路径长度）：";
    for (int i = 1; i <= v; i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;

    cout << "parent数组（最短路上终点的前一个节点）：";
    for (int i = 1; i <= v; ++i)
    {
        cout << parent[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= v;i++){
        print_shortestPath(1, i, parent);
    }
        
    system("pause");
    return 0;
}
