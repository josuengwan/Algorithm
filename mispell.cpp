//
// mispell.cpp
// MISPELL by algospot.com
// 
// Created by SeungWan Jo on 2015. 2.14.
// 
#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	int c;
	int len;
	char s[81];
	memset(s,0,sizeof(s));
	int tem_j;
	if(1<=T && T<=1000){
		for(int i=0;i<T;i++){
			scanf("%d %s",&c,s);
			len=strlen(s);
			for(int j=0;j<len;j++){
				if(j==c-1){
					tem_j=j;
					s[j]=0;           //delete spell
				}
			}
			for(int k=tem_j;k<len;k++){
				s[k]=s[k+1];              //null delete
			}
			cout<<i+1<<" "<<s<<endl;
		}
	}
	else cin>>T;
	return 0;
}