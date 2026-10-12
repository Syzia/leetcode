/*
169. Majority Element (Easy) -- Top Interview 150, Array / String #5

Return the majority element of nums: the value that appears more than
n / 2 times. It is guaranteed to exist.

    nums = [3,2,3]          ->  3
    nums = [2,2,1,1,1,2,2]  ->  2

Follow-up: O(n) time, O(1) extra space.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return 0;  // TODO
    }
};

void show(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Case { vector<int> nums; int want; };
    vector<Case> cases = {
        {{3, 2, 3}, 3},
        {{2, 2, 1, 1, 1, 2, 2}, 2},
        {{1}, 1},
        {{6, 5, 5}, 5},
        {{-1, -1, 2}, -1},
    };
    for (auto& c : cases) {
        int got = Solution().majorityElement(c.nums);
        cout << (got == c.want ? "ok   " : "FAIL ");
        show(c.nums); cout << " -> " << got << " (want " << c.want << ")\n";
    }
}
