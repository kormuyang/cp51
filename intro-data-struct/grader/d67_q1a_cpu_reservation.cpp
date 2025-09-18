#include <bits/stdc++.h>

bool checkIntersection(std::pair<int, int> a, std::pair<int, int> b) {
    return std::max(a.first, b.first) <= std::min(a.second, b.second);
}

int main() {
    int n;
    std::cin >> n;
    std::set<std::pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        int l, r;
        std::cin >> l >> r;
        auto it = s.lower_bound(std::make_pair(l, -1));
        if (it != s.end() && checkIntersection(*it, std::make_pair(l, r))) {
            continue;
        }
        if (it != s.begin() && checkIntersection(*prev(it), std::make_pair(l, r))) {
            continue;
        }
        std::cout << i << ' ';
        s.insert({l, r});
    }
    return 0;
}
