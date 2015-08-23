//
// snail.cpp
// 
// 
// Created by SeungWan Jo on 2015. 8.23.
// 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

using namespace std;

int main(){
	int t;
	int j=-1,i=0;
	int d =1;
	int num =0;
	cin>>t;
	int l=t;
	int **result = new int*[t];

	for(int m=0;m<t;m++)
		result[m] = new int[t];		//동적할당

	for(int p =0;p<t;p++){			//가로채우기
		for(int g=0;g<l;g++){
			j+=d;
			result[i][j]=num;
			num++;
		}
		l--;

		for(int g2=0;g2<l;g2++){	//세로채우기
			i+=d;
			result[i][j]=num;
			num++;
		}
		d=-d;					//방향전환
	}

	for(int i=0;i<t;i++){
		cout<<endl;
		for(int j=0;j<t;j++)
			printf("%d \t",result[i][j]);	//출력
	}
	cout<<endl;
	for(int k=0;k<t;k++)
		delete []result[k];
	delete []result;						//메모리반환
	
	return 0;
}	