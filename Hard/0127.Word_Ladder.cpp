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
    /// �r��
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
        ///         ��� �G���w�@�� beginWord �_�l�r��A�ؼЬO�u������ӵ��i�H��endWord�A�䤤beginWord�i�H��wordList����
        ///                1. �Q�Τ@��queue�N��b�ŦX���r����J (��}�l���w�ObeginWord)
        ///                2. �Q��HashTable �N wordList ����������i�A�C�����ɥ[�ֳt��
        ///                3. �C�����X�@��queue�����ؤ��O�_�ŦX endWord
        ///                4. ���ŦX�h���ͼ�b���r���A�M�᭫��1-4�B�J�A����3.�ŦXendWord�X�{
        ///                5. �W�z�����X�h��0
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