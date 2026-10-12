"""
88. Merge Sorted Array (Easy) -- Top Interview 150, Array / String #1

nums1 and nums2 are sorted ascending. nums1 has length m + n: its first m
entries are real values and the last n are 0 placeholders. Merge nums2 into
nums1 in place so nums1 ends up sorted. Return nothing.

    nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3  ->  [1,2,2,3,5,6]
    nums1 = [1], m = 1, nums2 = [], n = 0                 ->  [1]
    nums1 = [0], m = 0, nums2 = [1], n = 1                ->  [1]

Follow-up: O(m + n) time, O(1) extra space.
"""
from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        pass


if __name__ == "__main__":
    cases = [
        ([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3, [1, 2, 2, 3, 5, 6]),
        ([1], 1, [], 0, [1]),
        ([0], 0, [1], 1, [1]),
        ([4, 5, 6, 0, 0, 0], 3, [1, 2, 3], 3, [1, 2, 3, 4, 5, 6]),
        ([2, 0], 1, [1], 1, [1, 2]),
    ]
    for nums1, m, nums2, n, want in cases:
        shown = list(nums1)
        Solution().merge(nums1, m, nums2, n)
        print("ok  " if nums1 == want else "FAIL", shown, nums2, "->", nums1, "(want", str(want) + ")")
