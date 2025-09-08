#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        pq.push({0, t});
    }
    for (int i = 0; i < m; i++) {
        auto [x, t] = pq.top();
        pq.pop();
        cout << x << '\n';
        pq.push({x + t, t});
    }
    return 0;
}
