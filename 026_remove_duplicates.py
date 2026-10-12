"""
26. Remove Duplicates from Sorted Array (Easy) -- Top Interview 150, Array / String #3

nums is sorted ascending. Remove duplicates in place so each value appears
once, keeping relative order. Return k, the number of unique values; the
first k slots of nums must hold them. Anything after index k is ignored.

    nums = [1,1,2]                ->  k = 2, nums[:2] = [1,2]
    nums = [0,0,1,1,1,2,2,3,3,4]  ->  k = 5, nums[:5] = [0,1,2,3,4]
"""
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        pass


if __name__ == "__main__":
    cases = [
        ([1, 1, 2], [1, 2]),
        ([0, 0, 1, 1, 1, 2, 2, 3, 3, 4], [0, 1, 2, 3, 4]),
        ([1], [1]),
        ([2, 2, 2, 2], [2]),
        ([1, 2, 3], [1, 2, 3]),
    ]
    for nums, want in cases:
        shown = list(nums)
        k = Solution().removeDuplicates(nums)
        got = nums[:k] if isinstance(k, int) else None
        print("ok  " if got == want else "FAIL", shown, "->", k, got, "(want", str(want) + ")")
