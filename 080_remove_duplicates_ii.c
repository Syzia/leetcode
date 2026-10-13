/*
80. Remove Duplicates from Sorted Array II (Medium) -- Top Interview 150, Array / String

nums is sorted ascending. Remove duplicates in place so each value appears
at most twice, keeping relative order. Return k, the new length; the first
k slots of nums must hold the result. O(1) extra space.

    nums = [1,1,1,2,2,3]        ->  k = 5, first 5 = [1,1,2,2,3]
    nums = [0,0,1,1,1,1,2,3,3]  ->  k = 7, first 7 = [0,0,1,1,2,3,3]

Approach: read pointer / write pointer. The first two elements always stay.
After that, keep nums[i] only if it differs from the value two slots back
in the kept section, since equality there means two copies are already
kept. O(n) time, O(1) space.
*/
#include <stdio.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }

    int k = 2;

    for (int i = 2; i < numsSize; i++) {

        if (nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

static void show(const int* v, int n) {
    printf("[");
    for (int i = 0; i < n; i++) printf("%s%d", i ? "," : "", v[i]);
    printf("]");
}

int main(void) {
    struct Case { int nums[16]; int n; int want[16]; int wantLen; };
    struct Case cases[] = {
        {{1, 1, 1, 2, 2, 3}, 6, {1, 1, 2, 2, 3}, 5},
        {{0, 0, 1, 1, 1, 1, 2, 3, 3}, 9, {0, 0, 1, 1, 2, 3, 3}, 7},
        {{1}, 1, {1}, 1},
        {{1, 1}, 2, {1, 1}, 2},
        {{5, 5, 5, 5, 5}, 5, {5, 5}, 2},
        {{1, 2, 3}, 3, {1, 2, 3}, 3},
        {{-3, -3, -3, 0, 0, 0, 0, 4}, 8, {-3, -3, 0, 0, 4}, 5},
    };
    int count = sizeof(cases) / sizeof(cases[0]);
    for (int t = 0; t < count; t++) {
        int nums[16];
        memcpy(nums, cases[t].nums, sizeof(nums));
        int k = removeDuplicates(nums, cases[t].n);
        int ok = k == cases[t].wantLen && memcmp(nums, cases[t].want, sizeof(int) * k) == 0;
        printf(ok ? "ok   " : "FAIL ");
        show(cases[t].nums, cases[t].n);
        printf(" -> k=%d ", k);
        if (k >= 0 && k <= cases[t].n) show(nums, k);
        printf(" (want ");
        show(cases[t].want, cases[t].wantLen);
        printf(")\n");
    }
    return 0;
}
