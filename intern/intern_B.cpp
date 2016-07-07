//
//  intern_B.cpp
//  B번
//
//  Created by 조승완 on 2016. 4. 16..
//  Copyright © 2016년 Seungwan. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    string line;
    int count=0;
    int s1,s2;
    cin>>n;
    if(n<1 || n>1000) return 0;
    
    char** seat = new char*[n];
    for(int i =0;i<n;i++){
        seat[i]=new char[n];
        memset(seat[i], 0, sizeof(char)*n);
    }
    
    for(int i=0;i<n;i++){
        cin>>line;
        for(int j=0;j<n;j++){
            seat[i][j]=line.c_str()[j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            s1=seat[i][j];
            s2=seat[i][j+1];
            if(s1=='.' && s1==s2)
                count++;
        }
    }
    
    cout<<count<<endl;
    return 0;
}



