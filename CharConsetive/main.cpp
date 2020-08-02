//
//  main.cpp
//  CharConsetive
//
//  Created by jinglin sun on 2020/7/26.
//  Copyright © 2020 jinglin sun. All rights reserved.
//

#include <iostream>
using namespace std;

// 从目标字符串中，找出出现的连续重复字符个数最多的字符 及其 对应的位置
void FindStr(char* str)
{
    if(str == NULL)
        return;
    
    char* pStr = str;
    char* qStr = str+1;
    char* index = str;
    char* maxIndex = index;
    int num = 1;
    int maxNum = num;
    
    while(*pStr != '\0')
    {
        if(*qStr != *pStr){
            num = 1;
            pStr++;
        } else {
            while(*qStr == *pStr && *pStr !='\0' && *qStr !='\0')
            {
                num++;
                index = pStr;
                qStr++;
                pStr++;
            }
            
            if(num>2)
                index = qStr - num;
            
            
            if(num > maxNum){
                maxNum = num;
                maxIndex = index;
            }
        }
        
        qStr = pStr+1;
    }
    
    cout << "Result: max = " << maxNum << "\r\n";
    for(int i=0;i<maxNum;++i)
        cout << *maxIndex++;
    cout << endl;
}

// 从目标字母字符串中，找出出现的连续升序字符最多的字符 及其 对应的位置
void FindStr2(char* str)
{
    if(str == NULL)
        return;
    
    char* pStr = str;
    char* qStr = str+1;
    char* index = str;
    char* maxIndex = index;
    int num = 1;
    int maxNum = num;
    
    while(*pStr != '\0')
    {
        if(*qStr - 1 != *pStr) {
            num = 1;
            pStr++;
        } else {
            while(*qStr -1 == *pStr && *pStr !='\0' && *qStr !='\0')
            {
                num++;
                index = pStr;
                qStr++;
                pStr++;
            }
            
            if(num>2)
                index = qStr - num;
            
            
            if(num > maxNum){
                maxNum = num;
                maxIndex = index;
            }
        }
        
        qStr = pStr+1;
    }
    
    cout << "Result: max = " << maxNum << "\r\n";
    for(int i=0;i<maxNum;++i)
        cout << *maxIndex++;
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char* str = "aaaa2xxxx11111111111xb";
    FindStr(str);
    
    char* str2 = "abcdefx23123zabcdefghsfasf";
    FindStr2(str2);
    return 0;
}
