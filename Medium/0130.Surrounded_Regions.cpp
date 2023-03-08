#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution130
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0130.Surrounded_Regions.cpp"
    using namespace Solution130;

    int main()
    {
        Solution130::Surrounded_Regions useClass;
        Solution130::Surrounded_Regions::Surrounded_Regions_Model getTestModel = useClass.GetTestData001();
        useClass.solve(getTestModel.board);

        getTestModel = useClass.GetTestData002();
        useClass.solve(getTestModel.board);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 周邊地區
    /// </summary>
    class Surrounded_Regions
    {
    public:
        //Definition for singly-linked list.
        struct TreeNode {
            int val;
            TreeNode* left;
            TreeNode* right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
        };
#pragma region Model
    public:
        class Surrounded_Regions_Model
        {
        public:
            vector<vector<char>> board;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：先設定一個相同的空表recordBoard，然後由最外層一圈為基準點，開始進行DFS，四個方向的搜尋
        ///                若外圈有'O'則延伸的內圈資料recordBoard都必須為'O' (因為不可能被'X'包覆)
        ///                最後將值recordBoard 與原始的Board比對更新至Board 中
        ///      Runtime :   11 ms Beats 88.98 %
        /// Memory Usage : 10.5 MB Beats 24.26 %
        /// </summary>
        /// <returns></returns>
        vector<int> _yAxisDirector = {-1, 0, 1, 0};
        vector<int> _xAxisDirector = {0, 1, 0, -1};
        int _yAxisMax = INT_MAX;
        int _xAxisMax = INT_MAX;
        void solve(vector<vector<char>>& board) 
        {
            //1-1. 設定y與x軸的最大值
            _yAxisMax = board.size();
            _xAxisMax = board[0].size();
            //1-2. 準備一個可記錄用的board
            vector<vector<int>> recordBoard(_yAxisMax, vector<int>(_xAxisMax, 0));

            //2-1. 將第一列與最後一列，以x軸遍歷
            for (int xAxis = 0; xAxis < _xAxisMax; xAxis++) 
            {
				if (false == recordBoard[0][xAxis] && board[0][xAxis] == 'O')
					DfsFind(0, xAxis, recordBoard, board);
				if (false == recordBoard[_yAxisMax - 1][xAxis] && board[_yAxisMax - 1][xAxis] == 'O')
                    DfsFind(_yAxisMax - 1, xAxis, recordBoard, board);
            }
            //2-2. 將第一行與最後一行，以y軸遍歷
            for (int yAxis = 0; yAxis < _yAxisMax; yAxis++) {
                if (false == recordBoard[yAxis][0] && board[yAxis][0] == 'O')
                    DfsFind(yAxis, 0, recordBoard, board);
                if (false == recordBoard[yAxis][_xAxisMax - 1] && board[yAxis][_xAxisMax - 1] == 'O')
                    DfsFind(yAxis, _xAxisMax - 1, recordBoard, board);
            }
            
            //4. 將recordBoard上標記為0 且 board上為1的地方都設為'X'
            for (int yAxis = 0; yAxis < _yAxisMax; yAxis++) 
            {
                for (int xAxis = 0; xAxis < _xAxisMax; xAxis++) 
                {
                    if (false == recordBoard[yAxis][xAxis] && board[yAxis][xAxis] == 'O')
                        board[yAxis][xAxis] = 'X';
                }
            }

        }

        void DfsFind(int yAxisCurrent, int xAxisCurrent, vector<vector<int>>& recordBorad, vector<vector<char>>& board) 
        {
            //3-1. DFS能進來必定為'O' 所以紀錄表[yAxis][xAxis]設為1
            recordBorad[yAxisCurrent][xAxisCurrent] = 1;
            //3-2. 走上下左右
            for (int index = 0; index < 4; index++) 
            {
                int newRow = yAxisCurrent + _yAxisDirector[index];
                int newCol = xAxisCurrent + _xAxisDirector[index];
                //3-3. 檢查鄰近的資料是否為'O' 是話再遞迴DFS
                if (newRow >= 0 && 
                    newRow < _yAxisMax && 
                    newCol >= 0 && 
                    newCol < _xAxisMax && 
                    false == recordBorad[newRow][newCol] && 
                    board[newRow][newCol] == 'O')
                {
                    DfsFind(newRow, newCol, recordBorad, board);
                }
            }
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Surrounded_Regions_Model GetTestData001(void)
        {
            Surrounded_Regions_Model result;
            result.board = { {'X','X','X','X' } ,{'X','O','O','X' } ,{'X','X','O','X' } ,{'X','O','X','X' }};
            return result;//expect: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Surrounded_Regions_Model GetTestData002(void)
        {
            Surrounded_Regions_Model result;
            result.board = {{'X'}};
            return result;//expect: [["X"]]
        };

#pragma endregion TestData
    };
}