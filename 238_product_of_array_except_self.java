/*
238. Product of Array Except Self (Medium) -- Top Interview 150, Array / String

Given an integer array nums, return an array answer where answer[i] is the
product of every element of nums except nums[i]. Must run in O(n) time
without using division.

    [1,2,3,4]       ->  [24,12,8,6]
    [-1,1,0,-3,3]   ->  [0,0,9,0,0]

Approach: two passes. The first fills ans[i] with the product of everything
to the left of i; the second walks back from the right, multiplying in the
product of everything to the right. O(n) time, O(1) extra space beyond the
output array.
*/
import java.util.Arrays;

// Shrutink
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int ans[] = new int[nums.length];
        int n=nums.length;
        int suf =1;
        int pre =1;
        for(int i=0;i<n;i++){
            ans[i]=pre;
          pre=pre*nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]=ans[i]*suf;
            suf=suf*nums[i];
        }
        return ans;


    }
}

class Main {
    public static void main(String[] args) {
        int[][][] cases = {
            {{1, 2, 3, 4}, {24, 12, 8, 6}},
            {{-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0}},
            {{2, 3}, {3, 2}},
            {{0, 0}, {0, 0}},
            {{0, 4, 5}, {20, 0, 0}},
            {{-1, -2, -3}, {6, 3, 2}},
            {{1, 1, 1, 1}, {1, 1, 1, 1}},
            {{5, 0, 2, 0}, {0, 0, 0, 0}},
        };
        for (int[][] c : cases) {
            int[] got = new Solution().productExceptSelf(c[0].clone());
            System.out.println((Arrays.equals(got, c[1]) ? "ok   " : "FAIL ")
                + Arrays.toString(c[0]) + " -> " + Arrays.toString(got)
                + " (want " + Arrays.toString(c[1]) + ")");
        }
    }
}
