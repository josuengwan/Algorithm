//
//  intern_E.cpp
//  E번
//
//  Created by 조승완 on 2016. 4. 16..
//  Copyright © 2016년 Seungwan. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct answerStr {
    char ch;
    int check;
};

int checkString(string str,int len);
int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin,str);
    if(str.length()>1000) return 0;
    int len = str.length();
    
    cout<<checkString(str,len)<<endl;
    return 0;
}

int checkString(string str,int len){
    int count =0;
    answerStr answer[12];
    char ans[] = "JENNIFERSOFT";
    int checknum = 0;
    int machingnum =0;
    
    for(int i=0;i<12;i++){
        answer[i].ch=ans[i];
        answer[i].check =0;
    }
    if(len>12){
        for(int i=0;i<12;i++){
            if(str[i]==answer[i].ch){
                machingnum++;
            }
        }
        
        for(int i=0;i<len;i++){
            for(int j=0;j<12;j++){
                if(str[i]==answer[j].ch && answer[j].check==0){
                    answer[j].check=1;
                    str.erase(i,i);
                    len-=1;
                    break;
                }
            }
        }
        count+=len;         //삭제하고 교채한 갯수
        if(machingnum==0)
            count+=1;           //JENNIFERSOFT로 재배열하는 경우
    }else if(len<=12){
        for(int i=0;i<len;i++){
            for(int j=0;j<12;j++){
                if(str[i]==answer[j].ch && answer[j].check==0){
                    answer[j].check=1;
                    checknum++;
                    break;
                }
            }
        }
        count+=(12-checknum);       //교채하고 추가한 갯수
        count+=1;                   //JENNIFERSOFT로 재배열하는 경우
    }
    
    return count;
}




