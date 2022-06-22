#include<iostream>
#include <algorithm>
using namespace std;
int dat2num(string s){
    if(s=="monday") return 0;
    if(s=="tuesday") return 1;
    if(s=="wednesday") return 2;
    if(s=="thursday") return 3;
    if(s=="friday") return 4;
    if(s=="saturday") return 5;
    if(s=="sunday")  return 6;
}
int main(){
    int T,L,R;
    string S,E;
    int s,e;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>S>>E;
        s = dat2num(S);
        e = dat2num(E);
        cin>>L>>R;
        if(e-s>0&&(e-s+1)<L){
            cout<<"impossible";
        }
        else if(e-s<0&&(e-s+8)<L){
            cout<<"impossible";
        }
        if(R-L>7) cout<<"many"<<endl;
        else {
            int tmp = L/7;
            int s1 = (s+L-1)%7;
            int s2 = (s+R-1)%7;
            if(e>=min(s1,s2)&&e<=max(s1,s2)){
                if(s<e) cout<<tmp*7+e-s+1<<endl;
                else cout<<tmp*7+7+s-e+1<<endl;
            }
        }
    }
}

