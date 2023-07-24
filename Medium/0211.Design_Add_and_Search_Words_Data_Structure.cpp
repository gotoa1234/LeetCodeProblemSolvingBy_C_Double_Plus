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
    class Design_Add_and_Search_Words_Data_Structure
    {
#pragma region Model
    public:
        class WordDictionary {
    public:
        WordDictionary() {

        }

        void addWord(string word) {

        }

        bool search(string word) {

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