#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    for (auto &x : v) {
        std::cin >> x;
    }
    sort(v.begin(), v.end());
    std::map<int, int> mp1;
    std::map<int, std::set<int>> mp2;
    while (m--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int a, b;
            std::cin >> a >> b;
            if (!std::binary_search(v.begin(), v.end(), a)) {
                continue;
            }
            if (mp1.find(a) != mp1.end()) {
                mp2[mp1[a]].erase(a);
                if (mp2[mp1[a]].empty()) {
                    mp2.erase(mp2.find(mp1[a]));
                }
            }
            mp1[a] += b;
            mp2[mp1[a]].insert(a);
        } else {
            int k;
            std::cin >> k;
            auto it2 = mp2.lower_bound(k);
            if (it2 == mp2.begin()) {
                std::cout << "NONE\n";
            } else {
                --it2;
                auto &[key, val] = *it2;
                std::cout << *val.rbegin() << '\n';
            }
        }
    }
    return 0;
}
