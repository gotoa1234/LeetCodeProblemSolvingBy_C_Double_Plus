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
	/// �P�_�O�_���ƿW��
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
		///     thinking�G �ɶ������� O(n^2) �֤߬��ˮ�3�ت��p, 
		///                1. �ˬd�Ʀr�O�_�b9�c�椤�w�X�{ 
		///                2. �ˬd�Ʀr�O�_�brow���w�X�{ 
		///                3. �ˬd�Ʀr�O�_�bcolumn���w�X�{
		///                �Q��3�Ӱ}�C�A�C�����[x][y] �W���Ʀr��i�W����3���ˮ֪��}�C���аO�A�C���]�U�@��[x][y] �ɭY���Ʀr�N�ˬd�O�_�w�s�b
		///                �w�s�b�аO��ܭ���; �Y�����]�����S���ƪ�ܦX�k
		///       Runtime�G   21 ms Beats 93.66 %
		/// Memory Usage �G 18.1 MB Beats 71.22 %
		/// </summary>
		bool isValidSudoku(vector<vector<char>>& board) {
			int rowCheck[9][9] = { 0 };//�ˬd�C�@��(��)
			int columnCheck[9][9] = { 0 };//�ˬd�C�@�C(��)
			int subBoxCheck[9][9] = { 0 };//�Ŀ�C�Ӥl��(9�c���)
			int numberAxis = 0, ySubboxAxis = 0;
			for (int yAxis = 0; yAxis < board.size(); yAxis++)
			{
				for (int xAxis = 0; xAxis < board[yAxis].size(); xAxis++)
				{
					if (board[yAxis][xAxis] == '.')
						continue;
					numberAxis = board[yAxis][xAxis] - '0' - 1;//�Ʀr�����
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