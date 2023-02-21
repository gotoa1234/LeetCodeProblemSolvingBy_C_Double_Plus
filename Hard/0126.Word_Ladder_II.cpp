#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution126
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0126.Word_Ladder_II.cpp"
    using namespace Solution126;

    int main()
    {
        Solution126::Word_Ladder_II useClass;
        Solution126::Word_Ladder_II::Word_Ladder_II_Model getTestModel = useClass.GetTestData001();
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
    /// ¦r±è¤G
    /// </summary>
    class Word_Ladder_II
    {
#pragma region Model
    public:
        class Word_Ladder_II_Model
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
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            return {};
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Word_Ladder_II_Model GetTestData001(void)
        {
            Word_Ladder_II_Model result;
            result.beginWord = "hit";
            result.endWord = "cog";
            result.wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
            return result;//expect: [["hit", "hot", "dot", "dog", "cog"], ["hit", "hot", "lot", "log", "cog"]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Word_Ladder_II_Model GetTestData002(void)
        {
            Word_Ladder_II_Model result;
            result.beginWord = "hit";
            result.endWord = "cog";
            result.wordList = { "hot", "dot", "dog", "lot", "log"};
            return result;//expect:[]
        };

#pragma endregion TestData
    };
}