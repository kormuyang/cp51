#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(m), v;
    for (int &x : p) {
        cin >> x;
    }
    queue<int> q1, q2;
    v.push_back(0);
    while (n--) {
        int q;
        cin >> q;
        if (q == 1) {
            int a, b;
            cin >> a >> b;
            if (a == 1) {
                q1.push(b);
            } else {
                q2.push(b);
            }
        } else {
            int t1 = (q1.empty() ? INT_MAX : q1.front()), t2 = (q2.empty() ? INT_MAX : q2.front());
            if (t1 <= t2) {
                q1.pop();
                v.push_back(v[v.size() - 1] + t1);
            } else {
                q2.pop();
                v.push_back(v[v.size() - 1] + t2);
            }
        }
    }
    for (int &x : p) {
        int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
        cout << (idx == v.size() ? -1 : idx) << ' ';
    }
    return 0;
}
