/*
88. Merge Sorted Array (Easy) -- Top Interview 150, Array / String #1

nums1 and nums2 are sorted ascending. nums1 has length m + n: its first m
entries are real values and the last n are 0 placeholders. Merge nums2 into
nums1 in place so nums1 ends up sorted. Return nothing.

    nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3  ->  [1,2,2,3,5,6]
    nums1 = [1], m = 1, nums2 = [], n = 0                 ->  [1]
    nums1 = [0], m = 0, nums2 = [1], n = 1                ->  [1]

Follow-up: O(m + n) time, O(1) extra space.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    }
};

void show(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Case { vector<int> nums1; int m; vector<int> nums2; int n; vector<int> want; };
    vector<Case> cases = {
        {{1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}},
        {{1}, 1, {}, 0, {1}},
        {{0}, 0, {1}, 1, {1}},
        {{4, 5, 6, 0, 0, 0}, 3, {1, 2, 3}, 3, {1, 2, 3, 4, 5, 6}},
        {{2, 0}, 1, {1}, 1, {1, 2}},
    };
    for (auto& c : cases) {
        vector<int> got = c.nums1;
        Solution().merge(got, c.m, c.nums2, c.n);
        cout << (got == c.want ? "ok   " : "FAIL ");
        show(c.nums1); cout << " "; show(c.nums2); cout << " -> "; show(got);
        cout << " (want "; show(c.want); cout << ")\n";
    }
}
