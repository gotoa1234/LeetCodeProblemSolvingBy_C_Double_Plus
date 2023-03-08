#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution132
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0132.Palindrome_Partitioning_II.cpp"
    using namespace Solution132;

    int main()
    {
        Solution132::Palindrome_Partitioning_II useClass;
        Solution132::Palindrome_Partitioning_II::Palindrome_Partitioning_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.solve(getTestModel.s);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.solve(getTestModel.s);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.solve(getTestModel.s);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 回文劃分2
    /// </summary>
    class Palindrome_Partitioning_II
    {
#pragma region Model
    public:
        class Palindrome_Partitioning_II_Model
        {
        public:
            string s;
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
        int minCut(string s) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Palindrome_Partitioning_II_Model GetTestData001(void)
        {
            Palindrome_Partitioning_II_Model result;
            result.s = "aab";
            return result;//expect: 1
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Palindrome_Partitioning_II_Model GetTestData002(void)
        {
            Palindrome_Partitioning_II_Model result;
            result.s = "a";
            return result;//expect: 0
        };
        
        /// <summary>
        /// test 3
        /// </summary>   
        Palindrome_Partitioning_II_Model GetTestData003(void)
        {
            Palindrome_Partitioning_II_Model result;
            result.s = "ab";
            return result;//expect: 1
        };
#pragma endregion TestData
    };
}