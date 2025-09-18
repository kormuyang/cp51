#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::map<std::string, std::set<std::string>> dton;
    std::map<std::string, std::string> ntod;
    while (n--) {
        std::string name, department;
        std::cin >> name >> department;
        dton[department].insert(name);
        ntod[name] = department;
    }
    while (m--) {
        int t;
        std::string a, b;
        std::cin >> t >> a >> b;
        if (t == 1) {
            dton[ntod[a]].erase(a);
            ntod[a] = b;
            dton[b].insert(a);
       } else {
            for (auto name : dton[a]) {
                dton[b].insert(name);
                ntod[name] = b;
            }
            dton.erase(a);
        }
    }
    for (auto &[department, members] : dton) {
        std::cout << department << ':';
        for (auto &name : members) {
            std::cout << ' ' << name;
        }
        std::cout << '\n';
    }
    return 0;
}
