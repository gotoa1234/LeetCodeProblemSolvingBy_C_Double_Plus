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
        auto result1 = useClass.singleNumber(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.singleNumber(getTestModel.nums);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.singleNumber(getTestModel.nums);
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
        ///         思路 ：
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>        
        string convertToTitle(int columnNumber) {
            return {};
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
            result.columnNumber = 28;
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