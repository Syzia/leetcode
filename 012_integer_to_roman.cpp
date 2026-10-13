/*
12. Integer to Roman (Medium) -- Top Interview 150, Array / String

Convert an integer (1 <= num <= 3999) to a Roman numeral. Symbols are
I=1, V=5, X=10, L=50, C=100, D=500, M=1000, with the subtractive forms
IV, IX, XL, XC, CD and CM used for 4, 9, 40, 90, 400 and 900.

    3749  ->  "MMMDCCXLIX"
    58    ->  "LVIII"
    1994  ->  "MCMXCIV"

Approach: greedy. List the 13 values (symbols plus subtractive forms) from
largest to smallest and keep subtracting the largest one that still fits.
O(1) time and space, since num is bounded.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    const int    intgr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

public:
    string intToRoman(int num)
    {
        string rom = "";

        for (int i = 0; num > 0; i++)
		    // each digit is repeated as many times as needed to
			// completely cover the decimal representation
            while (num >= intgr[i]) rom += roman[i], num -= intgr[i];
        return rom;
    }
};

int main() {
    struct Case { int num; string want; };
    vector<Case> cases = {
        {3749, "MMMDCCXLIX"},
        {58, "LVIII"},
        {1994, "MCMXCIV"},
        {1, "I"},
        {4, "IV"},
        {9, "IX"},
        {14, "XIV"},
        {40, "XL"},
        {444, "CDXLIV"},
        {2024, "MMXXIV"},
        {3888, "MMMDCCCLXXXVIII"},
        {3999, "MMMCMXCIX"},
    };
    for (auto& c : cases) {
        string got = Solution().intToRoman(c.num);
        cout << (got == c.want ? "ok   " : "FAIL ");
        cout << c.num << " -> \"" << got << "\" (want \"" << c.want << "\")\n";
    }
}
