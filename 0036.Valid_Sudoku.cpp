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
		Solution36::Find_First_and_Last_Position_of_Element_in_Sorted_Array useClass;
		Solution36::Find_First_and_Last_Position_of_Element_in_Sorted_Array::Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model getTestModel = useClass.GetTestData001();
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
		///     thinking： 
		///      Runtime： 
		///Memory Usage ： 
		/// </summary>
		bool isValidSudoku(vector<vector<char>>& board) {
			int used1[9][9] = { 0 }; //檢查每一行
			int used2[9][9] = { 0 };//檢查每一列
			int used3[9][9] = { 0 };//勾選每個子框

			for (int xAxis = 0; xAxis < board.size(); ++xAxis)
			{
				for (int yAxis = 0; yAxis < board[xAxis].size(); ++yAxis)
				{
					if (board[xAxis][yAxis] != '.')
					{
						int num = board[xAxis][yAxis] - '0' - 1;
						int xSubBoxAxis = xAxis / 3 * 3 + yAxis / 3;
						if (used1[xAxis][num] ||
							used2[yAxis][num] ||
							used3[xSubBoxAxis][num])
						{
							return false;
						}
						used1[xAxis][num] = used2[yAxis][num] = used3[xSubBoxAxis][num] = 1;
					}
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