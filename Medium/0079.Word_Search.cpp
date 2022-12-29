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
    /// 子集
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
        ///         思路 ：此題可以用DFS ，從Board中找到word的第一個字，然後往上右下左四個方向繼續查詢，如果有的話可以回傳True
        ///                如果要提升Runtime，前置兩個檢查很重要，可以排查不合法的查詢，避免浪費時間
        ///      Runtime :  62 ms Beats 98.35 %
        /// Memory Usage : 7.8 MB Beats 94.86 %
        /// </summary>
        /// <returns></returns>
        int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        bool check(int currentYAxis, int currentXAxis, int findIndex, 
            vector<vector<char>>& board, string& word, 
            int yAxisMax, int xAxisMax, int wordMax)
        {
            //3-1. 找到最後一個項目且符合回傳true
            if (findIndex == wordMax) 
                return true;
            //3-2. 以下條件不合表示失敗
            if (currentYAxis < 0 || currentXAxis < 0 ||
                currentYAxis == yAxisMax || currentXAxis == xAxisMax || 
                board[currentYAxis][currentXAxis] != word[findIndex]
                ) 
                return false;

            //3-3. 找到的標記為空 (避免重複走)
            board[currentYAxis][currentXAxis] = ' ';
            for (int k = 0; k < 4; k++) //上左下右四個方向
            {
                int nextYAxis = currentYAxis + direction[k][0];
                int nextXAxis = currentXAxis + direction[k][1];
				if (check(nextYAxis, nextXAxis, findIndex + 1, board, word, yAxisMax, xAxisMax, wordMax))
                    return true;
            }
            //3-4. 若4個方向都失敗走到此要還原borad的值
            board[currentYAxis][currentXAxis] = word[findIndex];
            return false;
        }
        bool exist(vector<vector<char>>& board, string word) 
        {
            //1-1. 檢查範圍是否合理
            int yAxisMax = board.size();
            int xAxisMax = board[0].size();
            int wordMax = word.size();
            if (yAxisMax * xAxisMax < wordMax) 
                return false;
            //1-2. 檢查給的板子Borad 是否都有word裡面的字元
            int asciiTable[128] = { 0 };
            for (int yAxis = 0; yAxis < board.size(); yAxis++)
            {
                for (int xAxis = 0; xAxis < board[yAxis].size(); xAxis++)
                {
                    asciiTable[board[yAxis][xAxis]]++;
                }
            }
            for (auto wordChar : word) 
            {
                asciiTable[wordChar]--;
                if (asciiTable[wordChar] < 0)
                    return false;
            }

            //2. 使用DFS 檢查每個字元的延伸是否有符合結果
            for (int yAxis = 0; yAxis < yAxisMax; yAxis++)
            {
                for (int xAxis = 0; xAxis < xAxisMax; xAxis++)
                {
                    //2-1. 進入遞迴Check 如果都有符合可回傳true
                    if (board[yAxis][xAxis] == word[0] && 
                        check(yAxis, xAxis, 0, board, word, yAxisMax, xAxisMax, wordMax)
                       )
                    {
                        return true;
                    }
                }
            }
            return false;
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