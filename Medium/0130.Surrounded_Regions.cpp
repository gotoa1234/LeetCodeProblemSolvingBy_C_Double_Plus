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
    /// �P��a��
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
        ///         ��� �G���]�w�@�ӬۦP���Ū�recordBoard�A�M��ѳ̥~�h�@�鬰����I�A�}�l�i��DFS�A�|�Ӥ�V���j�M
        ///                �Y�~�馳'O'�h������������recordBoard��������'O' (�]�����i��Q'X'�]��)
        ///                �̫�N��recordBoard �P��l��Board����s��Board ��
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
            //1-1. �]�wy�Px�b���̤j��
            _yAxisMax = board.size();
            _xAxisMax = board[0].size();
            //1-2. �ǳƤ@�ӥi�O���Ϊ�board
            vector<vector<int>> recordBoard(_yAxisMax, vector<int>(_xAxisMax, 0));

            //2-1. �N�Ĥ@�C�P�̫�@�C�A�Hx�b�M��
            for (int xAxis = 0; xAxis < _xAxisMax; xAxis++) 
            {
				if (false == recordBoard[0][xAxis] && board[0][xAxis] == 'O')
					DfsFind(0, xAxis, recordBoard, board);
				if (false == recordBoard[_yAxisMax - 1][xAxis] && board[_yAxisMax - 1][xAxis] == 'O')
                    DfsFind(_yAxisMax - 1, xAxis, recordBoard, board);
            }
            //2-2. �N�Ĥ@��P�̫�@��A�Hy�b�M��
            for (int yAxis = 0; yAxis < _yAxisMax; yAxis++) {
                if (false == recordBoard[yAxis][0] && board[yAxis][0] == 'O')
                    DfsFind(yAxis, 0, recordBoard, board);
                if (false == recordBoard[yAxis][_xAxisMax - 1] && board[yAxis][_xAxisMax - 1] == 'O')
                    DfsFind(yAxis, _xAxisMax - 1, recordBoard, board);
            }
            
            //4. �NrecordBoard�W�аO��0 �B board�W��1���a�賣�]��'X'
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
            //3-1. DFS��i�ӥ��w��'O' �ҥH������[yAxis][xAxis]�]��1
            recordBorad[yAxisCurrent][xAxisCurrent] = 1;
            //3-2. ���W�U���k
            for (int index = 0; index < 4; index++) 
            {
                int newRow = yAxisCurrent + _yAxisDirector[index];
                int newCol = xAxisCurrent + _xAxisDirector[index];
                //3-3. �ˬd�F�񪺸�ƬO�_��'O' �O�ܦA���jDFS
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