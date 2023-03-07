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
            //1. 判斷endWord是否存在
            unordered_set<string> wordSet(wordList.begin(), wordList.end());
            if (false == wordSet.count(endWord)) 
                return 0;

            //2. 建立一個queue
            queue<string> queueTemp{ {beginWord} };
            int resultCount = 0;
            while (false == queueTemp.empty()) 
            {
                //3-1. 每次都將queue內的單詞比較完畢
                for (int index = queueTemp.size(); 0 < index ; index--) 
                {
                    //3-2. 取出queueTemp中潛在符合的單詞
                    string word = queueTemp.front(); 
                    queueTemp.pop();
                    //5. 此單詞出現表示走到盡頭可以跳出
                    if (word == endWord) 
                        return resultCount + 1;
                    //4-1. 在wordSet中找出可以匹配的單詞
                    for (int innerIndex = 0; innerIndex < word.size(); innerIndex++) 
                    {
                        //4-2. 嘗試找出淺在的替換項目，把一個字元換掉時存在於wordSet中
                        string newWord = word;
                        for (char charItem = 'a'; charItem <= 'z'; charItem++) 
                        {
                            newWord[innerIndex] = charItem;
                            //4-3. 找到符合的項目
                            if (wordSet.count(newWord) && newWord != word) 
                            {
                                //4-4. 把wordSet HashTable內的詞移除，不可重複使用，但將該詞放進queueTemp中
                                queueTemp.push(newWord);
                                wordSet.erase(newWord);
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