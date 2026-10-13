# LeetCode

Solutions to the [Top Interview 150](https://leetcode.com/studyplan/top-interview-150/) study plan, in C, C++, Java and Python.

**Progress: 13 / 150**

## Solutions

| # | Problem | Difficulty | Language | Approach |
|---|---------|------------|----------|----------|
| 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | Medium | [C++](012_integer_to_roman.cpp) | Greedy over a value table |
| 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | Easy | [Python](013_roman_to_integer.py) | Left-to-right scan with lookahead |
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | Easy | [C++](014_longest_common_prefix.cpp) | Shrinking prefix |
| 28 | [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) | Easy | [Java](028_find_index_of_first_occurrence.java) | KMP |
| 55 | [Jump Game](https://leetcode.com/problems/jump-game/) | Medium | [C++](055_jump_game.cpp) | Greedy, backwards |
| 58 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word/) | Easy | [Python](058_length_of_last_word.py) | Scan from the end |
| 80 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | Medium | [C](080_remove_duplicates_ii.c) | Two pointers |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | Easy | [C++](121_best_time_to_buy_and_sell_stock.cpp) | Running minimum |
| 122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | Medium | [Java](122_best_time_to_buy_and_sell_stock_ii.java) | Greedy, sum of rises |
| 134 | [Gas Station](https://leetcode.com/problems/gas-station/) | Medium | [C++](134_gas_station.cpp) | Greedy, one pass |
| 151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) | Medium | [C++](151_reverse_words_in_a_string.cpp) | Scan from the end |
| 189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | Medium | [Java](189_rotate_array.java) | Three reversals |
| 238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | Medium | [Java](238_product_of_array_except_self.java) | Prefix and suffix products |

## Running

Each file holds a problem summary, the solution as submitted to LeetCode, and a small set of test cases. Run one by problem number:

```sh
./run.sh 055
```

`run.sh` picks the compiler from the file extension. It needs a C/C++ compiler, `python3`, and a JDK for the Java files.
