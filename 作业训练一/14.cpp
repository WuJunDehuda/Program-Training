#include<iostream>
#include <algorithm>
using namespace std;
int dat2num(string s){
    if(s=="monday") return 0;
    if(s=="tuesday") return 1;
    if(s=="wednesday") return 2;
    if(s=="thursday") return 3;
    if(s=="friday") return 4;
    if(s=="saturday") return 5;
    if(s=="sunday")  return 6;
}
int main() {
    int T, L, R;
    string S, E;
    int s, e;
    cin >> T;
    int ans;
    for (int i = 0; i < T; i++) {
        cin >> S >> E;
        s = dat2num(S);
        e = dat2num(E);
        cin >> L >> R;
        if (e - s > 0 && (e - s + 1) < L) {
            cout << "impossible"<<endl;
            break;
        } else if (e - s < 0 && (e - s + 8) < L) {
            cout << "impossible"<<endl;
            break;
        }
        if (R - L > 7) {
            cout << "many" << endl;
            break;
        }
        int temp = abs(e - s) + 1;
        if (s > e) temp += 7;
        for (int j = L; j <= R; j++) {
            if (j % 7 == temp % 7) {
                ans = j;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
