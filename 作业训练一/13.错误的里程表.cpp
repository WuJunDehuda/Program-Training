#include<iostream>
#include<string.h>
#include<sstream>
#include<cmath>
#include <algorithm>
using namespace std;
int main(){
    string s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int sum = 0;
        for(int i=0;i<s.size();i++){
            if((s[i]-'0')>=4&&(s[i]-'0')<=7) s[i]-=1;
            if((s[i]-'0')>7) s[i]-=2;
        }
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            sum+=(s[i]-'0')*pow(8,i);
        }
        cout<<sum<<endl;
    }
}

