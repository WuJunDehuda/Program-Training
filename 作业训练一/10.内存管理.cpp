#include <iostream>
using namespace std;
int n,m;
int Serial = 0;
int BolckCount = 0;
struct ramblock
{
    int serial = 0;      //编号
    int pos = 0;        //相对位置
    int startPos = 0;    //占用开始位置（含）
    int endPos = 0;      //占用结束位置（含）
    bool erased = false; //是否已经抹除
};
void doAlloc(ramblock *a,int *b,int num){
    Serial++;
    a[Serial].serial = Serial;
}
void doErase(ramblock *a,int num){

}
void doDefragment(){

}
int main(){
    int num;
    ramblock a[502];
    int b[m];
    for(int i=0;i<m;i++){
        b[i] = 0;
    }
    cin>>n>>m;
    string operat;
    for(int i=0;i<n;i++){
        cin>>operat;
        if(operat=="alloc"){
            cin>>num;
            doAlloc(a,b,num);
        }
        else if(operat=="erase"){
            cin>>num;
            doErase();
        }
        else if(operat=="defragment"){
            doDefragment();
        }
    }
    return 0;
}
