#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution208
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "Medium\\0208.Implement_Trie_Prefix_Tree.cpp"
    using namespace Solution208;
    
    int main()
    {
        Solution208::Implement_Trie_Prefix_Tree useClass;
        useClass.WordDictionaryExecute();
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 完成前綴樹 (字典樹)
    /// </summary>
    /*         思路：建構字典樹 = 使用大量空間 => 題目給定小寫英文字母 所有預設陣列[0]-[25] 代表著'a'~'z'
    *                EX: 插入 abbca 就會產生 26 * 26 * 26 * 26 * 26 個配置空間，如下：
    *                    第一層  第二層   第三層  第四層  第五層
    *                        a     null     null    null       a
                          null        b        b    null    null           
                          null     null     null       c    null
                       ...到25   ...到25 ...到25 ...到25 ...到25
                         當查詢時 abb 就會第一~ 第三層都有值，所以true ，當查詢ac 時發現null 回傳false
    *
            Runtime：  32 ms Beats 100%
       Memory Usage：44.8 MB Beats 77.42%
    */
    class Implement_Trie_Prefix_Tree
    {

#pragma region Model   
    public:
        class Trie {
        public:
            struct TrieNode 
            {
                TrieNode* childItem[26];
                bool isEnd = false;
                TrieNode()
                {
                    for (auto& child : childItem)
                        child = nullptr;
                }
            };
            TrieNode* root;
            Trie() {
                root = new TrieNode();
            }

            void insert(string word) {
                auto tempNode = root;
                for (auto& charItem : word)
                {
                    int index = charItem - 'a';
                    if (tempNode->childItem[index] == nullptr)
                        tempNode->childItem[index] = new TrieNode();
                    tempNode = tempNode->childItem[index];
                }
                tempNode->isEnd = true;
            }

            bool search(string word) {
                bool isPrefix = false;
                return DeepSearch(0, root, word, isPrefix);
            }

            bool DeepSearch(int index, TrieNode* currentNode, string& word, bool& isPrefix)
            {
                if (index == word.size())
                    return isPrefix ? true : currentNode->isEnd;
                
                int currentIndex = word[index] - 'a';
                if (currentNode->childItem[currentIndex] == nullptr)
                    return false;                
                return DeepSearch(index + 1, currentNode->childItem[currentIndex], word, isPrefix);
            }

            bool startsWith(string prefix) {
                bool isPrefix = true;
                return DeepSearch(0, root, prefix, isPrefix);
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
                ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
              */
            Trie trie;
            trie.insert("apple");
            trie.search("apple");   // return True
            trie.search("app");     // return False
            trie.startsWith("app"); // return True
            trie.insert("app");
            trie.search("app");     // return True
        }//expect:  [null, null, true, false, true, null, true]
#pragma endregion Main

    };
}