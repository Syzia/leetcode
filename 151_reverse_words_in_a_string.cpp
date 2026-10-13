/*
151. Reverse Words in a String (Medium) -- Top Interview 150, Array / String

Given a string s, reverse the order of the words. Words are runs of
non-space characters. s may have leading, trailing, or repeated spaces; the
result must have exactly one space between words and none at the ends.

    "the sky is blue"   ->  "blue is sky the"
    "  hello world  "   ->  "world hello"
    "a good   example"  ->  "example good a"

Approach: scan from the back, counting the length of the current word, and
append each word to the answer when the space before it is reached. A space
is prepended to s so the first word is flushed the same way as the rest.
O(n) time, O(n) space.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s=" "+s;
        string ans="";
        int n=s.size(),k=n-1,c=0,a=n-1,cs=0;


        while(k>=0){
            if(s[a]==' '){a--,k--;continue;}
            if(s[k] != ' ') c++,k--,cs=0;

            else{
                cs++;
                if(cs>1){k--;continue;}
                string ss=s.substr(k+1,c);
                ans+=ss+' ';
                c=0;
            }
        }
        ans.pop_back();
        return ans;
    }
};

int main() {
    struct Case { string s; string want; };
    vector<Case> cases = {
        {"the sky is blue", "blue is sky the"},
        {"  hello world  ", "world hello"},
        {"a good   example", "example good a"},
        {"a", "a"},
        {"   a   ", "a"},
        {"ab  cd", "cd ab"},
        {"EPY2giL aLbl3 x9", "x9 aLbl3 EPY2giL"},
        {" one", "one"},
        {"one ", "one"},
    };
    for (auto& c : cases) {
        string got = Solution().reverseWords(c.s);
        cout << (got == c.want ? "ok   " : "FAIL ");
        cout << "\"" << c.s << "\" -> \"" << got << "\" (want \"" << c.want << "\")\n";
    }
}
