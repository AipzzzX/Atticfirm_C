#include <iostream>
#include <vector>
using namespace std;
int countCombinations(vector<int>& coins, int target, int index) {
    if (target == 0) {
        return 1;
    }
    if (target < 0 || index >= coins.size()) {
        return 0;
    }
    int coin = coins[index];
    int count1 = countCombinations(coins, target - coin, index);
    int count2 = countCombinations(coins, target, index + 1);
    return count1 + count2;
}
void findCombinations(vector<int>& coins, vector<int>& current, int target, int index) {
    if (target == 0) {
        for (int i = 0; i < current.size(); i++) {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }
    if (target < 0 || index >= coins.size()) {
        return;
    }
    int coin = coins[index];
    current.push_back(coin);
    findCombinations(coins, current, target - coin, index);
    current.pop_back();
    findCombinations(coins, current, target, index + 1);
}
int main() {
    vector<int> coins = {1, 2, 5};
    vector<int> current;
    int target = 15;
    int count = countCombinations(coins, target, 0);
    cout << "总共有 " << count << " 种组合方式" << endl;
    cout << "组合方式：" << endl;
    findCombinations(coins, current, target, 0);
    return 0;
}

