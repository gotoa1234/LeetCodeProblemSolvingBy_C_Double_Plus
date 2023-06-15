#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution165
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0165.Compare_Version_Numbers.cpp"
    using namespace Solution165;

    int main()
    {
        Solution165::Compare_Version_Numbers useClass;
        Solution165::Compare_Version_Numbers::Compare_Version_Numbers_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.compareVersion(getTestModel.version1, getTestModel.version2);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.compareVersion(getTestModel.version1, getTestModel.version2);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 比較版本號
    /// </summary>
    class Compare_Version_Numbers
    {
#pragma region Model
    public:
        class Compare_Version_Numbers_Model
        {
        public:
            string version1;
            string version2;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路：         
        ///      Runtime：
        /// Memory Usage：
        /// </summary>
        /// <returns></returns>
    public:
        int compareVersion(string version1, string version2) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Compare_Version_Numbers_Model GetTestData001(void)
        {
            Compare_Version_Numbers_Model result;
            result.version1 = "1.01";
            result.version2 = "1.001";
            return result;//expect: 0
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Compare_Version_Numbers_Model GetTestData002(void)
        {
            Compare_Version_Numbers_Model result;
            result.version1 = "1.0";
            result.version2 = "1.0.0";
            return result;//expect: 0           
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Compare_Version_Numbers_Model GetTestData003(void)
        {
            Compare_Version_Numbers_Model result;
            result.version1 = "0.1";
            result.version2 = "1.1";
            return result;//expect: -1
        };

#pragma endregion TestData
    };
}