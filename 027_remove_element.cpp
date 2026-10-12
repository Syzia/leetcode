/*
27. Remove Element (Easy) -- Top Interview 150, Array / String #2

Remove every occurrence of val from nums in place. Return k, the number of
elements that are not val. The first k slots of nums must hold those
elements (any order); whatever sits after index k is ignored.

    nums = [3,2,2,3], val = 3          ->  k = 2, first 2 = [2,2]
    nums = [0,1,2,2,3,0,4,2], val = 2  ->  k = 5, first 5 = [0,1,3,0,4]
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return 0;  // TODO
    }
};

void show(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    // want is sorted, since the kept elements may be in any order
    struct Case { vector<int> nums; int val; vector<int> want; };
    vector<Case> cases = {
        {{3, 2, 2, 3}, 3, {2, 2}},
        {{0, 1, 2, 2, 3, 0, 4, 2}, 2, {0, 0, 1, 3, 4}},
        {{}, 1, {}},
        {{1}, 1, {}},
        {{4, 5}, 7, {4, 5}},
    };
    for (auto& c : cases) {
        vector<int> nums = c.nums;
        int k = Solution().removeElement(nums, c.val);
        bool valid = k >= 0 && k <= (int)nums.size();
        vector<int> got = valid ? vector<int>(nums.begin(), nums.begin() + k) : vector<int>();
        sort(got.begin(), got.end());
        cout << (valid && got == c.want ? "ok   " : "FAIL ");
        show(c.nums); cout << " val=" << c.val << " -> k=" << k << " "; show(got);
        cout << " (want "; show(c.want); cout << ")\n";
    }
}
