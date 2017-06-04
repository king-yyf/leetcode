//
//  main.cpp
//  expMatch
//
//  Created by Yang Yunfei on 2017/5/29.
//  Copyright © 2017年 Yang Yunfei. All rights reserved.
//
#include<cstdio>
#include<iostream>
using namespace std;
bool isMatch(const char *s, const char * p){
    if(*p == '\0') return *s == '\0';
    if(*(p + 1) != '*'){
        if(*p == *s || (*p == '.' && *s != '\0'))
            return isMatch(s + 1, p + 1);
        else
            return false;
    }else{
        while(*p == *s || (*p == '.' && *s != '\0')){
            if(isMatch(s, p + 2))
                return true;
            s++;
        }
        return isMatch(s, p + 2);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    bool ok;
    ok = isMatch("aabb","a.*");
    cout<<ok<<endl;
    return 0;
}
