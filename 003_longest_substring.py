"""
3. Longest Substring Without Repeating Characters (Medium)

Given a string s, return the length of the longest substring
that contains no repeated characters.

    "abcabcbb" -> 3   ("abc")
    "bbbbb"    -> 1   ("b")
    "pwwkew"   -> 3   ("wke")

Constraints: 0 <= len(s) <= 5 * 10^4; s is letters, digits, symbols, spaces.
"""


def length_of_longest_substring(s: str) -> int:
    pass


if __name__ == "__main__":
    cases = [
        ("abcabcbb", 3),
        ("bbbbb", 1),
        ("pwwkew", 3),
        ("", 0),
        (" ", 1),
        ("dvdf", 3),
        ("abba", 2),
        ("tmmzuxt", 5),
    ]
    for s, want in cases:
        got = length_of_longest_substring(s)
        print("ok  " if got == want else "FAIL", repr(s), "->", got, "(want", str(want) + ")")
