#include "0034.Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp"
using namespace Solution34;
using namespace std;

int main()
{
	Solution34::Find_First_and_Last_Position_of_Element_in_Sorted_Array useClass;
	Solution34::Find_First_and_Last_Position_of_Element_in_Sorted_Array::Find_First_and_Last_Position_of_Element_in_Sorted_Array_Model getTestModel = useClass.GetTestData001();
	vector<int> result = useClass.searchRange(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData002();
	result = useClass.searchRange(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData003();
	result = useClass.searchRange(getTestModel.nums, getTestModel.target);

	return 0;
}