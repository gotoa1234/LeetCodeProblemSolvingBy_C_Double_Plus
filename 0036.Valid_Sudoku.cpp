#include <iostream>
#include <vector>
using namespace std;

namespace Solution36
{
#pragma region Paste to execute 
	/*
	#include "0036.Valid_Sudoku.cpp"
	using namespace Solution36;
	using namespace std;

	int main()
	{
	    bool result;
		Solution36::Valid_Sudoku useClass;
		Solution36::Valid_Sudoku::Valid_Sudoku_Model getTestModel = useClass.GetTestData001();
		result = useClass.isValidSudoku(getTestModel.board);

		getTestModel = useClass.GetTestData002();
		result = useClass.isValidSudoku(getTestModel.board);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 判斷是否為數獨版
	/// </summary>
	class Valid_Sudoku
	{
#pragma region Model
	public:
		class Valid_Sudoku_Model
		{
		public:
			vector<vector<char>> board;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking： 時間複雜度 O(n^2) 核心為檢核3種狀況, 
		///                1. 檢查數字是否在9宮格中已出現 
		///                2. 檢查數字是否在row中已出現 
		///                3. 檢查數字是否在column中已出現
		///                利用3個陣列，每次抓到[x][y] 上的數字放進上面的3個檢核的陣列中標記，每次跑下一個[x][y] 時若有數字就檢查是否已存在
		///                已存在標記表示重複; 若全部跑完都沒重複表示合法
		///       Runtime：   21 ms Beats 93.66 %
		/// Memory Usage ： 18.1 MB Beats 71.22 %
		/// </summary>
		bool isValidSudoku(vector<vector<char>>& board) {
			int rowCheck[9][9] = { 0 };//檢查每一行(橫)
			int columnCheck[9][9] = { 0 };//檢查每一列(直)
			int subBoxCheck[9][9] = { 0 };//勾選每個子框(9宮格框)
			int numberAxis = 0, ySubboxAxis = 0;
			for (int yAxis = 0; yAxis < board.size(); yAxis++)
			{
				for (int xAxis = 0; xAxis < board[yAxis].size(); xAxis++)
				{
					if (board[yAxis][xAxis] == '.')
						continue;
					numberAxis = board[yAxis][xAxis] - '0' - 1;//數字轉索引
					ySubboxAxis = yAxis / 3 * 3 + xAxis / 3;
					if (subBoxCheck[ySubboxAxis][numberAxis] ||
						rowCheck[xAxis][numberAxis] ||
						columnCheck[yAxis][numberAxis])
					{
						return false;
					}
					subBoxCheck[ySubboxAxis][numberAxis] = rowCheck[xAxis][numberAxis] = columnCheck[yAxis][numberAxis] = 1;
				}
			}
			return true;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Valid_Sudoku_Model GetTestData001(void)
		{
			Valid_Sudoku_Model result;
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
		Valid_Sudoku_Model GetTestData002(void)
		{
			Valid_Sudoku_Model result;
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