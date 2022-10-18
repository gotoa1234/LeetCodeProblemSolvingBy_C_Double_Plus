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
		///     thinking： 先將題目的所有數字標記 行、列、子9宮格 對應的位置為1
		///                接著從 0,0 (x,y) 開始遍歷，直到跑到 8,8 (x,y) 
		///                每走一步時，判斷是否為 '.' 是的話進入遞迴傳一個可以塞的數字 (檢核行、列、子9)
		///                每當錯誤時回滾塞入的數值，並且x,y的值+1 嘗試下個值是否可以填寫 
		///       Runtime：  3 ms Beats 99.35 %
		/// Memory Usage ：6.4 MB Beats	52.00 %
		/// </summary>
		int _rowCheck[9][9] = { 0 };//檢查每一行(橫)
		int _columnCheck[9][9] = { 0 };//檢查每一列(直)
		int _subBoxCheck[9][9] = { 0 };//勾選每個子框(9宮格框)
		void solveSudoku(vector<vector<char>>& board) {
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
			FillNumber(board, 0, 0);
		}

	private:
		bool FillNumber(vector<vector<char>>& board, int xAxis, int yAxis) {
			//走到底跳出
			if (yAxis == 9)
				return true;

			//先決定下個步數是多少
			int netxXAxis = (xAxis + 1) % 9;
			int nextYAxis = (netxXAxis == 0) ? yAxis + 1 : yAxis;

			//如果本次步數是空白，先規劃出下一個步數
			if (board[yAxis][xAxis] != '.') 
				return FillNumber(board, netxXAxis, nextYAxis);

			//檢查3個表格的 0~8的位置 (也就是1~9號)
			for (int index = 0; index < 9; index++) 
			{
				int ySubboxAxis = yAxis / 3 * 3 + xAxis / 3;
				if (!_rowCheck[yAxis][index] && !_columnCheck[xAxis][index] && !_subBoxCheck[ySubboxAxis][index])
				{
					//嘗試寫一個數值在Board[y軸][x軸]上
					_rowCheck[yAxis][index] = _columnCheck[xAxis][index] = _subBoxCheck[ySubboxAxis][index] = 1;
					board[yAxis][xAxis] = index + '0' + 1;//索引轉數字
					if (FillNumber(board, netxXAxis, nextYAxis))
					{
						//合法可以填的數值
						return true;
					}
					//重置吧，此路不通全都Revrt
					board[yAxis][xAxis] = '.';
					_subBoxCheck[ySubboxAxis][index] = _columnCheck[xAxis][index] = _rowCheck[yAxis][index] = 0;
				}
			}
			//上面3個表格都走過，表示已無欄位可塞入，可以結束
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