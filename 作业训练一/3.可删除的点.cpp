#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int x,y;
    int num1 = 0,num2 = 0;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(x<0) num1++;
        if(x>0) num2++;
    }
    if(num1<=1||num2<=1){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}
