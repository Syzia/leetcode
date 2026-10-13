/*
189. Rotate Array (Medium) -- Top Interview 150, Array / String

Rotate the integer array nums to the right by k steps, in place.

    nums = [1,2,3,4,5,6,7], k = 3  ->  [5,6,7,1,2,3,4]
    nums = [-1,-100,3,99], k = 2   ->  [3,99,-1,-100]

Approach: three reversals. Reverse the whole array, then reverse the first
k elements and the remaining n - k elements separately. Taking k mod n
first handles k larger than the array. O(n) time, O(1) extra space.
*/
import java.util.Arrays;

class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n; // Handles cases where k > n

        reverse(nums, 0, n - 1); // Step 1: Reverse whole array
        reverse(nums, 0, k - 1); // Step 2: Reverse first k elements
        reverse(nums, k, n - 1); // Step 3: Reverse the rest
    }

    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}

class Main {
    public static void main(String[] args) {
        int[][] inputs = {
            {1, 2, 3, 4, 5, 6, 7},
            {-1, -100, 3, 99},
            {1},
            {1, 2},
            {1, 2},
            {1, 2, 3},
            {1, 2, 3},
            {1, 2, 3, 4},
        };
        int[] ks = {3, 2, 5, 1, 2, 0, 4, 6};
        int[][] wants = {
            {5, 6, 7, 1, 2, 3, 4},
            {3, 99, -1, -100},
            {1},
            {2, 1},
            {1, 2},
            {1, 2, 3},
            {3, 1, 2},
            {3, 4, 1, 2},
        };
        for (int t = 0; t < inputs.length; t++) {
            int[] got = inputs[t].clone();
            new Solution().rotate(got, ks[t]);
            System.out.println((Arrays.equals(got, wants[t]) ? "ok   " : "FAIL ")
                + Arrays.toString(inputs[t]) + " k=" + ks[t] + " -> " + Arrays.toString(got)
                + " (want " + Arrays.toString(wants[t]) + ")");
        }
    }
}
