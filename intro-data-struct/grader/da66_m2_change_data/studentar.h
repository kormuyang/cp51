#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to) {
    std::stack<std::vector<std::queue<int>>> tmp_st;
    while (!a.empty()) {
        for (auto &q : a.top()) {
            std::queue<int> tmp_q;
            while (!q.empty()) {
                tmp_q.push(q.front() == from ? to : q.front());
                q.pop();
            }
            q.swap(tmp_q);
        }
        tmp_st.push(a.top());
        a.pop();
    }
    while (!tmp_st.empty()) {
        a.push(tmp_st.top());
        tmp_st.pop();
    }
    return;
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to) {
    for (auto &[key, val] : a) {
        auto &[ref_pq, ref_int] = val;
        std::priority_queue<int> tmp_pq;
        ref_int = (ref_int == from ? to : ref_int);
        while (!ref_pq.empty()) {
            tmp_pq.push(ref_pq.top() == from ? to : ref_pq.top());
            ref_pq.pop();
        }
        ref_pq.swap(tmp_pq);
    }
    return;
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a,
              int from, int to) {
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> tmp_s;
    for (auto &ref_pair : a) {
        auto [ref_list, ref_mp] = ref_pair;
        for (auto &ref_int : ref_list) {
            ref_int = (ref_int == from ? to : ref_int);
        }
        std::map<int, std::pair<int, string>> tmp_mp;
        for (auto &[ref_int, ref_pair] : ref_mp) {
            tmp_mp.insert({(ref_int == from ? to : ref_int),
                   {(ref_pair.first == from ? to : ref_pair.first), ref_pair.second}});
        }
        tmp_s.insert({ref_list, tmp_mp});
    }
    a.swap(tmp_s);
    return;
}

#endif
