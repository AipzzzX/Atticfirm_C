#include <iostream>
#include <vector>

using namespace std;

// 在有序序列a中查找两个数的和是否等于x
bool FindPair(vector<int>& a, int low, int high, int x) {
    while (low < high) {
        int sum = a[low] + a[high - 1];
        if (sum == x) {
            return true;
        } else if (sum > x) {
            high--;
        } else {
            low++;
        }
    }
    return false;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 10;
    bool exist = FindPair(a, 0, a.size(), x);
    if (exist) {
        cout << "在序列中存在两个整数，它们的和为 " << x << endl;
    } else {
        cout << "在序列中不存在两个整数，它们的和为 " << x << endl;
    }
    return 0;
}
