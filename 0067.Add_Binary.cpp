#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution67
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0067.Add_Binary.cpp"
    using namespace Solution67;

    int main()
    {
        Solution67::Add_Binary useClass;
        Solution67::Add_Binary::Add_Binary_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.addBinary(getTestModel.a, getTestModel.b);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.addBinary(getTestModel.a, getTestModel.b);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.addBinary(getTestModel.a, getTestModel.b);

        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 增加二進位
    /// </summary>
    class Add_Binary
    {
#pragma region Model
    public:
        class Add_Binary_Model
        {
        public:
            string a;
            string b;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：
        ///      Runtime : 
        /// Memory Usage : 
        /// <returns></returns>
        string addBinary(string a, string b) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Add_Binary_Model GetTestData001(void)
        {
            Add_Binary_Model result;
            result.a = "11";
            result.b = "1";
            return result;//expected = "100"
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Add_Binary_Model GetTestData002(void)
        {
            Add_Binary_Model result;
            result.a = "1010";
            result.b = "1011";
            return result;//expected = "10101"
        };
#pragma endregion TestData
    };
}