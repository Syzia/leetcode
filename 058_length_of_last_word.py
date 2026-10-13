"""
58. Length of Last Word (Easy) -- Top Interview 150, Array / String

Given a string s of words and spaces, return the length of the last word.
A word is a maximal run of non-space characters.

    "Hello World"                  ->  5   ("World")
    "   fly me   to   the moon  "  ->  4   ("moon")
    "luffy is still joyboy"        ->  6   ("joyboy")

Approach: walk back past the trailing spaces, then count characters until
the next space or the start of the string. O(n) time.
"""


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ans = 0
        n = len(s) - 1

        # Skip trailing spaces
        while s[n] == " ":
            n -= 1

        # Count characters of the last word backward
        for ch in s[n::-1]:
            if ch == " ":
                break
            ans += 1

        return ans


if __name__ == "__main__":
    cases = [
        ("Hello World", 5),
        ("   fly me   to   the moon  ", 4),
        ("luffy is still joyboy", 6),
        ("a", 1),
        ("a ", 1),
        (" a", 1),
        ("word", 4),
        ("day   ", 3),
    ]
    for s, want in cases:
        got = Solution().lengthOfLastWord(s)
        print("ok  " if got == want else "FAIL", repr(s), "->", got, "(want", str(want) + ")")
