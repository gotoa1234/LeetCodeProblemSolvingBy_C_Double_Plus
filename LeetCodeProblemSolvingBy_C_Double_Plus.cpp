#include "0019.Remove_Nth_Node_From_End_of_List.cpp"
using namespace Solution19;
using namespace std;

int main()
{
	Solution19::Remove_Nth_Node_From_End_of_List useClass;
	Solution19::Remove_Nth_Node_From_End_of_List::Remove_Nth_Node_From_End_of_List_Model getTestModel = useClass.GetTestData001();
	Remove_Nth_Node_From_End_of_List::ListNode* result = useClass.removeNthFromEnd(getTestModel.head, getTestModel.n);

	getTestModel = useClass.GetTestData002();
	result = useClass.removeNthFromEnd(getTestModel.head, getTestModel.n);

	getTestModel = useClass.GetTestData003();
	result = useClass.removeNthFromEnd(getTestModel.head, getTestModel.n);

	getTestModel = useClass.GetTestData004();
	result = useClass.removeNthFromEnd(getTestModel.head, getTestModel.n);
	return 0;
}
