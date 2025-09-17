#include <bits/stdc++.h>

int main() {
    int q;
    std::cin >> q;
    long long mSize = 0, mCap = 1;
    while (q--) {
        int a, k;
        std::cin >> a >> k;
        mSize += (a == 0 ? k : -k);
        while (mCap < mSize) {
            mCap *= 2;
        }
    }
    std::cout << (mCap - mSize) << '\n';
    return 0;
}
