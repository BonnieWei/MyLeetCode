#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findS(vector<int> &res, int num, int pos, int n, int l) {
    if(l == 0) {
        if(n == 4 && num < 12)
            res.push_back(num);
        else if(n == 6 && num < 60)
            res.push_back(num);
        return;
    }
    for(int i = pos; i < n; i++) {
        int c = 1<<i;
        num += c;
        findS(res, num, i+1, n, l-1);
        num -= c;
    }
}
vector<string> readBinaryWatch(int num) {
    vector<string> res;
    if(num == 0) return {"00:00"};
    for(int i = 0; i < 4 && i <= num; i++) {
        int t = 0;
        vector<int> h;
        vector<int> m;
        findS(h, t, 0, 4, i);
        t = 0;
        findS(m, t, 0, 6, num - i);
        for(int i = 0; i < h.size(); i++) {
            for(int j = 0; j < m.size(); j++) {
                string s = to_string(h[i])+":";
                if(m[i] < 10) {
                    s = s + "0";
                }
                s = s + to_string(m[j]);
                res.push_back(s);
            }
        }
    }
    return res;
}
int main() {
    int n;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        vector<string> res;
        res = readBinaryWatch(n);
    }
    return 0;
}