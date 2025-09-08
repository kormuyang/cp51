#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    vector<pair<int, int>> v(n + 1);
    v[0] = {0, start};
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<int> qsum(n + 1);
    qsum[0] = start;
    for (int i = 1; i <= n; i++) {
        qsum[i] = qsum[i - 1] + v[i].second + (v[i].first - v[i - 1].first - 1) * v[i - 1].second;
    }
    while (m--) {
        int p, x;
        cin >> p >> x;
        if (p <= qsum[0]) {
            cout << v[0].first << ' ';
            continue;
        }
        int nft = upper_bound(v.begin(), v.end(), make_pair(x, -1)) - v.begin() - 1;
        int sum = qsum[nft] + (x - v[nft].first) * v[nft].second;
        int tar = (sum < p ? p + sum : p);
        int idx = upper_bound(qsum.begin(), qsum.end(), tar) - qsum.begin() - 1;
        cout << v[idx].first + ((tar - qsum[idx] + v[idx].second - 1) / v[idx].second) << ' ';
    }
    return 0;
}
