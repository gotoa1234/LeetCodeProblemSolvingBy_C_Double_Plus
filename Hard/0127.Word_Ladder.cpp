#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution127
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0127.Word_Ladder.cpp"
    using namespace Solution127;

    int main()
    {
        Solution127::Word_Ladder useClass;
        Solution127::Word_Ladder::Word_Ladder_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.findLadders(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.findLadders(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.findLadders(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ¦r±è
    /// </summary>
    class Word_Ladder
    {
#pragma region Model
    public:
        class Word_Ladder_Model
        {
        public:
            string beginWord;
            string endWord;
            vector<string> wordList;

        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         «ä¸ô ¡G
        ///                
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            return {};
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Word_Ladder_Model GetTestData001(void)
        {
            Word_Ladder_Model result;
            result.beginWord = "hit";
            result.endWord = "cog";
            result.wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
            return result;//expect: 5
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Word_Ladder_Model GetTestData002(void)
        {
            Word_Ladder_Model result;
            result.beginWord = "hit";
            result.endWord = "cog";
            result.wordList = { "hot", "dot", "dog", "lot", "log" };
            return result;//expect:0
        };

#pragma endregion TestData
    };
}