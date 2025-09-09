#include <bits/stdc++.h>

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> k(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        std::cin >> k[i];
    }
    std::vector<std::map<int, int>> mp(n + 1);
    while (q--) {
        char op;
        std::cin >> op;
        if (op == 'B') {
            int u, i, v;
            std::cin >> u >> i >> v;
            mp[i][u] = v;
        } else {
            int u, i;
            std::cin >> u >> i;
            auto it = mp[i].find(u);
            if (it != mp[i].end()) {
                mp[i].erase(it);
            }
        }
    }
    std::vector<std::vector<int>> out(m + 1);
    for (int i = 1; i <= n; ++i) {
        if (mp[i].size() <= k[i]) {
            for (auto &[usr, bid] : mp[i]) {
                out[usr].push_back(i);
            }
        } else {
            std::vector<std::pair<int, int>> tmp;
            for (auto &[usr, bid] : mp[i]) {
                tmp.push_back({bid, usr});
            }
            std::sort(tmp.begin(), tmp.end(), std::greater<>());
            for (int j = 0; j < k[i]; ++j) {
                out[tmp[j].second].push_back(i);
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (out[i].empty()) {
            std::cout << "NONE\n";
        } else {
            for (auto &item : out[i]) {
                std::cout << item << ' ';
            }
            std::cout << '\n';
        }
    }
    return 0;
}
