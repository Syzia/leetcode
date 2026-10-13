"""
13. Roman to Integer (Easy) -- Top Interview 150, Array / String

Convert a valid Roman numeral (1 to 3999) to an integer. Symbols are
I=1, V=5, X=10, L=50, C=100, D=500, M=1000. A smaller symbol written before
a larger one is subtracted: IV=4, IX=9, XL=40, XC=90, CD=400, CM=900.

    "III"      ->  3
    "LVIII"    ->  58
    "MCMXCIV"  ->  1994

Approach: scan left to right. If the next symbol is larger than the current
one, add their difference and skip both; otherwise add the current value.
O(n) time, O(1) space.
"""


class Solution:
    def romanToInt(self, s: str) -> int:
        symbol_map = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

        # Número que queremos devolver
        number = 0

        i = 0
        while i < len(s):
            # Comparamos si el siguiente es mayor que el actual
            if i + 1 < len(s) and symbol_map[s[i+1]] - symbol_map[s[i]] > 0:
                valor = symbol_map[s[i+1]] - symbol_map[s[i]]
                number += valor
                # Avanzamos al siguiente número
                i += 1
            else:
                # El siguiente es menor que el actual, sumamos el valor de este
                number += symbol_map[s[i]]

            # Siguiente índice
            i += 1

        return number


if __name__ == "__main__":
    cases = [
        ("III", 3),
        ("LVIII", 58),
        ("MCMXCIV", 1994),
        ("I", 1),
        ("IV", 4),
        ("IX", 9),
        ("XIV", 14),
        ("CDXLIV", 444),
        ("MMXXIV", 2024),
        ("MMMDCCCLXXXVIII", 3888),
        ("MMMCMXCIX", 3999),
    ]
    for s, want in cases:
        got = Solution().romanToInt(s)
        print("ok  " if got == want else "FAIL", repr(s), "->", got, "(want", str(want) + ")")
