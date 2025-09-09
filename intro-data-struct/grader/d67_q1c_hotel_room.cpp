#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;
        s.insert({r, -i});
        sum += r;
    }
    while (m--) {
        int p;
        cin >> p;
        if (p > sum) {
            cout << "-1\n";
            continue;
        }
        sum -= p;
        vector<pair<int, int>> out;
        while (p) {
            if (s.rbegin()->first <= p) {
                auto it = s.lower_bound({s.rbegin()->first, -(n + 1)});
                out.push_back({-it->second, it->first});
                p -= it->first;
                s.erase(it);
            } else {
                auto it = s.lower_bound({p, -(n + 1)});
                out.push_back({-it->second, p});
                p = 0;
                s.insert({it->first - p, it->second});
                s.erase(it);
            }
        }
        sort(out.begin(), out.end());
        for (auto &[f, s] : out) {
            cout << f << ' ' << s << ' ';
        }
        cout << '\n';
    }
    return 0;
}
