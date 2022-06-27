#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
struct person{
    string name;
    int num = 0;
    set<string> phone;
};
void cmp(string tmp,set<string> &phone){
    bool flag = true;
    string tmp3 = tmp;
    reverse(tmp3.begin(), tmp3.end());
    for(auto it:phone){
        if(it.size()>tmp.size()){
            string tmp1 = it;
            reverse(tmp1.begin(), tmp1.end());
            if(tmp1.find(tmp3)==0)
                flag = false;
        }
        else{
            string tmp1 = it;
            reverse(tmp1.begin(), tmp1.end());
            if(tmp3.find(tmp1)==0){
                phone.erase(it);
            }
        }
    }
    if(flag){
        phone.insert(tmp);
    }
}
bool cmp1(const string &s1,const string &s2){
    if(s1.size()!=s2.size()) return s1.size()<s2.size();
    else return s1<s2;
}
int main(){
    int n;
    cin>>n;
    map<string,person> lis;
    while(n--){
        string name;
        int num;
        cin>>name>>num;
        lis[name].name = name;
        while(num--){
            string tmp;
            cin>>tmp;
            cmp(tmp,lis[name].phone);
        }
    }
    cout<<lis.size()<<endl;
    for(auto it:lis){
        cout<<it.first<<" "<<it.second.phone.size()<<" ";
        for(int i=0;i<it.second.phone.size()/it.second.phone.size();i++){
            vector<string> result;
            result.assign(it.second.phone.begin(), it.second.phone.end());
            sort(result.begin(), result.end(), cmp1);
            for(auto j:result){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
