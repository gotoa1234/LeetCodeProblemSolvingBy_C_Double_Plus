#include <iostream>
#include <vector>
using namespace std;

namespace Solution6
{
#pragma region Paste to execute 
    /*
    #include "0006.Zigzag_Conversion.cpp"
    #include <vector>
    using namespace Solution6;
    using namespace std;

    Solution6::convert useClass;
    Solution6::convert::Zigzag_Conversion_Model getTestModel = useClass.GetTestData001();
    string result = useClass.convert(getTestModel.s, getTestModel.numRows);
    */
#pragma endregion Paste to execute

    /// <summary>
    /// Z字形轉換 - 給予一個字串 + 行數 。 字串中字元排列成由上至下到指定行數，然後再反轉向上到第1行，最後由第一行 到最後一行 組成新字串
    /// </summary>
    class Zigzag_Conversion
    {
#pragma region Model
    public:
        class Zigzag_Conversion_Model
        {
        public:
            string s;
            int numRows;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        /// 思路：找出排列規則，只需遍歷一次字串，即可達成O(n) 的效能
        ///      Runtime :  14 ms, faster than 68.09 % of C++ online submissions for Zigzag Conversion.
        /// Memory Usage : 8.2 MB,   less than 81.10 % of C++ online submissions for Zigzag Conversion.
        /// </summary>
        string convert(string s, int numRows) 
        {
            if (numRows <= 1)
            {
                return s;
            }

            string result;
            // 找出週期值
            int period = 2 * numRows - 2;

            // 每行的字元
            for (int index = 0; index < numRows; index++) 
            {               
                //移動索引
                int moveIndex = index;
                //移動間格數
                int movePeriod = period - 2 * index;
                while (moveIndex < s.size()) 
                {
                    result.push_back(s[moveIndex]);
                    moveIndex += (index > 0 && index < numRows - 1) ? movePeriod : period;
                    movePeriod = period - movePeriod;
                }
            }

            return result;
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Zigzag_Conversion_Model GetTestData001(void)
        {
            Zigzag_Conversion_Model result;
            result.s = "PAYPALISHIRING";
            result.numRows = 3;

            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Zigzag_Conversion_Model GetTestData002(void)
        {
            Zigzag_Conversion_Model result;
            result.s = "PAYPALISHIRING";
            result.numRows = 4;

            return result;
        };
#pragma endregion TestData
    };
}