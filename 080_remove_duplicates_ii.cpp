/*
80. Remove Duplicates from Sorted Array II (Medium) -- Top Interview 150, Array / String #4

nums is sorted ascending. Remove duplicates in place so each value appears
at most twice, keeping relative order. Return k, the new length; the first
k slots of nums must hold the result. O(1) extra space.

    nums = [1,1,1,2,2,3]        ->  k = 5, first 5 = [1,1,2,2,3]
    nums = [0,0,1,1,1,1,2,3,3]  ->  k = 7, first 7 = [0,0,1,1,2,3,3]
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
        {{1, 1, 1, 2, 2, 3}, {1, 1, 2, 2, 3}},
        {{0, 0, 1, 1, 1, 1, 2, 3, 3}, {0, 0, 1, 1, 2, 3, 3}},
        {{1}, {1}},
        {{1, 1}, {1, 1}},
        {{5, 5, 5, 5, 5}, {5, 5}},
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
