#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution140
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0140.Word_Break_II.cpp"
    using namespace Solution140;

    int main()
    {
        Solution140::Word_Break_II useClass;
        Solution140::Word_Break_II::Word_Break_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);

        getTestModel = useClass.GetTestData002();
        auto result3 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ¤Àµü2
    /// </summary>
    class Word_Break_II
    {
#pragma region Model
    public:
        class Word_Break_II_Model
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
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Word_Break_II_Model GetTestData001(void)
        {
            Word_Break_II_Model result;
            result.s = "catsanddog";
            result.wordDict = {"cat", "cats", "and", "sand", "dog"};
            return result;//expect:  ["cats and dog","cat sand dog"]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Word_Break_II_Model GetTestData002(void)
        {
            Word_Break_II_Model result;
            result.s = "pineapplepenapple";
            result.wordDict = { "apple","pen","applepen","pine","pineapple" };
            return result;//expect: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Word_Break_II_Model GetTestData003(void)
        {
            Word_Break_II_Model result;
            result.s = "catsandog";
            result.wordDict = { "cats","dog","sand","and","cat" };
            return result;//expect: []
        };

#pragma endregion TestData
    };
}