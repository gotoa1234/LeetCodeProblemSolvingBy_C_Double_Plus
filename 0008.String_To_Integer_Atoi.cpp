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
        /// 思路：預處理空白 => 處理 +,- => 每個字元開始計算，若非數字則跳出，並且做 int 溢位處理(-2^32 ~ 2^32)
        ///      Runtime : 3 ms, faster than 82.92% of C++ online submissions for String to Integer(atoi).
        /// Memory Usage : 7 MB,   less than 89.40% of C++ online submissions for String to Integer(atoi).
        /// </summary>
        int myAtoi(string s) {
            int result = 0;

            //清除空白
            for (; s[0] == ' ';)
                s.erase(s.begin());
            int sign = 1;

            //+ - 處理
            if (s[0] == '+' || s[0] == '-')
            {
                sign = s[0] == '-' ? -1 : 1;
                s.erase(s.begin());
            }

            //字元計算
            for (int index = 0; index < s.size(); index++)
            {
                if (!isdigit(s[index]))
                    break;
                //C++溢位處理
                if (result > (INT_MAX - s[index] + 48) / 10)
                {
                    return sign == -1 ? INT_MIN : INT_MAX;
                }
                result = result * 10 + (s[index] - 48);
            }
            return sign * result;
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
            result.s = "42";
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