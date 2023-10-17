#include <iostream>
using namespace std;

namespace Solution9
{
#pragma region Paste to execute 
    /*
#include "Easy\0009.Palindrome_Number.cpp"
using namespace Solution9;
using namespace std;

int main()
{
    Solution9::Palindrome_Number useClass;
    Solution9::Palindrome_Number::Palindrome_Number_Model getTestModel = useClass.GetTestData001();
    bool result = useClass.myAtoi(getTestModel.x);
}

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 是否為回文整數
    /// ※轉成字串太簡單，LeetCode建議不用String嘗試挑戰
    /// </summary>
    class Palindrome_Number
    {
#pragma region Model
    public:
        class Palindrome_Number_Model
        {
        public:
            int x;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///          思路：排除負數/尾0 => 整數倒換 => 溢位判斷 => 最後判斷整數倒換值是否與原值相同
        ///      Runtime :  12 ms, faster than 87.84 % of C++ online submissions for Palindrome Number.
        /// Memory Usage : 5.8 MB,   less than 91.05 % of C++ online submissions for Palindrome Number.
        /// </summary>
        bool myAtoi(int x) {
            //1. 負數為false
            if (x < 0 || x % 10 == 0)
                return false;    
            //2. 個位數為回文
            if (x >= 0 && x <= 9)
                return true;

            int tmep = x;
            int result = 0;
            int remainder = 0;
            while (tmep > 0)
            {
                //3. 確保result的int值不會溢位
                remainder = tmep % 10;
                if (result > (INT_MAX - (remainder)) / 10)
                {
                    return false;
                }
                result = result * 10 + remainder;
                tmep = tmep / 10;
            }
            return result == x;
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Palindrome_Number_Model GetTestData001(void)
        {
            Palindrome_Number_Model result;
            result.x = 1234567899;//
            return result;//expect: true
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Palindrome_Number_Model GetTestData002(void)
        {
            Palindrome_Number_Model result;
            result.x = -121;
            return result;//expect: false
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Palindrome_Number_Model GetTestData003(void)
        {
            Palindrome_Number_Model result;
            result.x = 10;
            return result;//expect: false
        };
#pragma endregion TestData
    };
}