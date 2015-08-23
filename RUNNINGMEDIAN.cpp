//
// RUNNINGMEDIAN.cpp
// RUNNINGMEDIAN by algospot.com
// 
// Created by SeungWan Jo on 2015. 8.19.
// 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

using namespace std;

void swap(int*v,int i,int j){
	int temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

void sort(int v[],int n){
	int i,last;
	if(n<=1)return;
	swap(v,0,rand()%n);
	last = 0;
	for(i=0;i<n;i++)
		if(v[i]<v[0])
			swap(v,++last,i);
	swap(v,0,last);
	sort(v,last);
	sort(v+last+1,n-last-1);
}
int main(){
	int T;
	int C;
	int a,b;
	cin>>T;
	if(1<=T&&T<=20){
		int *result = new int[T];
		for(int i=0;i<T;i++){
			scanf("%d %d %d",&C,&a,&b);
			if(1<=C&&C<=200000&&0<=a&&0<=b&&a<=10000&&b<=10000){
				int*ptr =new int[C];
				int*out =new int[C];
				int output=0;
				int temp;
				ptr[0]=1983;
				out[0]=1983;
				for(int j=1;j<C;j++){
					ptr[j]=(ptr[j-1]*a+b)%20090711;
					int k =j;
					sort(ptr,j);

					if(j+1%2==0){
						if(ptr[j/2]<ptr[j/2+1])
							out[j]=ptr[j/2];
						else
							out[j]=ptr[j/2+1];
					}else
						out[j]=ptr[j/2];
				}
				for(int t=0;t<C;t++){
					output+=out[t];
				}
				output=output%20090711;
				result[i]=output;
				delete ptr;
				delete out;
			}
		}
		for(int k=0;k<T;k++)
			cout<<result[k]<<endl;
		delete result;
	}
	return 0;
}