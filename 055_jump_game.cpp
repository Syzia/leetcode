/*
55. Jump Game (Medium) -- Top Interview 150, Array / String

You start at index 0 of nums, and nums[i] is the maximum jump length from
index i. Return true if you can reach the last index.

    [2,3,1,1,4]  ->  true
    [3,2,1,0,4]  ->  false   (always stuck at index 3)

Approach: greedy, walking backwards. Keep the leftmost index known to reach
the end; any earlier index that can jump at least that far becomes the new
target. The end is reachable if the target finishes at index 0.
O(n) time, O(1) space.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int j = n - 2;
        int targetIdx = n - 1;

        while(j >= 0) {
            if(nums[j] >= (targetIdx - j)) {
                targetIdx = j;
            }
            j--;
        }

        return targetIdx == 0 ? true : false;
    }
};

void show(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Case { vector<int> nums; bool want; };
    vector<Case> cases = {
        {{2, 3, 1, 1, 4}, true},
        {{3, 2, 1, 0, 4}, false},
        {{0}, true},
        {{1}, true},
        {{0, 1}, false},
        {{1, 0}, true},
        {{2, 0, 0}, true},
        {{1, 0, 1}, false},
        {{5, 0, 0, 0, 0, 0}, true},
        {{4, 0, 0, 0, 0, 0}, false},
        {{1, 1, 1, 1}, true},
    };
    cout << boolalpha;
    for (auto& c : cases) {
        bool got = Solution().canJump(c.nums);
        cout << (got == c.want ? "ok   " : "FAIL ");
        show(c.nums); cout << " -> " << got << " (want " << c.want << ")\n";
    }
}
