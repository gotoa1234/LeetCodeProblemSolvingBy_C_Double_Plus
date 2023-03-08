#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution131
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0131.Palindrome_Partitioning.cpp"
    using namespace Solution131;

    int main()
    {
        Solution131::Palindrome_Partitioning useClass;
        Solution131::Palindrome_Partitioning::Palindrome_Partitioning_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.solve(getTestModel.s);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.solve(getTestModel.s);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 回文劃分
    /// </summary>
    class Palindrome_Partitioning
    {
#pragma region Model
    public:
        class Palindrome_Partitioning_Model
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
        vector<vector<string>> partition(string s) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Palindrome_Partitioning_Model GetTestData001(void)
        {
            Palindrome_Partitioning_Model result;
            result.s = "aab";
            return result;//expect: [["a","a","b"],["aa","b"]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Palindrome_Partitioning_Model GetTestData002(void)
        {
            Palindrome_Partitioning_Model result;
            result.s = "a";
            return result;//expect: [["a"]]
        };

#pragma endregion TestData
    };
}