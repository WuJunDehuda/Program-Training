#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct team{
    int score = 0;
    int goal = 0;
    int win_goal = 0;
};
struct ssteam{
    string name;
    int score;
    int goal;
    int win_goal;
};
bool cmp(ssteam s1,ssteam s2){
    if(s1.score!=s2.score){
        return s1.score>s2.score;
    }
    else if(s1.win_goal!=s2.win_goal){
        return s1.win_goal>s2.win_goal;
    }
    else return s1.goal>s2.goal;
}
int main(){
    int n;
    cin>>n;
    string a;
    for(int i=0;i<n;i++){
        cin>>a;
    }
    string name1,name2;
    int goal1,goal2;
    string tmp1,tmp2;
    char tmp;
    vector<ssteam> result;
    vector<string> final_result;
    map<string,team> teams;
    for(int i=0;i<n*(n-1)/2;i++){
        cin>>tmp1>>goal1>>tmp>>goal2;
        int pos1;
        for(int i=0;i<tmp1.size();i++){
            if(tmp1[i]=='-'){
                pos1 = i;
            }
        }
        name1 = tmp1.substr(0,pos1);
        name2 = tmp1.substr(pos1+1);
        if(goal1>goal2){
            teams[name1].score+=3;
            teams[name1].win_goal+=goal1-goal2;
            teams[name1].goal+=goal1;
            teams[name2].win_goal+=goal2-goal1;
            teams[name2].goal+=goal2;
        }
        else if(goal1<goal2){
            teams[name2].score+=3;
            teams[name1].win_goal+=goal1-goal2;
            teams[name1].goal+=goal1;
            teams[name2].win_goal+=goal2-goal1;
            teams[name2].goal+=goal2;
        }
        else{
            teams[name1].score+=1;
            teams[name1].goal+=goal1;
            teams[name2].score+=1;
            teams[name2].goal+=goal2;
        }
    }
    for(map<string,team>::iterator i = teams.begin();i!=teams.end();i++){
        ssteam tmp;
        tmp.name = i->first;
        tmp.win_goal = i->second.win_goal;
        tmp.goal = i->second.goal;
        tmp.score = i->second.score;
        result.push_back(tmp);
    }
    sort(result.begin(),result.end(),cmp);
    for(int i=0;i<n/2;i++){
        final_result.push_back(result[i].name);
    }
    sort(final_result.begin(), final_result.end());
    for(int i=0;i<n/2;i++){
        cout<<final_result[i]<<endl;
    }
    return 0;
}
