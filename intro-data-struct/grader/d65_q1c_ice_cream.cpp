#include <bits/stdc++.h>

#define MAX_ANS 100000

int main() {
    int n, m, start;
    std::cin >> n >> m >> start;
    std::vector<int> qsum(MAX_ANS + 1, 0);
    qsum[0] = start;
    for (int i = 1; i <= n; i++) {
        int a, s;
        std::cin >> a >> s;
        qsum[a] = s;
    }
    int c = start;
    for (int i = 1; i <= MAX_ANS; i++) {
        if (qsum[i]) {
            c = qsum[i];
        }
        qsum[i] = qsum[i - 1] + c;
    }
    while (m--) {
        int p, x;
        std::cin >> p >> x;
        int tar = (qsum[x] < p ? p + qsum[x] : p);
        std::cout << std::lower_bound(qsum.begin(), qsum.end(), tar) - qsum.begin() << ' ';
    }
    return 0;
}
