#include <vector>
#include "0008.String_To_Integer_Atoi.cpp"
using namespace Solution8;
using namespace std;

int main()
{
    Solution8::String_To_Integer_Atoi useClass;
    Solution8::String_To_Integer_Atoi::String_To_Integer_Atoi_Model getTestModel = useClass.GetTestData003();
    int temp = INT_MIN;
    int temp2 = INT_MAX;
    getTestModel.s = "21474836460";
    int result = useClass.myAtoi(getTestModel.s);
    getTestModel.s = "2147483646";//exp :2147483646
    result = useClass.myAtoi(getTestModel.s);
    getTestModel.s = "-2147483647";//exp : -2147483647
    result = useClass.myAtoi(getTestModel.s);
    getTestModel.s = "-91283472332";//
    result = useClass.myAtoi(getTestModel.s);
    getTestModel.s = "42";//exp :2147483646
    result = useClass.myAtoi(getTestModel.s);
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