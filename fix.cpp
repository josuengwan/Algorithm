//
// fix.cpp
// fix by algospot.com
// 
// Created by SeungWan Jo on 2015. 2.9.
// 

#include<iostream>
using namespace std;

int main(){
	int T;
	int N;
	int cont=0;
	cin >> T;
	int *t = new int[T];

	for(int i=0;i<T;i++){
		cin >> N;
		int *n = new int[N];
		if(10<=N){
			if(N<=12){
				for(int j=0;j<N;j++){
					cin>>n[j];
					if((j+1)==n[j]){
						cont ++;
						
					}
				}
			}
		}	
		t[i]= cont;
		cont=0;
	}
	for(int i=0;i<T;i++){
		cout<<t[i]<<endl;
	}
	return 0;
}