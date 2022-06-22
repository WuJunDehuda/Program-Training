#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct player{
    int score = 0;
    int win[101] = {0};
};
struct pplayer{
    string name;
    int score = 0;
    int win[101]={0};
};
bool cmp1(const pplayer &player1,const pplayer &player2){
    if(player1.score!=player2.score) return player1.score>player2.score;
    else {
        for(int i=0;i<101;i++){
            if(player1.win[i]!=player2.win[i]) return player1.win[i]>player2.win[i];
        }
    }
}
bool cmp2(const pplayer &player1,const pplayer &player2){
    if(player1.win[0]!=player2.win[0]) return player1.win[0]>player2.win[0];
    else if(player1.score!=player2.score) return player1.score>player2.score;
    else{
        for(int i=1;i<101;i++){
            if(player1.win[i]!=player2.win[i]) return player1.win[i]>player2.win[i];
        }
    }
}
int main(){
    int score[10] = {25,18,15,12,10,8,6,4,2,1};
    int t;
    cin>>t;
    map<string,player> res;
    vector<pplayer> fin_res;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string name;
            cin>>name;
            res[name].score+=score[i];
            res[name].win[i]++;
        }
        for(auto it:res){
            pplayer tmp;
            tmp.name = it.first;
            tmp.score = it.second.score;
            for(int j=0;j<10;j++){
                tmp.win[j] = it.second.win[j];
            }
            fin_res.push_back(tmp);
        }
    }
    sort(fin_res.begin(), fin_res.end(),cmp1);
    cout<<fin_res[0].name<<endl;
    sort(fin_res.begin(), fin_res.end(), cmp2);
    cout<<fin_res[0].name<<endl;
    return 0;
}
