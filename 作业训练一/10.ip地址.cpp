#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int ten_to_two(int a){
    int sum = 0;
    while(a!=0){
        if(a%2==1) sum++;
        a/=2;
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    char tmp;
    for(int i=0;i<n;i++){
        int result = 0;
        int a1,a2,a3,a4;
        cin>>a1>>tmp>>a2>>tmp>>a3>>tmp>>a4;
        result = ten_to_two(a1)+ ten_to_two(a2) + ten_to_two(a3)+ ten_to_two(a4);
        cout<<result<<endl;
    }
    return 0;
}
