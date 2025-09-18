#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<int, int>> st;
    while (n--) {
        int o;
        cin >> o;
        if (o == 1) {
            int l, r;
            cin >> l >> r;
            auto it = st.lower_bound(make_pair(l - 1, -1));
            while (it != st.end() && it->second <= r + 1) {
                l = min(l, it->second);
                r = max(r, it->first);
                it = st.erase(it);
            }
            st.insert(make_pair(r, l));
        } else {
            cout << st.size() << '\n';
        }
    }
    return 0;
}
