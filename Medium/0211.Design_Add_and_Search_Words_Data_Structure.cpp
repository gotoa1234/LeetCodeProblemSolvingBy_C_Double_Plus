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
    /// 設計加法和搜尋文字資料結構
    /// </summary>
    /*         思路： 必須利用字典樹(Trie)才有辦法通過時間複雜度，如果字串的長度與可輸入數量少，還有辦法用HashTable的方式解
    *                 ※558.3Mb 都還可以擊敗75.65% 表示空間盡量用
            Runtime： 455 ms Beats 99.88%
       Memory Usage： 558.3 MB Beats 75.65%
    */
    class Design_Add_and_Search_Words_Data_Structure
    {

#pragma region Model   
    public:
        class WordDictionary {
    public:
        //1-1. 建立26個字母表(題目是a-z組成的字串)
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

        //1-2. 創造一個根節點
        TrieNode* root;

        WordDictionary() {
            root = new TrieNode();
        }
       
        void addWord(string word) 
        {   
            TrieNode* tempNode = root;
            //2. 增加時，找出第字元是否已經建立，沒有則建立，並創建26個子節點(先塞空)
            //             若已經建立了，則往節點下繼續前進
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
            //3-1. 搜尋一律從第一個索引的字元開始
            return searchWord(root, 0, word);
        }

        bool searchWord(TrieNode* p, int index, string& word)
        {
            //3-2. 若長度相同，則回傳是否為走到底了，如果走到底表示有存在此字串
            if (index == word.size()) 
                return p->isEnd;
            //3-3. 處理. 任意字元
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
                //3-4. 非.的情況，需要不斷往下一個節點探索
                return p->childNode[word[index] - 'a'] != nullptr && 
                       searchWord(p->childNode[word[index] - 'a'], index + 1, word);
            }
        }
    };

#pragma endregion Model

#pragma region Main
    public:
        ///         思路 : 
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