#include "0033.Search_in_Rotated_Sorted_Array.cpp"
using namespace Solution33;
using namespace std;

int main()
{
	Solution33::Search_in_Rotated_Sorted_Array useClass;
	Solution33::Search_in_Rotated_Sorted_Array::Search_in_Rotated_Sorted_Array_Model getTestModel = useClass.GetTestData001();
	int result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData002();
	result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData003();
	result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData004();
	result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData005();
	result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData006();
	result = useClass.search(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData007();
	result = useClass.search(getTestModel.nums, getTestModel.target);
	return 0;
}