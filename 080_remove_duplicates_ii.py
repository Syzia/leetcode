"""
80. Remove Duplicates from Sorted Array II (Medium) -- Top Interview 150, Array / String #4

nums is sorted ascending. Remove duplicates in place so each value appears
at most twice, keeping relative order. Return k, the new length; the first
k slots of nums must hold the result. O(1) extra space.

    nums = [1,1,1,2,2,3]        ->  k = 5, nums[:5] = [1,1,2,2,3]
    nums = [0,0,1,1,1,1,2,3,3]  ->  k = 7, nums[:7] = [0,0,1,1,2,3,3]
"""
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        pass


if __name__ == "__main__":
    cases = [
        ([1, 1, 1, 2, 2, 3], [1, 1, 2, 2, 3]),
        ([0, 0, 1, 1, 1, 1, 2, 3, 3], [0, 0, 1, 1, 2, 3, 3]),
        ([1], [1]),
        ([1, 1], [1, 1]),
        ([5, 5, 5, 5, 5], [5, 5]),
        ([1, 2, 3], [1, 2, 3]),
    ]
    for nums, want in cases:
        shown = list(nums)
        k = Solution().removeDuplicates(nums)
        got = nums[:k] if isinstance(k, int) else None
        print("ok  " if got == want else "FAIL", shown, "->", k, got, "(want", str(want) + ")")
