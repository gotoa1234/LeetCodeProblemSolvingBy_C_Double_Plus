#include <vector>
#include "0005_Longest_Palindromic_Substring.cpp"
#include "0006.Zigzag_Conversion.cpp"
#include "0007.Reverse_Integer.cpp"
using namespace Solution7;
using namespace Solution5;
using namespace Solution6;
using namespace std;

int main()
{
    //Solution5::Longest_Palindromic_Substring useClass;
    //Solution5::Longest_Palindromic_Substring::Longest_Palindromic_Substring_Model getTestModel = useClass.GetTestData001();
    //string result = useClass.longestPalindrome(getTestModel.s);


    Solution7::Reverse_Integer useClass;
    Solution7::Reverse_Integer::Reverse_Integer_Model getTestModel = useClass.GetTestData001();
    int result = useClass.reverse(getTestModel.x);
    return 0;
}

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int st{}, stmax{};
        int mx{};
        for (int i{}; i < n; i++) {
            st = i;
            while (i < n && st >= 0 && s[i] == s[st]) {
                i++;
            }
            i--;
            int j{};
            while (i + j < n && st - j >= 0 && s[i + j] == s[st - j]) {
                j++;
            }
            j--;
            if (mx < (i - st + 2 * j + 1)) {
                mx = i - st + 2 * j + 1;
                stmax = st - j;
            }
        }
        return s.substr(stmax, mx);
    }
};