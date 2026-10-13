/*
28. Find the Index of the First Occurrence in a String (Easy) -- Top Interview 150, Array / String

Given two strings needle and haystack, return the index of the first
occurrence of needle in haystack, or -1 if needle is not part of haystack.

    haystack = "sadbutsad", needle = "sad"   ->  0
    haystack = "leetcode", needle = "leeto"  ->  -1

Approach: KMP. Build the longest-prefix-suffix table for needle, then scan
haystack without ever moving backwards in it. O(n + m) time, O(m) space.
*/
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) return 0;
        if (haystack.length() < needle.length()) return -1;

        int[] lps = new int[needle.length()];
        int prevLPS = 0;
        int i = 1;

        while (i < needle.length()) {
            if (needle.charAt(i) == needle.charAt(prevLPS)) {
                prevLPS++;
                lps[i] = prevLPS;
                i++;
            } else {
                if (prevLPS != 0) {
                    prevLPS = lps[prevLPS - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        i = 0;
        int j = 0;
        while (i < haystack.length()) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
                if (j == needle.length()) {
                    return i - j;
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
}

class Main {
    public static void main(String[] args) {
        Object[][] cases = {
            {"sadbutsad", "sad", 0},
            {"leetcode", "leeto", -1},
            {"a", "a", 0},
            {"hello", "ll", 2},
            {"aaaaab", "aab", 3},
            {"mississippi", "issip", 4},
            {"aabaaabaaac", "aabaaac", 4},
            {"abc", "abcd", -1},
        };
        for (Object[] c : cases) {
            int got = new Solution().strStr((String) c[0], (String) c[1]);
            System.out.println((got == (int) c[2] ? "ok   " : "FAIL ")
                + "\"" + c[0] + "\" \"" + c[1] + "\" -> " + got + " (want " + c[2] + ")");
        }
    }
}
