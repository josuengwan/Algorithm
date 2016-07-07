//
//  intern_A.cpp
//  A번
//
//  Created by 조승완 on 2016. 4. 16..
//  Copyright © 2016년 Seungwan. All rights reserved.
//


#include <iostream>
#include <stdlib.h>


using namespace std;

void check_Alpbet_output(string str,int len);
struct alpbetstr {
    int index=0;
    int charnum=0;
};

int main(int argc, const char * argv[]) {
    string str = "";
    getline(cin,str);
    int limitlen = 1000000;
    int len = str.length();

    if(len == limitlen){
        return 0;
    }else{
        check_Alpbet_output(str,len);
    }
    return 0;
}

void check_Alpbet_output(string str,int len){
    char cstr[len];
    strcpy(cstr,str.c_str());
    alpbetstr str_struct[26];
    alpbetstr strtemp;
    int alpbetSortResult[26]={0};

    //checknum of alpbet
    for (int i =0; i<len; i++)
        ++alpbetSortResult[(int)cstr[i]-65];

    for(int a=0; a<26; a++){
        str_struct[a].index = a;
        str_struct[a].charnum=alpbetSortResult[a];
    }

    //sorting
    for(int k=0;k<25;k++){
        for(int x=0;x<26-k;x++){
            if(str_struct[x].charnum>str_struct[x+1].charnum){
                strtemp=str_struct[x];
                str_struct[x]=str_struct[x+1];
                str_struct[x+1]=strtemp;
                }
        }
    }

    //print
    for(int k=0;k<26;k++){
        if(str_struct[k].charnum!=0){
            for(int j=0;j<str_struct[k].charnum;j++){
                char t = str_struct[k].index+65;
                cout<<t;
            }
        }
    }
    cout<<endl;
}
