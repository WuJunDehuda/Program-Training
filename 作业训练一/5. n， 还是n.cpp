#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <sstream>
int getsize(int n){
    int count = 1;
    while(n>=10){
        n/=10;
        count++;
    }
    return count;
}
using namespace std;
int main() {
    int n,m;
    cin>>m>>n;
    char tmp1[getsize(n)];
    sprintf(tmp1,"%d",n);
    stringstream ss2;
    ss2<<tmp1;
    string pre = ss2.str();
    for(int i=1;i<=m;i++){
        char tmp2[getsize(i)];
        sprintf(tmp2,"%d",i);
        stringstream ss;
        ss<<tmp2;
        string result = ss.str();
        if(i%n==0||result.find(pre)!=string::npos){
            cout<<i<<" ";
        }
    }
    return 0;
}z
