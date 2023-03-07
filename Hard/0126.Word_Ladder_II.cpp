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
    /// �r��G
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
        ///         ��� �G�ݭn�u��126.������������A126.������BFS��X�Ҧ��i��ʻP������i���m
        ///                �M��A�i��DFS���j�A��X�Ҧ�������զX�i���
        ///      Runtime :   7 ms Beats 99.36 %
        /// Memory Usage : 9.2 MB Beats 79.62 %
        /// </summary>
        /// <returns></returns>
        unordered_map<string, int> _hashTable;
        vector<vector<string>> _result;
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            
            //1-1. �إߤ@��wordList��HashTable
            unordered_set<string> hashSetTable(wordList.begin(), wordList.end());
            if (false == hashSetTable.count(endWord))
                return _result;
            queue<string> queue;
            queue.push({ beginWord });
            //1-2. ����wordList��HashTable����beginWord
            hashSetTable.erase(beginWord);
            //1-3. _hashTable �������ǥΪ���A�NbeginWord�]���Ĥ@�ӳ��
            _hashTable[beginWord] = 1;

            while (false == queue.empty())
            {
                string compareWord = queue.front();
                //2-1. �W�[�@��depth �����ĴX�ӳ���A�C����queue<string> �O���h�إi��A�۷��Bfs�o���d�ߡA�ðO������
                int depth = _hashTable[compareWord];
                queue.pop();

                //3. ����endWord�������X
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

            //4-1. DFS�i��A�q�̫�@�ӳ���˱�
			vector<string> seq;
			seq.push_back(endWord);
			DfsCheck(endWord, beginWord, seq);
            
            return _result;
        }
        
        //4-2. ����Dfs���j
        void DfsCheck(string compareWord, string& beginWord, vector<string>& sequence)
        {
            //4-3. ���X���󬰷�e��compareWord �����D�ت��_�lbeginWord ��ܨ����1�Ӷ��ءA�i�H����
            if (compareWord == beginWord)
            {
                reverse(sequence.begin(), sequence.end());
                _result.push_back(sequence);
                reverse(sequence.begin(), sequence.end());
                return;
            }            

            //5-1. ��ecompareWord�i�H�qhashTable�����X�A�W����������m��
            int steps = _hashTable[compareWord];
            for (int index = 0; index < compareWord.size(); index++)
            {
                char originalChar = compareWord[index];
                //5-2. ����26�Ӧr���A��X�i�HDFS�����
                for (char charItem = 'a'; charItem <= 'z'; charItem++)
                {
                    compareWord[index] = charItem;
                    //5-3. �Y���o�{�h�i�JDFS�d��
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