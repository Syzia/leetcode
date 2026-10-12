"""
27. Remove Element (Easy) -- Top Interview 150, Array / String #2

Remove every occurrence of val from nums in place. Return k, the number of
elements that are not val. The first k slots of nums must hold those
elements (any order); whatever sits after index k is ignored.

    nums = [3,2,2,3], val = 3          ->  k = 2, nums[:2] = [2,2]
    nums = [0,1,2,2,3,0,4,2], val = 2  ->  k = 5, nums[:5] = [0,1,3,0,4]
"""
from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        pass


if __name__ == "__main__":
    cases = [
        ([3, 2, 2, 3], 3, [2, 2]),
        ([0, 1, 2, 2, 3, 0, 4, 2], 2, [0, 0, 1, 3, 4]),
        ([], 1, []),
        ([1], 1, []),
        ([4, 5], 7, [4, 5]),
    ]
    for nums, val, want in cases:
        shown = list(nums)
        k = Solution().removeElement(nums, val)
        got = sorted(nums[:k]) if isinstance(k, int) else None
        print("ok  " if got == want else "FAIL", shown, val, "->", k, got, "(want", str(want) + ")")
