#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution8
{
#pragma region Paste to execute 
    /*
    #include "0008.String_To_Integer_Atoi.cpp"
    using namespace Solution8;
    using namespace std;

    Solution8::String_To_Integer_Atoi useClass;
    Solution8::String_To_Integer_Atoi::String_To_Integer_Atoi_Model getTestModel = useClass.GetTestData001();
    int result = useClass.myAtoi(getTestModel.s);
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 字串轉整數: 給定一字串，取出遇到的第一組數字轉型
    /// ※只支援32bit的整數 int 型態，若反轉時溢位返回0
    /// </summary>
    class String_To_Integer_Atoi
    {
#pragma region Model
    public:
        class String_To_Integer_Atoi_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        /// 思路：
        ///      Runtim e:   0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
        /// Memory Usage : 5.9 MB,   less than 76.34 % of C++ online submissions for Reverse Integer.
        /// </summary>
        int myAtoi(string s) {
            int result = 0;
            int startIndex = 0;
            int sign = 1;
            unordered_map<char, int> hashMap;
            hashMap[' '] = 1;
            hashMap['-'] = 1;
            hashMap['+'] = 1;
            hashMap['0'] = 1;
            hashMap['1'] = 1;
            hashMap['2'] = 1;
            hashMap['3'] = 1;
            hashMap['4'] = 1;
            hashMap['5'] = 1;
            hashMap['6'] = 1;
            hashMap['7'] = 1;
            hashMap['8'] = 1;
            hashMap['9'] = 1;
        
            for (int Index = 0; Index < s.size(); Index++)
            {
                if (hashMap.find(s[Index]) == hashMap.end())
                {
                    return 0;
                }
                if (s[Index] == ' ')
                {
                    continue;
                }
                if (s[Index] == '-')
                {
                    sign = -1;
                    startIndex = Index + 1;
                }
                else if (s[Index] == '+')
                {
                    startIndex = Index + 1;
                }
                else
                {
                    startIndex = Index;
                }
                break;
            }

            hashMap.erase(' ');
            hashMap.erase('-');
            hashMap.erase('+');
            for (int Index = startIndex; Index < s.size(); Index++)
            {
                if (hashMap.find(s[Index]) == hashMap.end())
                {
                    break;
                }
                if (result * 10 + (s[Index] - 48) * sign > INT_MAX/10 || result * 10 + (s[Index] - 48) * sign < INT_MIN/10)
                {
                    return sign == -1 ? INT_MIN : INT_MAX;
                }
                result = result * 10 + (s[Index] - 48);
            }

            result = result * sign;

            return result;
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        String_To_Integer_Atoi_Model GetTestData001(void)
        {
            String_To_Integer_Atoi_Model result;
            //result.s = "2147483646";//exp :2147483646
            //result.s = "-2147483647";//exp : -2147483647
            result.s = "-91283472332";//
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        String_To_Integer_Atoi_Model GetTestData002(void)
        {
            String_To_Integer_Atoi_Model result;
            result.s = "   -42";
            return result;
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        String_To_Integer_Atoi_Model GetTestData003(void)
        {
            String_To_Integer_Atoi_Model result;
            result.s = "4193 with words";
            return result;
        };
#pragma endregion TestData
    };
}