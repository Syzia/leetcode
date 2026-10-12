/*
3. Longest Substring Without Repeating Characters (Medium) -- Top Interview 150, Sliding Window

Given a string s, return the length of the longest substring
that contains no repeated characters.

    "abcabcbb" -> 3   ("abc")
    "bbbbb"    -> 1   ("b")
    "pwwkew"   -> 3   ("wke")

Constraints: 0 <= s.length <= 5 * 10^4; s is letters, digits, symbols, spaces.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return 0;  // TODO
    }
};

int main() {
    struct Case { string s; int want; };
    vector<Case> cases = {
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
        {"", 0},
        {" ", 1},
        {"dvdf", 3},
        {"abba", 2},
        {"tmmzuxt", 5},
    };
    for (auto& c : cases) {
        int got = Solution().lengthOfLongestSubstring(c.s);
        cout << (got == c.want ? "ok   " : "FAIL ");
        cout << "\"" << c.s << "\" -> " << got << " (want " << c.want << ")\n";
    }
}
