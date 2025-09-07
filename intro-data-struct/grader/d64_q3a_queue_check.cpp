#include <bits/stdc++.h>

using namespace std;

pair<bool, int> check(int front, int size, int cap, int last, int correction) {
    pair<bool, int> out = {true, -1};
    if (front < cap && size <= cap && last < cap && (front + size) % cap == last) {
        return out;
    } else if (correction == 0) {
        out = {false, -1};
    } else if (correction == 1) {
        out = {false, (last - size + cap) % cap};
    } else if (correction == 2) {
        out = {false, (last - front + cap) % cap};
    } else if (correction == 3) {
        out = {false, (last > front ? last + 1 : front + size - last)};
    } else {
        out = {false, (front + size) % cap};
    }
    return out;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int front, size, cap, last, correction;
        cin >> front >> size >> cap >> last >> correction;
        auto [chk, val] = check(front, size, cap, last, correction);
        if (chk) {
            cout << "OK\n";
        } else if (val == -1) {
            cout << "WRONG\n";
        } else {
            cout << "WRONG " << val << '\n';
        }
    }
    return 0;
}
