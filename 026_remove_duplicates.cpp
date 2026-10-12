/*
26. Remove Duplicates from Sorted Array (Easy) -- Top Interview 150, Array / String #3

nums is sorted ascending. Remove duplicates in place so each value appears
once, keeping relative order. Return k, the number of unique values; the
first k slots of nums must hold them. Anything after index k is ignored.

    nums = [1,1,2]                ->  k = 2, first 2 = [1,2]
    nums = [0,0,1,1,1,2,2,3,3,4]  ->  k = 5, first 5 = [0,1,2,3,4]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return 0;  // TODO
    }
};

void show(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Case { vector<int> nums; vector<int> want; };
    vector<Case> cases = {
        {{1, 1, 2}, {1, 2}},
        {{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 1, 2, 3, 4}},
        {{1}, {1}},
        {{2, 2, 2, 2}, {2}},
        {{1, 2, 3}, {1, 2, 3}},
    };
    for (auto& c : cases) {
        vector<int> nums = c.nums;
        int k = Solution().removeDuplicates(nums);
        bool valid = k >= 0 && k <= (int)nums.size();
        vector<int> got = valid ? vector<int>(nums.begin(), nums.begin() + k) : vector<int>();
        cout << (valid && got == c.want ? "ok   " : "FAIL ");
        show(c.nums); cout << " -> k=" << k << " "; show(got);
        cout << " (want "; show(c.want); cout << ")\n";
    }
}
