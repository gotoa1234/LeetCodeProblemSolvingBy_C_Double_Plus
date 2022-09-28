#include "0026.Remove_Duplicates_from_Sorted_Array.cpp"
using namespace Solution26;
using namespace std;

int main()
{
	Solution26::Remove_Duplicates_from_Sorted_Array useClass;
	Solution26::Remove_Duplicates_from_Sorted_Array::Remove_Duplicates_from_Sorted_Array_Model getTestModel = useClass.GetTestData001();
	int result = useClass.removeDuplicates(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	result = useClass.removeDuplicates(getTestModel.nums);
	return 0;
}