#include <iostream>
using namespace std;
int couut(string str){
    int count = 0;
    for(int i=str.size()-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(str[i]<str[j]){
                count++;
            }
        }
    }
    return count;
}
int main(){
    int n,m;
    cin>>n>>m;
    string str[m];
    int count[m];
    for(int i=0;i<m;i++){
        cin>>str[i];
        count[i] = couut(str[i]);
    }
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            if(count[i]>count[j]){
                swap(count[i], count[j]);
                swap(str[i],str[j]);
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<str[i]<<endl;
    }
    return 0;
}
