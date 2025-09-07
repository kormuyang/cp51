#include <bits/stdc++.h>

using namespace std;

#define BASE 10

int get_num_digit(vector<int> &v) {
    int max_element = v[0];
    for (int i = 1; i < v.size(); ++i) {
        max_element = max(max_element, v[i]);
    }
    int out = 0;
    while (max_element) {
        ++out;
        max_element /= BASE;
    }
    return out;
}

int get_kth_digit(int x, int k) {
    for (int i = 0; x && i < k; ++i) {
        x /= BASE;
    }
    return (x % BASE);
}

void radix_sort(vector<int> &v) {
    int mx_digit = get_num_digit(v);
    for (int k = 0; k < mx_digit; ++k) {
        queue<int> q[BASE];
        for (int &x : v) {
            q[get_kth_digit(x, k)].push(x);
        }
        v.clear();
        for (int i = 0; i < BASE; ++i) {
            while (!q[i].empty()) {
                v.push_back(q[i].front());
                q[i].pop();
            }
        }
    }
    return;
}

int main() {
    vector<int> v = {115, 42, 15, 304, 21, 8, 463};
    radix_sort(v);
    for (int &x : v) {
        cout << x << ' ';
    }
    return 0;
}
