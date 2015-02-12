//
// encrypt.cpp
// ENCRYPT by algospot.com
// 
// Created by SeungWan Jo on 2015. 2.12.
// 
#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	char s[101];
	char r[60];
	memset(r,0,sizeof(r));       //r√ ±‚»≠
	int k=0;
	if(1<=T && T<=10){
		for(int i=0;i<T;i++){
			scanf("%s",s);
			int half;
			if(strlen(s)%2==0) half=(strlen(s)/2);
			if(strlen(s)%2!=0) half=(strlen(s)/2)+1;
		
			for(int j=0;j<strlen(s);j++){
				if(j==0) r[j]=s[j];
				if(j%2==0){
					r[j-k]=s[j];
				}
				if(j%2!=0){
					r[half+k]=s[j];
					k++;
				}
			}
			cout<<r<<endl;
		}
	}
	else cin>>T;
	return 0;
}