#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        if (n != 0) {
            int pre, curr, result, count = 0, maxn = 0;
            for (int i = 0; i < n; i++) {
                cin >> curr;
                if (i == 0) {
                    pre = curr;
                }
                if (pre == curr) {
                    count++;
                }
                else {
                    if (maxn<count){
                        maxn = count;
                        result = pre;
                    }
                    count = 1;
                    pre = curr;
                }
            }
            if(curr==pre){
                if (maxn<count){
                    maxn = count;
                    result = pre;
                }
            }
            cout << result << endl;
        } else return 0;
    }
}
