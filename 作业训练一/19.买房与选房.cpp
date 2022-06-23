#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
using namespace std;

struct people{
    char id[19];                  /* 身份证号码 */
    int social;                     /* 社保缴纳月数 */
    int area;                       /* 现有住房面积 */
    char date[11];              /* 申报日期 */
};
struct ppeple{
    int num;
    bool same = false;
    string id;
    int social;
    int area;
    string date;
    int year,month,day;
};
people* getMess(int &n);
string to_string(const char* c);
bool cmp(const ppeple &p1,const ppeple &p2){
    if(p1.area!=p2.area) return p1.area<p2.area;
    else if(p1.area==0&&p2.area==0) return p1.social>p2.social;
    else if(p1.year!=p2.year) return p1.year<p2.year;
    else if(p1.month!=p2.month) return p1.month<p2.month;
    else return p1.day<p2.day;
}
bool isSame(const ppeple &p1,const ppeple &p2){
    if(p1.area==p2.area&&p1.social==p2.social&&p1.date==p2.date) return true;
    else return false;
}
int main(){
    people *person;          /* 指向所有报名人的基本资料首地址，通过调用函数getMess获取 */
    ppeple *pperson;
    int n;                            /* n为报名人数，通过调用函数getMess获取 */
    person=getMess(n);
    for(int i=0;i<n;i++){
        pperson[i].id = to_string(person[i].id);
        pperson[i].area = person[i].area;
        pperson[i].social = person[i].social;
        stringstream ss;
        ss<<person[i].date;
        char tmp;
        ss>>pperson[i].month>>tmp>>pperson[i].day>>tmp>>pperson[i].year;
    }
    sort(pperson,pperson+n,cmp);
    map<string,ppeple> res;
    pperson[0].num = 1;
    res[pperson[0].id] = pperson[0];
    for(int i=1;i<n;i++){
        if(isSame(pperson[i-1],pperson[i])){
            pperson[i-1].same = true;
            pperson[i-1].same = true;
        }
        pperson[i].num = i+1;
        res[pperson[i].id] = pperson[i];
    }
    int x,y;
    cin>>x>>y;
    string name;
    for(int i=0;i<y;i++){
        cin>>name;
        if(res[name].social<2||res[name].num>x) cout<<"Sorry"<<endl;
        else if(!res[name].same) cout<<res[name].num<<endl;
        else if(res[name].same&&res[name].num<x){
            int count = res[name].num;
            for(int i=res[name].num-1;i<n;i++){         //可能会有错 连续的same
                if(pperson[i].same) count++;
                else break;
            }
            if(count>x) cout<<res[name].num<<" "<<count<<endl;
        }
        else {
            int count = 0;
            for(int i=res[name].num-1;i<n;i++){         //可能会有错 连续的same
                if(pperson[i].same) count++;
                else break;
            }
            cout<<x-res[name].num<<"/"<<count<<endl;
        }
        return 0;
    }



    return 0;
}

people* getMess(int &n)            /* 将文件数据读入内存 */

{

    FILE *fp;

    fp=fopen("house.bin","rb");

    fseek(fp,-1*(long)sizeof(int), 2);

    fread(&n, sizeof(int),1, fp);

    rewind(fp);

    people *tmp=new people[n];

    fread(tmp, sizeof(people), n, fp);

    fclose(fp);

    return tmp;

}
string to_string(const char* c){
    stringstream ss;
    ss<<c;
    string result = ss.str();
    return result;
}
