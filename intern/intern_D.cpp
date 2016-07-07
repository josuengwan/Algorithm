//
//  intern_D.cpp
//  D번
//
//  Created by 조승완 on 2016. 4. 16..
//  Copyright © 2016년 Seungwan. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
#define N 100
#define INF 9999

int a[N+1][N+1];
int visit[N];
int dist[N];
int edges[N+1];
int start, gold;
int edge,vertex;

void input(int n){
    
    int inputedge[n][n];
    string mudnum;
    int temp[n][n];
    
    for(int i=0;i<vertex;i++)
        for(int j=0;j<vertex;j++)
            a[i][j]=INF;
    
    for(int i=0;i<n;i++){
        cin>>mudnum;
        for(int j=0;j<n;j++){
            char tem=mudnum.c_str()[j];
            temp[i][j]=atoi(&tem);
        }
    }
    
    //입력값 90도 회전
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            inputedge[j][n-1-i]=temp[i][j];
        }
    }
    
    int j=0;
    for(int i=0;i<vertex;i++){
        edges[i]=inputedge[j][i];
        if(i+1%n==0)
            ++j;
    }
    edges[100]=INF;
    
    for (int i =1;i <=vertex; i++)
        dist[i] = INF;
}

int Upsarching(int cR,int index,int n){
    
    int outindex = index+n;
    
    if(cR==n)
        return -1;
    return outindex;
}
int Downsarching(int cR,int index,int n){
    int outindex = index-n;
    
    if(cR==0)
        return -1;
    return outindex;
}
int Rigthsarching(int cL,int index,int n){
    
    int outindex=index+1;
    
    if(cL==n)
        return -1;
    return outindex;
}
int Leftsarching(int cL,int index,int n){
    
    int outindex=index-1;
    
    if(cL==0)
        return -1;
    return outindex;
}

void makeGraph(int n){
    int eu,ed,er,el;
    int row;
    int col;
    for(int i=0;i<vertex;i++){
        row=i/n;
        col=i%n;
        eu=Upsarching(row,i,n);
        ed=Downsarching(row,i,n);
        er=Rigthsarching(col,i,n);
        el=Leftsarching(col,i,n);
        for(int j=0;j<vertex;j++){
            if(j==eu)
                a[i][j]=edges[j];
            if(j==ed)
                a[i][j]=edges[j];
            if(j==er)
                a[i][j]=edges[j];
            if(j==el)
                a[i][j]=edges[j];
        }
    }
}

int choose(int dist[], int n, int visit[])
{
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for(i=0;i<n;i++)
        if( dist[i]< min && ! visit[i] ){
            min = dist[i];
            minpos=i;
        }
    return minpos;
}

void dijkstra()
{
    int v = start;
    
    for(int i=0; i<vertex; i++)
    {
        dist[i] = a[start][i];
        visit[i] = 0;
    }
    visit[start] = 1;
    dist[start] = 0;
    for(int i=0; i<vertex; i++){
        v = choose(dist, vertex, visit);
        visit[v] = 1;
        for(int w=0;w<vertex; w++)
            if(!visit[w])
                if( dist[v]+a[v][w] < dist[w] ) {
                    dist[w] = dist[v]+a[v][w];
                }
    }
}



int main(int argc, const char * argv[]) {
    
    int n;
    cin>>n;
    if(n>10&&n<1) return 0;
    start=0;
    gold=n*n-1;
    vertex = n*n;
    edge = (n-1)*(2*n);
    
    input(n);
    makeGraph(n);
    dijkstra();
    if(dist[gold]>100){
        cout<<"100"<<endl;
    }else{
        cout<<dist[gold]<<endl;
    }
    return 0;
}
