/*
122. Best Time to Buy and Sell Stock II (Medium) -- Top Interview 150, Array / String

prices[i] is the price of a stock on day i. You may buy and sell as often
as you like, including on the same day, but can hold at most one share at
a time. Return the maximum profit.

    [7,1,5,3,6,4]  ->  7   (buy 1 sell 5, buy 3 sell 6)
    [1,2,3,4,5]    ->  4   (buy 1 sell 5)
    [7,6,4,3,1]    ->  0   (never buy)

Approach: greedy. Every day-to-day rise can be captured, so the answer is
the sum of all positive differences between consecutive days.
O(n) time, O(1) space.
*/
import java.util.Arrays;

class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit=0;
        int i=0;
        for(int j=1;j<prices.length;j++){
            if(prices[j]>=prices[i]){
                maxprofit+=prices[j]-prices[i];
            }
            i++;
        }
        return maxprofit;
    }
}

class Main {
    public static void main(String[] args) {
        int[][] inputs = {
            {7, 1, 5, 3, 6, 4},
            {1, 2, 3, 4, 5},
            {7, 6, 4, 3, 1},
            {5},
            {3, 3, 3},
            {1, 5},
            {5, 1},
            {2, 1, 2, 0, 1},
            {1, 9, 2, 8},
        };
        int[] wants = {7, 4, 0, 0, 0, 4, 0, 2, 14};
        for (int t = 0; t < inputs.length; t++) {
            int got = new Solution().maxProfit(inputs[t]);
            System.out.println((got == wants[t] ? "ok   " : "FAIL ")
                + Arrays.toString(inputs[t]) + " -> " + got + " (want " + wants[t] + ")");
        }
    }
}
