"""
169. Majority Element (Easy) -- Top Interview 150, Array / String #5

Return the majority element of nums: the value that appears more than
n // 2 times. It is guaranteed to exist.

    nums = [3,2,3]          ->  3
    nums = [2,2,1,1,1,2,2]  ->  2

Follow-up: O(n) time, O(1) extra space.
"""
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        pass


if __name__ == "__main__":
    cases = [
        ([3, 2, 3], 3),
        ([2, 2, 1, 1, 1, 2, 2], 2),
        ([1], 1),
        ([6, 5, 5], 5),
        ([-1, -1, 2], -1),
    ]
    for nums, want in cases:
        got = Solution().majorityElement(nums)
        print("ok  " if got == want else "FAIL", nums, "->", got, "(want", str(want) + ")")
