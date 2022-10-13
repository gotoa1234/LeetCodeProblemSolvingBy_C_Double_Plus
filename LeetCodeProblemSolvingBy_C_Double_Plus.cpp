#include "0036.Valid_Sudoku.cpp"
#include <string> 
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