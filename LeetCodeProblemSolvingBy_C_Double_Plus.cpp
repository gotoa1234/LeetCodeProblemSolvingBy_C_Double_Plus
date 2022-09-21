#include "0023.Merge_k_Sorted_Lists.cpp"
using namespace Solution23;
using namespace std;

int main()
{
	Solution23::Merge_k_Sorted_Lists useClass;
	Solution23::Merge_k_Sorted_Lists::Merge_k_Sorted_Lists_Model getTestModel = useClass.GetTestData001();
	Solution23::Merge_k_Sorted_Lists::ListNode* result = useClass.mergeKLists(getTestModel.head);

	getTestModel = useClass.GetTestData002();
	result = useClass.mergeKLists(getTestModel.head);

	getTestModel = useClass.GetTestData003();
	result = useClass.mergeKLists(getTestModel.head);
	return 0;
}