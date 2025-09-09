#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <bits/stdc++.h>

using namespace std;

class Wallet {
public:
    queue<pair<size_t, int>> adds;
    int totalMoney = 0;
};

class Action {
public:
    size_t time;
    string id;
    bool operator<(const Action &other) const { return time > other.time; }
};

class DigitalWallet {
    std::map<string, Wallet> wallets;
    priority_queue<Action> actions;
    int totalGive = 0, totalSpent = 0, totalExpired = 0;

public:
    void update(size_t time) {
        while (!actions.empty() && actions.top().time <= time) {
            Action action = actions.top();
            actions.pop();
            Wallet &wallet = wallets[action.id];
            while (!wallet.adds.empty() && wallet.adds.front().first <= action.time) {
                wallet.totalMoney -= wallet.adds.front().second;
                totalExpired += wallet.adds.front().second;
                wallet.adds.pop();
            }
        }
        return;
    }

    void add_money(size_t time, string person_id, int amount, size_t duration) {
        update(time);
        Wallet &wallet = wallets[person_id];
        wallet.adds.push({time + duration + 1, amount});
        wallet.totalMoney += amount;
        actions.push({time + duration + 1, person_id});
        totalGive += amount;
        return;
    }

    bool use_money(size_t time, string person_id, int amount) {
        update(time);
        Wallet &wallet = wallets[person_id];
        if (wallet.totalMoney < amount) {
            return false;
        }
        wallet.totalMoney -= amount;
        totalSpent += amount;
        while (amount) {
            int &current = wallet.adds.front().second;
            if (current > amount) {
                current -= amount;
                amount = 0;
            } else {
                amount -= current;
                wallet.adds.pop();
            }
        }
        return true;
    }

    int current_money(size_t time, string person_id) {
        update(time);
        return wallets[person_id].totalMoney;
    }

    void status(size_t time, long long &total_give, long long &total_spent,
                long long &total_expired) {
        update(time);
        total_give = totalGive;
        total_spent = totalSpent;
        total_expired = totalExpired;
        return;
    }
};

#endif
