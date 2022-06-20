#include<iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s;
    for(int i=-1;i<n;i++){  //我也不了解为什么是-1
        getline(cin,s);
        s+=" ";
        string::iterator start = s.begin();
        for(string::iterator i = s.begin();i!=s.end();i++){
            if(*i==' '){
                reverse(start,i);   //左闭右开
                start = i+1;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
