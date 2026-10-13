/*
134. Gas Station (Medium) -- Top Interview 150, Array / String

n gas stations sit on a circular route. Station i has gas[i] fuel, and it
costs cost[i] to drive from station i to station i + 1. Starting with an
empty tank, return the index of the station from which you can complete
one full clockwise loop, or -1 if no such station exists. The answer, if
any, is unique.

    gas = [1,2,3,4,5], cost = [3,4,5,1,2]  ->  3
    gas = [2,3,4], cost = [3,4,3]          ->  -1

Approach: greedy, one pass. Track the running balance from the current
candidate start. When it goes negative, no station in that stretch can be
the start, so bank the shortfall as deficit and restart from the next
station. A loop is possible only if the final balance covers the deficit.
O(n) time, O(1) space.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = cost.size(), bal = 0, start = 0, deficit = 0;

        for(int i = 0; i< n; i++){
            bal += gas[i] - cost[i];

            if(bal < 0){

                deficit += bal;
                start = i+1;
                bal = 0;
            }
        }
        return bal + deficit >= 0 ? start : -1;
    }
};

void show(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Case { vector<int> gas; vector<int> cost; int want; };
    vector<Case> cases = {
        {{1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 3},
        {{2, 3, 4}, {3, 4, 3}, -1},
        {{5}, {4}, 0},
        {{2}, {3}, -1},
        {{5, 1, 2, 3, 4}, {4, 4, 1, 5, 1}, 4},
        {{3, 1, 1}, {1, 2, 2}, 0},
        {{1, 2}, {2, 1}, 1},
        {{0, 0, 5}, {1, 1, 1}, 2},
    };
    for (auto& c : cases) {
        int got = Solution().canCompleteCircuit(c.gas, c.cost);
        cout << (got == c.want ? "ok   " : "FAIL ");
        show(c.gas); cout << " "; show(c.cost);
        cout << " -> " << got << " (want " << c.want << ")\n";
    }
}
