#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution211
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0211.Design_Add_and_Search_Words_Data_Structure.cpp"
    using namespace Solution211;

    int main()
    {
        Solution211::Design_Add_and_Search_Words_Data_Structure useClass;
        Solution211::Design_Add_and_Search_Words_Data_Structure::Design_Add_and_Search_Words_Data_Structure_Model getTestModel = useClass.GetTestData2();
        auto result = useClass.countPrimes(getTestModel.grid);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.countPrimes(getTestModel.grid);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.countPrimes(getTestModel.grid);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �]�p�[�k�M�j�M��r��Ƶ��c
    /// </summary>
    /*         ����G �����Q�Φr���(Trie)�~����k�q�L�ɶ������סA�p�G�r�ꪺ���׻P�i��J�ƶq�֡A�٦���k��HashTable���覡��
    *                 ��558.3Mb ���٥i�H����75.65% ��ܪŶ��ɶq��
            Runtime�G 455 ms Beats 99.88%
       Memory Usage�G 558.3 MB Beats 75.65%
    */
    class Design_Add_and_Search_Words_Data_Structure
    {

#pragma region Model   
    public:
        class WordDictionary {
    public:
        //1-1. �إ�26�Ӧr����(�D�جOa-z�զ����r��)
        struct TrieNode {
        public:
            TrieNode* childNode[26];
            bool isEnd = false;
            TrieNode() 
            {
                for (auto& node : childNode)
                    node = nullptr;
            }
        };

        //1-2. �гy�@�Ӯڸ`�I
        TrieNode* root;

        WordDictionary() {
            root = new TrieNode();
        }
       
        void addWord(string word) 
        {   
            TrieNode* tempNode = root;
            //2. �W�[�ɡA��X�Ħr���O�_�w�g�إߡA�S���h�إߡA�óЫ�26�Ӥl�`�I(�����)
            //             �Y�w�g�إߤF�A�h���`�I�U�~��e�i
            for (auto& charItem : word) 
            {
                int index = charItem - 'a';
                if (tempNode->childNode[index] == nullptr) 
                    tempNode->childNode[index] = new TrieNode();
				tempNode = tempNode->childNode[index];
            }
            tempNode->isEnd = true;
        }

        bool search(string word) {
            //3-1. �j�M�@�߱q�Ĥ@�ӯ��ު��r���}�l
            return searchWord(root, 0, word);
        }

        bool searchWord(TrieNode* p, int index, string& word)
        {
            //3-2. �Y���׬ۦP�A�h�^�ǬO�_�����쩳�F�A�p�G���쩳��ܦ��s�b���r��
            if (index == word.size()) 
                return p->isEnd;
            //3-3. �B�z. ���N�r��
            if (word[index] == '.') 
            {
                for (auto& charItem : p->childNode) 
                {
                    if (charItem != nullptr && searchWord(charItem, index + 1, word))
                        return true;
                }
                return false;
            }
            else 
            {
                //3-4. �D.�����p�A�ݭn���_���U�@�Ӹ`�I����
                return p->childNode[word[index] - 'a'] != nullptr && 
                       searchWord(p->childNode[word[index] - 'a'], index + 1, word);
            }
        }
    };

#pragma endregion Model

#pragma region Main
    public:
        ///         ��� : 
        ///                
        ///      Runtime:  
        /// Memory Usage : 
        void WordDictionaryExecute() {
            /* Input
                ["WordDictionary", "addWord", "addWord", "addWord", "search", "search", "search", "search"]
            [[], ["bad"], ["dad"], ["mad"], ["pad"], ["bad"], [".ad"], ["b.."]]           
              */ 
            WordDictionary wordDictionary = WordDictionary();
            wordDictionary.addWord("bad");
            wordDictionary.addWord("dad");
            wordDictionary.addWord("mad");
            wordDictionary.search("pad"); // return False
            wordDictionary.search("bad"); // return True
            wordDictionary.search(".ad"); // return True
            wordDictionary.search("b.."); // return True
        }//expect:  [null, null, null, null, false, true, true, true]
#pragma endregion Main

    };
}