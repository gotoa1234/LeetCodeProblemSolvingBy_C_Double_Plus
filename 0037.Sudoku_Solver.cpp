#include <iostream>
#include <vector>
using namespace std;

namespace Solution37
{
#pragma region Paste to execute 
	/*
    #include "0037.Sudoku_Solver.cpp"
    using namespace Solution37;
    using namespace std;
    
    int main()
    {
    	Solution37::Sudoku_Solver useClass;
    	Solution37::Sudoku_Solver::Sudoku_Solver_Model getTestModel = useClass.GetTestData001();
    	useClass.solveSudoku(getTestModel.board);
    
    	getTestModel = useClass.GetTestData002();
    	useClass.solveSudoku(getTestModel.board);
    	return 0;
    }

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 解數讀
	/// </summary>
	class Sudoku_Solver
	{
#pragma region Model
	public:
		class Sudoku_Solver_Model
		{
		public:
			vector<vector<char>> board;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 
		///                
		///                
		///                
		///                
		///                
		///       Runtime：
		/// Memory Usage ：
		/// </summary>
		int _rowCheck[9][9] = { 0 };//檢查每一行(橫)
		int _columnCheck[9][9] = { 0 };//檢查每一列(直)
		int _subBoxCheck[9][9] = { 0 };//勾選每個子框(9宮格框)
		void solveSudoku(vector<vector<char>>& board) {
			//_rowCheck = vector<vector<int>>(9, vector<int>(10));
			//_columnCheck = vector<vector<int>>(9, vector<int>(10));
			//_subBoxCheck = vector<vector<int>>(9, vector<int>(10));
			int numberAxis = 0;
			int ySubboxAxis = 0;
			char number = ' ';
			//1. 先將題目內容的位置設為已走過
			for (int yAxis = 0; yAxis < 9; yAxis++)
				for (int xAxis = 0; xAxis < 9; xAxis++) 
				{
					number = board[yAxis][xAxis];
					if (number != '.') 
					{
						numberAxis = board[yAxis][xAxis] - '0' - 1;//數字轉索引
						ySubboxAxis = yAxis / 3 * 3 + xAxis / 3;
						_rowCheck[yAxis][numberAxis] = _columnCheck[xAxis][numberAxis] = _subBoxCheck[ySubboxAxis][numberAxis] = 1;
					}
				}
			//2. 由座標 x,y (0,0)開始
			fill(board, 0, 0);
		}

	private:

		//vector<vector<int>> _rowCheck, _columnCheck, _subBoxCheck;

		bool fill(vector<vector<char>>& board, int x, int y) {
			if (y == 9)
				return true;

			int nx = (x + 1) % 9;
			int ny = (nx == 0) ? y + 1 : y;

			if (board[y][x] != '.') 
				return fill(board, nx, ny);

			for (int i = 0; i < 9; i++) {
				int bx = x / 3;
				int by = y / 3;
				int box_key = by * 3 + bx;
				if (!_rowCheck[y][i] && !_columnCheck[x][i] && !_subBoxCheck[box_key][i]) 
				{
					_rowCheck[y][i] = 1;
					_columnCheck[x][i] = 1;
					_subBoxCheck[box_key][i] = 1;
					board[y][x] = i + '0';
					if (fill(board, nx, ny)) 
						return true;
					board[y][x] = '.';
					_subBoxCheck[box_key][i] = 0;
					_columnCheck[x][i] = 0;
					_rowCheck[y][i] = 0;
				}
			}
			return false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Sudoku_Solver_Model GetTestData001(void)
		{
			Sudoku_Solver_Model result;
			result.board = {
				  {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
				, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
				, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
				, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
				, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
				, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
				, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
				, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
				, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
			};
			return result;//except: true
		};

		/// <summary>
		/// test data 2
		/// </summary>   
		Sudoku_Solver_Model GetTestData002(void)
		{
			Sudoku_Solver_Model result;
			result.board = {
				  {'8', '3', '.', '.', '7', '.', '.', '.', '.'}
				, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
				, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
				, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
				, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
				, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
				, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
				, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
				, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
			};
			return result;//except: false
		};
#pragma endregion TestData

	};
}