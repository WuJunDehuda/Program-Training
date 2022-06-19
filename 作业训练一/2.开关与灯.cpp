#include<iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    char open[n][m];
    int light[m];
    bool flag= false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>open[i][j];
        }
    }
    for(int i=0;i<n;i++){
            for(int l=0;l<m;l++){
                light[l] = 0;
            }
            for(int j=0;j<n;j++){
                if(j==i) continue;
                for(int k=0;k<m;k++){
                    if(open[j][k]=='1'){
                        light[k] = 1;
                    }
                }
            }
        flag = true;
        for(int j=0;j<m;j++){
            if(light[j]==0) flag = false;
        }
        if(flag== true){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
