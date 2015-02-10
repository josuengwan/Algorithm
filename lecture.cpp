//
// lecture.cpp
// lecture by algospot.com
// 
// Created by SeungWan Jo on 2015. 2.10.
// 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string sort_this(string& s){
	vector<string> mainstr;
	for(int i=0; i<s.size();i+=2)
		mainstr.push_back(s.substr(i,2));       //문자열 2개씩 분리하기

	for(int i = 0; i< mainstr.size();++i){     //sort
		for(int j= i;j<mainstr.size();++j){
			if(mainstr[i]>mainstr[j])
				swap(mainstr[i],mainstr[j]);
		}
	}

	string result;
	for(int i=0;i<mainstr.size();++i){       //합치기
		result +=mainstr[i];
	}
	return result;
}

int main(){
	int T;
	cin>>T;
	string s;
	for(int i=0;i<T;++i){
	cin>>s;
	cout<<sort_this(s)<<endl;
	}
	
	return 0;
}