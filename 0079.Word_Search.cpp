#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution79
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0079.Word_Search.cpp"
    using namespace Solution79;

    int main()
    {
        Solution79::Word_Search useClass;
        Solution79::Word_Search::Word_Search_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.exist(getTestModel.board, getTestModel.word);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.exist(getTestModel.board, getTestModel.word);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.exist(getTestModel.board, getTestModel.word);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ¤l¶°
    /// </summary>
    class Word_Search
    {
#pragma region Model
    public:
        class Word_Search_Model
        {
        public:
            vector<vector<char>> board;
            string word;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        bool exist(vector<vector<char>>& board, string word) {
            return {};
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Word_Search_Model GetTestData001(void)
        {
            Word_Search_Model result;
            result.board = { {'A', 'B', 'C', 'E'}, { 'S', 'F', 'C', 'S' },{'A', 'D', 'E', 'E' } };
            result.word = "ABCCED";
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Word_Search_Model GetTestData002(void)
        {
            Word_Search_Model result;
            result.board = { {'A', 'B', 'C', 'E'}, { 'S', 'F', 'C', 'S' },{'A', 'D', 'E', 'E' } };
            result.word = "SEE";
            return result;//expect:true
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Word_Search_Model GetTestData003(void)
        {
            Word_Search_Model result;
            result.board = { {'A', 'B', 'C', 'E'}, { 'S', 'F', 'C', 'S' },{'A', 'D', 'E', 'E' } };
            result.word = "ABCB";
            return result;//expect:false
        };

#pragma endregion TestData
    };
}