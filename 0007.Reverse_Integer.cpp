#include <iostream>
#include <vector>
using namespace std;

namespace Solution7
{
#pragma region Paste to execute 
    /*
    #include "0007.Reverse_Integer.cpp"
    using namespace Solution7;
    using namespace std;

    Solution7::Reverse_Integer useClass;
    Solution7::Reverse_Integer::Reverse_Integer_Model getTestModel = useClass.GetTestData001();
    int result = useClass.reverse(getTestModel.x);
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 倒轉整數 - 給予1個32bit的整數。返回相反的整數值 EX: 輸入123 返回321 
    /// ※只支援32bit的整數 int 型態，若反轉時溢位返回0
    /// </summary>
    class Reverse_Integer
    {
#pragma region Model
    public:
        class Reverse_Integer_Model
        {
        public:
            int x;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        /// 思路：迴圈執行，將輸入的數值%10取餘數，並且輸入的值/10 後進入下一迴圈 * 10 運算
        ///     EX: Input = 102 
        /// STEP 1: 102 % 10 => 取得 2 放入"結果"  102/10  =>取得10
        /// STEP 2: 結果 (2 * 10) + (10 % 10) = 第二層結果 20   10 /10 => 取得1
        /// STEP 3: 結果 (20 * 10) + (1 % 10) = 第三層結果，也是反轉結果
        ///      Runtim e:   0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
        /// Memory Usage : 5.9 MB,   less than 76.34 % of C++ online submissions for Reverse Integer.
        /// </summary>
        int reverse(int x) {
            int result = 0;
            int remainder = 0;
            while (x)
            {
                if (result > INT_MAX / 10 || result < INT_MIN / 10)
                {
                    return 0;
                }
                remainder = x % 10;
                result = result * 10 + remainder;
                x = x / 10;
            }
            return result;
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Reverse_Integer_Model GetTestData001(void)
        {
            Reverse_Integer_Model result;
            result.x = 123;

            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Reverse_Integer_Model GetTestData002(void)
        {
            Reverse_Integer_Model result;
            result.x = -123;
            return result;
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Reverse_Integer_Model GetTestData003(void)
        {
            Reverse_Integer_Model result;
            result.x = 120;
            return result;
        };
#pragma endregion TestData
    };
}