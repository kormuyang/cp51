#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq1;
    vector<int> pq2(m);
    for (int i = 0; i < m; i++) {
        pq2[i] = 1;
        pq1.push({1, i});
    }
    for (auto &[power, type] : v) {
        if (power > pq2[type]) {
            pq2[type] = power;
            pq1.push({power, type});
        }
        while (!pq1.empty() && pq1.top().first != pq2[pq1.top().second]) {
            pq1.pop();
        }
        cout << pq1.top().first << ' ';
    }
    return 0;
}
