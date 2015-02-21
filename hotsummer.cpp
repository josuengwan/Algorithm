//
// hotsummer.cpp
// HOTSUMMER by algospot.com
// 
// Created by SeungWan Jo on 2015. 2.21.
// 
#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	int a[9];
	int g;
	int sum=0;
	memset(a,0,sizeof(a));
	for(int i=0;i<T;i++){
		cin>>g;
		for(int j=0;j<9;j++){
			cin>>a[j];
			if(0<=a[j]&&a[j]<=1000)
				sum+=a[j];
			else
				cin>>a[j];
		}
		if(sum<=g)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

		sum=0;
	}
}