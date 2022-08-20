#include "0142.Linked_List_Cycle_II.cpp"
using namespace Solution142;
using namespace std;


int main()
{


    Solution142::Linked_List_Cycle_II useClass;
    Solution142::Linked_List_Cycle_II::Linked_List_Cycle_II_Model getTestModel = useClass.GetTestData001();
    Solution142::Linked_List_Cycle_II::ListNode* result = useClass.detectCycle(getTestModel.head);
	getTestModel = useClass.GetTestData002();
	result = useClass.detectCycle(getTestModel.head);

	getTestModel = useClass.GetTestData003();
	result = useClass.detectCycle(getTestModel.head);
	return 0;
}
