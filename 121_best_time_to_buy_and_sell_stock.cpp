/*
121. Best Time to Buy and Sell Stock (Easy) -- Top Interview 150, Array / String

prices[i] is the price of a stock on day i. Buy on one day and sell on a
later day to maximize profit. Return the best profit, or 0 if none is
possible.

    [7,1,5,3,6,4]  ->  5   (buy at 1, sell at 6)
    [7,6,4,3,1]    ->  0

Approach: one pass, tracking the lowest price seen so far and the best
profit from selling today against that minimum. O(n) time, O(1) space.
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minimum = INT_MAX;
        int result = 0;

        for(int i = 0; i < prices.size(); i++) {

            if(prices[i] < minimum) {
                minimum = prices[i];
            }

            result = max(result, prices[i] - minimum);
        }

        return result;
    }
};

void show(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Case { vector<int> prices; int want; };
    vector<Case> cases = {
        {{7, 1, 5, 3, 6, 4}, 5},
        {{7, 6, 4, 3, 1}, 0},
        {{5}, 0},
        {{1, 2}, 1},
        {{2, 1}, 0},
        {{3, 3, 3}, 0},
        {{2, 4, 1}, 2},
        {{3, 8, 1, 5}, 5},
        {{0, 10000}, 10000},
    };
    for (auto& c : cases) {
        int got = Solution().maxProfit(c.prices);
        cout << (got == c.want ? "ok   " : "FAIL ");
        show(c.prices); cout << " -> " << got << " (want " << c.want << ")\n";
    }
}
