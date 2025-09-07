#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;
    queue<int> q;
    q.push(1);
    vector<int> prev(x * 3 + 1, -1);
    prev[1] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr * 3 <= x * 3 && prev[curr * 3] == -1) {
            q.push(curr * 3);
            prev[curr * 3] = curr;
        }
        if (curr / 2 != 0 && prev[curr / 2] == -1) {
            q.push(curr / 2);
            prev[curr / 2] = curr;
        }
    }
    if (prev[x] != -1) {
        string out = "";
        int curr = x;
        while (prev[curr] != 1) {
            if (prev[curr] * 3 == curr) {
                out = " * 3" + out;
            } else {
                out = " / 2" + out;
            }
            curr = prev[curr];
        }
        cout << "1" + out << '\n';
    } else {
        cout << "-1\n";
    }
    return 0;
}
