#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <queue>
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
    /// 字梯二
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
        ///         思路 ：需要沿用126.的思路做延伸，126.先執行BFS找出所有可能性與單詞的可能位置
        ///                然後再進行DFS遞迴，找出所有單詞的組合可能性
        ///      Runtime :   7 ms Beats 99.36 %
        /// Memory Usage : 9.2 MB Beats 79.62 %
        /// </summary>
        /// <returns></returns>
        unordered_map<string, int> _hashTable;
        vector<vector<string>> _result;
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            
            //1-1. 建立一個wordList的HashTable
            unordered_set<string> hashSetTable(wordList.begin(), wordList.end());
            if (false == hashSetTable.count(endWord))
                return _result;
            queue<string> queue;
            queue.push({ beginWord });
            //1-2. 移除wordList的HashTable中的beginWord
            hashSetTable.erase(beginWord);
            //1-3. _hashTable 紀錄順序用的表，將beginWord設為第一個單詞
            _hashTable[beginWord] = 1;

            while (false == queue.empty())
            {
                string compareWord = queue.front();
                //2-1. 增加一個depth 紀錄第幾個單詞，每輪的queue<string> 是有多種可能，相當於Bfs發散查詢，並記錄順序
                int depth = _hashTable[compareWord];
                queue.pop();

                //3. 走到endWord必須跳出
                if (compareWord == endWord)
                    break;

                for (int index = 0; index < compareWord.size(); index++)
                {
                    char newChar = compareWord[index];
                    for (auto charItem = 'a'; charItem <= 'z'; charItem++)
                    {
                        compareWord[index] = charItem;
                        if (hashSetTable.count(compareWord))
                        {
                            queue.push({ compareWord });
                            hashSetTable.erase(compareWord);
                            _hashTable[compareWord] = depth + 1;
                        }
                    }
                    compareWord[index] = newChar;
                }
            }

            //4-1. DFS進行，從最後一個單詞倒推
			vector<string> seq;
			seq.push_back(endWord);
			DfsCheck(endWord, beginWord, seq);
            
            return _result;
        }
        
        //4-2. 此為Dfs遞迴
        void DfsCheck(string compareWord, string& beginWord, vector<string>& sequence)
        {
            //4-3. 跳出條件為當前的compareWord 等於題目的起始beginWord 表示走到第1個項目，可以結束
            if (compareWord == beginWord)
            {
                reverse(sequence.begin(), sequence.end());
                _result.push_back(sequence);
                reverse(sequence.begin(), sequence.end());
                return;
            }            

            //5-1. 當前compareWord可以從hashTable中取出，上面有紀錄位置數
            int steps = _hashTable[compareWord];
            for (int index = 0; index < compareWord.size(); index++)
            {
                char originalChar = compareWord[index];
                //5-2. 替換26個字元，找出可以DFS的單詞
                for (char charItem = 'a'; charItem <= 'z'; charItem++)
                {
                    compareWord[index] = charItem;
                    //5-3. 若有發現則進入DFS查找
                    if (_hashTable.count(compareWord) && _hashTable[compareWord] + 1 == steps)
                    {
                        sequence.push_back(compareWord);
						DfsCheck(compareWord, beginWord, sequence);
                        sequence.pop_back();
                    }
                }
                compareWord[index] = originalChar;
            }
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