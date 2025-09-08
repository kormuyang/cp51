#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<int, int>> s;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            auto it = s.upper_bound({l, -1});
            if (it != s.begin()) {
                --it;
                if (it->first <= l && l - 1 <= it->second) {
                    l = min(l, it->first);
                    r = max(r, it->second);
                    it = s.erase(it);
                } else {
                    ++it;
                }
            }
            while (it != s.end() && r + 1 >= it->first) {
                r = max(r, it->second);
                it = s.erase(it);
            }
            s.insert({l, r});
        } else {
            cout << s.size() << '\n';
        }
    }
    return 0;
}
