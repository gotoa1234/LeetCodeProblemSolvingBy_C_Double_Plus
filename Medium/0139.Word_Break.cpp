#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution139
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0139.Word_Break.cpp"
    using namespace Solution139;

    int main()
    {
        Solution139::Word_Break useClass;
        Solution139::Word_Break::Word_Break_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ¤Àµü
    /// </summary>
    class Word_Break
    {
#pragma region Model
    public:
        class Word_Break_Model
        {
        public:
            string s;
            vector<string> wordDict;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>        
        bool wordBreak(string s, vector<string>& wordDict) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Word_Break_Model GetTestData001(void)
        {
            Word_Break_Model result;
            result.s = "leetcode";
            result.wordDict = { "leet","code" };
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Word_Break_Model GetTestData002(void)
        {
            Word_Break_Model result;
            result.s = "applepenapple";
            result.wordDict = { "apple","pen" };
            return result;//expect: true
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Word_Break_Model GetTestData003(void)
        {
            Word_Break_Model result;
            result.s = "catsandog";
            result.wordDict = { "cats","dog","sand","and","cat" };
            return result;//expect: false
        };

#pragma endregion TestData
    };
}