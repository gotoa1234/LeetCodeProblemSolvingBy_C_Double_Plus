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
		Solution36::Find_First_and_Last_Position_of_Element_in_Sorted_Array useClass;
		Solution36::Find_First_and_Last_Position_of_Element_in_Sorted_Array::Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model getTestModel = useClass.GetTestData001();
		bool result = useClass.isValidSudoku(getTestModel.board);

		getTestModel = useClass.GetTestData002();
		result = useClass.isValidSudoku(getTestModel.board);

		getTestModel = useClass.GetTestData003();
		result = useClass.isValidSudoku(getTestModel.board);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// §PÂ_¬O§_¬°¼Æ¿Wª©
	/// </summary>
	class Find_First_and_Last_Position_of_Element_in_Sorted_Array
	{
#pragma region Model
	public:
		class Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model
		{
		public:
			vector<vector<char>> board;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///     thinking¡G 
		///      Runtime¡G 
		///Memory Usage ¡G 
		/// </summary>
		bool isValidSudoku(vector<vector<char>>& board) {



			return false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test data 1
		/// </summary>        
		Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model GetTestData001(void)
		{
			Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model result;
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
		Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model GetTestData002(void)
		{
			Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model result;
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