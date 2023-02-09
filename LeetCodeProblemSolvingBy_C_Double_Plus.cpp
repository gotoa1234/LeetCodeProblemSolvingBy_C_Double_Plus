#include "Easy\0108.Convert_Sorted_Array_to_Binary_Search_Tree.cpp"
using namespace Solution108;
using namespace std;

int main()
{
	Solution108::Convert_Sorted_Array_to_Binary_Search_Tree useClass;
	Solution108::Convert_Sorted_Array_to_Binary_Search_Tree::Convert_Sorted_Array_to_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.sortedArrayToBST(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.sortedArrayToBST(getTestModel.nums);
}