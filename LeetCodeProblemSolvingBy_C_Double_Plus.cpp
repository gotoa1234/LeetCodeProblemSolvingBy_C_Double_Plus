#include "0206.Reverse_Linked_List.cpp"
using namespace Solution206;
using namespace std;


int main()
{

	Solution206::Reverse_Linked_List useClass;
	Solution206::Reverse_Linked_List::Reverse_Linked_List_Model getTestModel = useClass.GetTestData001();
	Solution206::Reverse_Linked_List::ListNode* result = useClass.reverseList(getTestModel.head);

	getTestModel = useClass.GetTestData002();
	result = useClass.reverseList(getTestModel.head);

	getTestModel = useClass.GetTestData003();
	result = useClass.reverseList(getTestModel.head);
	return 0;
}
