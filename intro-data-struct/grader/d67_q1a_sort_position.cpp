#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i].first;
        v[i].second = i;
    }
    std::sort(v.begin(), v.end());
    std::vector<std::pair<int, int>> out(n);
    for (int i = 0; i < n; i++) {
        out[i] = {v[i].second, i + 1};
    }
    std::sort(out.begin(), out.end());
    for (auto &[f, s] : out) {
        std::cout << s << ' ';
    }
    return 0;
}
