#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    set<pair<int, int>> s;
    int sum = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it = s.lower_bound({l - 1, -1});
        while (it != s.end() && it->second <= r + 1) {
            l = min(l, it->second);
            r = max(r, it->first);
            sum -= (it->first - it->second + 1);
            it = s.erase(it);
        }
        sum += (r - l + 1);
        s.insert({r, l});
        cout << n - sum << '\n';
    }
    return 0;
}
