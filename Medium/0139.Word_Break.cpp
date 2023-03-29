#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
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
        ///      Runtime :   4 ms Beats 85.98 %
        /// Memory Usage : 7.9 MB Beats 85.92 %
        /// </summary>
        /// <returns></returns>        
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_map<int, unordered_map<char, unordered_set<string>>> hashTable;
            vector<bool> dp(s.size() + 1, false);
            int length;

            for (auto str : wordDict) 
            {
                hashTable[str.size()][str[0]].insert(str);
            }

            dp[0] = true;
            for (int index = 1; index <= s.size(); index++)
            {
                for (int innerIndex = 0; innerIndex < index; innerIndex++)
                {
                    if (dp[innerIndex]) 
                    {
                        length = index - innerIndex;
                        if (        hashTable.count(length) && 
                            hashTable[length].count(s[innerIndex])
                            ) 
                        {
                            auto subWord = s.substr(innerIndex, length);
                            if (hashTable[length][s[innerIndex]].count(subWord)) 
                            {
                                dp[index] = true;
                                break;
                            }
                        }
                    }
                }
            }
            return dp[s.size()];
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