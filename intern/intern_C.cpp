//
//  intern_C.cpp
//  C번
//
//  Created by 조승완 on 2016. 4. 16..
//  Copyright © 2016년 Seungwan. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>

#define BIG_INT     9999
#define MAX_SIZE    121
#define Find       2
#define NotFind      1

using namespace std;

struct graphPoint {
    int index;
    int x;
    int y;
};

void ShortestPath(int v, float graph[][MAX_SIZE], float* distance, int* visit,int* result_pointpath,  int pointnum);
int ChoosePoint(float* distance, int* visit, int pointnum);
float Distences(graphPoint p1, graphPoint p2);

int main(int argc, const char * argv[]) {
    float graph[MAX_SIZE][MAX_SIZE]={BIG_INT};
    graphPoint point[121];
    float distance[MAX_SIZE];
    int visit[MAX_SIZE];
    int result_pointpath[MAX_SIZE]={BIG_INT};
    
    //init
    point[0].index =0;
    point[0].x =0;
    point[0].y =0;
    
    int n;
    cin>>n;
    if(n>10 || n<1) return 0;
    
    int totalpointnum = n+2;
    for(int i =1;i<n+1;i++){
        point[i].index=i;
        scanf("%d %d", &point[i].x,&point[i].y);
        if(point[i].x<1 || point[i].x>10) return 0;
        if(point[i].y<1 || point[i].y>10) return 0;
    }
    
    point[120].x=10;
    point[120].y=10;
    point[120].index=120;
    
    //----------makeGraph
    for(int i=0;i<totalpointnum;i++){
        for(int j=0;j<totalpointnum;j++){
            if(i==point[j].index){
                graph[i][point[j].index]=BIG_INT;
            }else{
                graph[i][point[j].index]=Distences(point[i], point[j]);
            }
            
        }
    }
    //------makeGraphend
    
    ShortestPath(0, graph, distance, visit, result_pointpath, totalpointnum);
    
    //----------printResult
    cout<<"(0,0)";
    for(int i=1;i<totalpointnum-1;i++){
        printf(" -> (%d,%d)",point[result_pointpath[i]].x,point[result_pointpath[i]].y);
    }
    cout<<" -> (10,10)"<<endl;
    //----------printResult end
    return 0;
}

int ChoosePoint(float* distance, int* visit, int pointnum){
    int i, minpos;
    
    float min = INT_MAX;
    minpos = -1;
    for(i=0;i<pointnum;i++)
        if( distance[i]< min && visit[i]==NotFind){
            min = distance[i];
            minpos=i;
        }
    return minpos;
}

float Distences(graphPoint p1, graphPoint p2){
    
    float d;
    d = sqrt((pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2)));
    return d;
}

void ShortestPath(int start, float graph[][MAX_SIZE], float* distance, int* visit,int* result_poinpath,  int pointnum){
    int choosep;
    for(int i=0;i<pointnum;i++){
        distance[i]= graph[start][i];
        if ( distance[i] > 0 && distance[i] < BIG_INT) result_poinpath[i] = start;
        visit[i]=NotFind;
    }
    visit[start]=Find;
    
    for(int i=0;i<pointnum;i++){
        choosep=ChoosePoint(distance, visit, pointnum);
        result_poinpath[i]=choosep;
        visit[choosep]=Find;
        for(int j=0;j<pointnum;j++){
            if(visit[j]==Find) continue;
            distance[j]= graph[choosep][j];
        }
    }
}



