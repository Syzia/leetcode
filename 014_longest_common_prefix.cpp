/*
14. Longest Common Prefix (Easy) -- Top Interview 150, Array / String

Return the longest common prefix shared by every string in strs, or "" if
there is none.

    ["flower","flow","flight"]  ->  "fl"
    ["dog","racecar","car"]     ->  ""

Approach: treat the first string as the candidate prefix and shrink its
length while comparing against each other string in turn.
O(total characters) time, O(1) extra space.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int len = strs[0].size();
        int n = strs.size();
        for (int i = 1; i < n; ++i) {
            int j = 0;
            int k = min(len, int(strs[i].size()));
            while (j < k && strs[0][j] == strs[i][j]) {
                j++;
            }
            if (j == 0) return "";
            len = j;
        }
        return strs[0].substr(0, len);
    }
};

int main() {
    struct Case { vector<string> strs; string want; };
    vector<Case> cases = {
        {{"flower", "flow", "flight"}, "fl"},
        {{"dog", "racecar", "car"}, ""},
        {{"alone"}, "alone"},
        {{""}, ""},
        {{"", "b"}, ""},
        {{"ab", "a"}, "a"},
        {{"same", "same", "same"}, "same"},
        {{"interview", "internet", "interval", "into"}, "int"},
        {{"abc", "abd", "xbc"}, ""},
    };
    for (auto& c : cases) {
        string got = Solution().longestCommonPrefix(c.strs);
        cout << (got == c.want ? "ok   " : "FAIL ") << "[";
        for (size_t i = 0; i < c.strs.size(); i++) cout << (i ? "," : "") << "\"" << c.strs[i] << "\"";
        cout << "] -> \"" << got << "\" (want \"" << c.want << "\")\n";
    }
}
