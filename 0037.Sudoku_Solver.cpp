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
	/// �Ѽ�Ū
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
		///     thinking�G ���N�D�ت��Ҧ��Ʀr�аO ��B�C�B�l9�c�� ��������m��1
		///                ���۱q 0,0 (x,y) �}�l�M���A����]�� 8,8 (x,y) 
		///                �C���@�B�ɡA�P�_�O�_�� '.' �O���ܶi�J���j�Ǥ@�ӥi�H�몺�Ʀr (�ˮ֦�B�C�B�l9)
		///                �C����~�ɦ^�u��J���ƭȡA�åBx,y����+1 ���դU�ӭȬO�_�i�H��g 
		///       Runtime�G  3 ms Beats 99.35 %
		/// Memory Usage �G6.4 MB Beats	52.00 %
		/// </summary>
		int _rowCheck[9][9] = { 0 };//�ˬd�C�@��(��)
		int _columnCheck[9][9] = { 0 };//�ˬd�C�@�C(��)
		int _subBoxCheck[9][9] = { 0 };//�Ŀ�C�Ӥl��(9�c���)
		void solveSudoku(vector<vector<char>>& board) {
			int numberAxis = 0;
			int ySubboxAxis = 0;
			char number = ' ';
			//1. ���N�D�ؤ��e����m�]���w���L
			for (int yAxis = 0; yAxis < 9; yAxis++)
				for (int xAxis = 0; xAxis < 9; xAxis++) 
				{
					number = board[yAxis][xAxis];
					if (number != '.') 
					{
						numberAxis = board[yAxis][xAxis] - '0' - 1;//�Ʀr�����
						ySubboxAxis = yAxis / 3 * 3 + xAxis / 3;
						_rowCheck[yAxis][numberAxis] = _columnCheck[xAxis][numberAxis] = _subBoxCheck[ySubboxAxis][numberAxis] = 1;
					}
				}
			//2. �Ѯy�� x,y (0,0)�}�l
			FillNumber(board, 0, 0);
		}

	private:
		bool FillNumber(vector<vector<char>>& board, int xAxis, int yAxis) {
			//���쩳���X
			if (yAxis == 9)
				return true;

			//���M�w�U�ӨB�ƬO�h��
			int netxXAxis = (xAxis + 1) % 9;
			int nextYAxis = (netxXAxis == 0) ? yAxis + 1 : yAxis;

			//�p�G�����B�ƬO�ťաA���W���X�U�@�ӨB��
			if (board[yAxis][xAxis] != '.') 
				return FillNumber(board, netxXAxis, nextYAxis);

			//�ˬd3�Ӫ�檺 0~8����m (�]�N�O1~9��)
			for (int index = 0; index < 9; index++) 
			{
				int ySubboxAxis = yAxis / 3 * 3 + xAxis / 3;
				if (!_rowCheck[yAxis][index] && !_columnCheck[xAxis][index] && !_subBoxCheck[ySubboxAxis][index])
				{
					//���ռg�@�ӼƭȦbBoard[y�b][x�b]�W
					_rowCheck[yAxis][index] = _columnCheck[xAxis][index] = _subBoxCheck[ySubboxAxis][index] = 1;
					board[yAxis][xAxis] = index + '0' + 1;//������Ʀr
					if (FillNumber(board, netxXAxis, nextYAxis))
					{
						//�X�k�i�H�񪺼ƭ�
						return true;
					}
					//���m�a�A�������q����Revrt
					board[yAxis][xAxis] = '.';
					_subBoxCheck[ySubboxAxis][index] = _columnCheck[xAxis][index] = _rowCheck[yAxis][index] = 0;
				}
			}
			//�W��3�Ӫ�泣���L�A��ܤw�L���i��J�A�i�H����
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