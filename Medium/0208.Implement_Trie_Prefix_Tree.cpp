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
    /// �����e��� (�r���)
    /// </summary>
    /*         ����G�غc�r��� = �ϥΤj�q�Ŷ� => �D�ص��w�p�g�^��r�� �Ҧ��w�]�}�C[0]-[25] �N���'a'~'z'
    *                EX: ���J abbca �N�|���� 26 * 26 * 26 * 26 * 26 �Ӱt�m�Ŷ��A�p�U�G
    *                    �Ĥ@�h  �ĤG�h   �ĤT�h  �ĥ|�h  �Ĥ��h
    *                        a     null     null    null       a
                          null        b        b    null    null           
                          null     null     null       c    null
                       ...��25   ...��25 ...��25 ...��25 ...��25
                         ��d�߮� abb �N�|�Ĥ@~ �ĤT�h�����ȡA�ҥHtrue �A��d��ac �ɵo�{null �^��false
    *
            Runtime�G  32 ms Beats 100%
       Memory Usage�G44.8 MB Beats 77.42%
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
        ///         ��� : 
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