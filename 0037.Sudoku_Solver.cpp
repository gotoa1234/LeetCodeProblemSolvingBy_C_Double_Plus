#include <iostream>
#include <vector>
using namespace std;

namespace Solution37
{
#pragma region Paste to execute 
	/*
	#include "0037.Sudoku_Solver"
	using namespace Solution37;
	using namespace std;

	int main()
	{
		Solution37::Sudoku_Solver useClass;
		Solution37::Sudoku_Solver::Sudoku_Solver_Model getTestModel = useClass.GetTestData001();
		useClass.isValidSudoku(getTestModel.board);

		getTestModel = useClass.GetTestData002();
		useClass.isValidSudoku(getTestModel.board);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ¸Ñ¼ÆÅª
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
		///     thinking¡G 
		///                
		///                
		///                
		///                
		///                
		///       Runtime¡G
		/// Memory Usage ¡G
		/// </summary>
		void solveSudoku(vector<vector<char>>& board) {

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