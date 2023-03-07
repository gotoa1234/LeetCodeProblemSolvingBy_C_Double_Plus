#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <queue>
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
        auto result1 = useClass.ladderLength(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.ladderLength(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.ladderLength(getTestModel.beginWord, getTestModel.endWord, getTestModel.wordList);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 字梯
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
        ///         思路 ：給定一個 beginWord 起始字串，目標是只替換兩個詞可以到endWord，其中beginWord可以用wordList替換
        ///                1. 利用一個queue將潛在符合的字詞放入 (剛開始必定是beginWord)
        ///                2. 利用HashTable 將 wordList 的詞全部放進，每次比對時加快速度
        ///                3. 每次取出一個queue的項目比對是否符合 endWord
        ///                4. 不符合則產生潛在的字詞，然後重複1-4步驟，直到3.符合endWord出現
        ///                5. 上述都不合則為0
        ///      Runtime :   82 ms Beats 93.43 %
        /// Memory Usage : 13.8 MB Beats 88.94 %
        /// </summary>
        /// <returns></returns>
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
        {
            unordered_set<string> hashTable(wordList.begin(), wordList.end());
            if (false == hashTable.count(endWord))
                return 0;
            queue<string> queueTemp;
            queueTemp.push(beginWord);
            int resultCount = 0;
            while (queueTemp.empty() == false)
            {
                for (int queueCount = queueTemp.size(); queueCount > 0; queueCount--)
                {
                    string compareWord = queueTemp.front();
                    queueTemp.pop();
                    if (compareWord == endWord)
                        return resultCount + 1;
                    for (int index = 0; index < compareWord.size(); index++)
                    {
                        string newWord = compareWord;
                        for (auto charItem = 'a'; charItem < 'z'; charItem++)
                        {
                            newWord[index] = charItem;
                            if (hashTable.count(newWord))
                            {
                                queueTemp.push(newWord);
                                hashTable.erase(newWord);
                            }
                        }    
                    }
                }
                resultCount++;
            }
            return 0;
           
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
            result.wordList = { "hot", "dot", "lot", "log", "dog", "cog" };
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

        /// <summary>
        /// test 3
        /// </summary>   
        Word_Ladder_Model GetTestData003(void)
        {
            Word_Ladder_Model result;
            result.beginWord = "a";
            result.endWord = "c";
            result.wordList = { "a", "b", "c" };
            return result;//expect:2
        };

#pragma endregion TestData
    };
}