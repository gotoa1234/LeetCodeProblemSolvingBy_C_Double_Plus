#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution168
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Easy/0168.Excel_Sheet_Column_Title.cpp"
    using namespace Solution168;

    int main()
    {
        Solution168::Excel_Sheet_Column_Title useClass;
        Solution168::Excel_Sheet_Column_Title::Excel_Sheet_Column_Title_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.convertToTitle(getTestModel.columnNumber);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.convertToTitle(getTestModel.columnNumber);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.convertToTitle(getTestModel.columnNumber);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// Excel 工作表列標題
    /// </summary>
    class Excel_Sheet_Column_Title
    {
#pragma region Model
    public:
        class Excel_Sheet_Column_Title_Model
        {
        public:
           int columnNumber;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：要把這題轉為26進位思維
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 5.9 MB Beats 79.23 %
        /// </summary>
        /// <returns></returns>        
        string convertToTitle(int columnNumber) {
            string result;
            while (columnNumber != 0)
            {
                if (columnNumber % 26 == 0)
                {
                    result.push_back('Z');
                    columnNumber -= 26;
                }
                else
                {
					result.push_back((columnNumber % 26) + 64);
					columnNumber -= columnNumber % 26;
                }
                columnNumber /= 26;
            }
            reverse(result.begin(), result.end());
            return result;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Excel_Sheet_Column_Title_Model GetTestData001(void)
        {
            Excel_Sheet_Column_Title_Model result;
            result.columnNumber = 1;
            return result;//expect:  A
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Excel_Sheet_Column_Title_Model GetTestData002(void)
        {
            Excel_Sheet_Column_Title_Model result;
            result.columnNumber = 702;
            return result;//expect:  AB
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Excel_Sheet_Column_Title_Model GetTestData003(void)
        {
            Excel_Sheet_Column_Title_Model result;
            result.columnNumber = 701;
            return result;//expect:  ZY
        };

#pragma endregion TestData
    };
}