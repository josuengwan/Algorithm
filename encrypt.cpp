//
// encrypt.cpp
// ENCRYPT by algospot.com
// 
// Created by SeungWan Jo on 2015. 3.02.
// 
#include <stdio.h>
#include <string.h>
int T; // �׽�Ʈ ���̽� ����
char originalString[101]; // 100���� ���ڿ�
char cryptString[101];
// HelloWorld = 10 / 5
void initString(){

}
int main(){
    int index;
    int strIndex,maxLength;
    int midIndex;
    scanf("%d",&T);
    for(index=0;index<T;index++){
        int cryptIndex=0;
        memset(originalString,0, strlen(originalString));
        memset(cryptString,0, strlen(cryptString));
        
        scanf("%s",originalString);
        maxLength = (int)strlen(originalString);
        if(maxLength%2==0)
            midIndex = maxLength/2;
        else
            midIndex = maxLength/2+1;
        
        for (strIndex=0; strIndex<maxLength; strIndex++) {
            if(strIndex%2==0){
                cryptString[cryptIndex++]=originalString[strIndex];
            }else{
                // 1
                cryptString[midIndex+cryptIndex-1] = originalString[strIndex];
            }
        }
        printf("%s\n",cryptString);
    }
    
    return 0;
}