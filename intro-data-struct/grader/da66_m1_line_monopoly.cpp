#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<int, int>> s, reversed_s;
    while (n--) {
        int q;
        cin >> q;
        if (q == 1) {
            int a, b;
            cin >> a >> b;
        } else {
            cout << s.size() << '\n';
        }
    }
    return 0;
}
