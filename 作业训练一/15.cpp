#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
struct inf{
    int goal = 0;
    int fs = 0;
};

bool cmp(const pair<string,inf> &s1,pair<const string,inf> &s2){
    return s1.second.fs>s2.second.fs;
}
int main(){
    int n;
    cin>>n;
    string name1,name2;
    int goal1,goal2;
    string tmp;
    for(int i=0;i<n;i++){
        map<string,inf> teams;
        cin>>name1>>goal1>>tmp>>goal2>>name2;
        if(goal1>goal2){
            teams[name1].fs+=3;
            teams[name1].goal+=goal1-goal2;
        }
        if(goal1<goal2){
            teams[name2].fs+=3;
            teams[name2].goal+=goal2-goal1;
        }
        else{
            teams[name1].fs+=1;
            teams[name2].fs+=1;
        }
        vector<pair<string,inf>> result(teams.begin(),teams.end());
        sort(result.begin(),result.end(),cmp);
        if(result[0].second.fs==result[1].second.fs){
            if(result[0].second.goal>result[1].second.goal){
                cout<<result[0].first<<" "<<result[1].first<<endl;
            }
            else{
                cout<<result[1].first<<" "<<result[1].first<<endl;
            }
        }
        else{
            cout<<result[0].first<<" "<<result[1].first<<endl;
        }
    }return 0;
}
