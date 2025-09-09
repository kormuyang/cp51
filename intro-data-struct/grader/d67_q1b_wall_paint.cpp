#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m + 1);
    for (int i = 1; i <= m * 2; i++) {
        int x, c, d;
        cin >> x >> c >> d;
        if (d == 0) {
            v[c].first = x;
        } else {
            v[c].second = x;
        }
    }
    set<int> chk;
    vector<pair<int, int>> line;
    chk.insert(n + 1);
    for (int i = 1; i <= m; i++) {
        auto it = chk.lower_bound(v[i].first);
        if (*it > v[i].second) {
            chk.insert(v[i].first);
            chk.insert(v[i].second);
            line.push_back({v[i].first, 1});
            line.push_back({v[i].second + 1, -1});
        }
    }
    sort(line.begin(), line.end());
    int ans = 0, cur = 0;
    for (auto &[f, s] : line) {
        cur += s;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}
