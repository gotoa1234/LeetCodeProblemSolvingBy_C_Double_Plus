#include "0025.Reverse_Nodes_in_k_Group.cpp"
using namespace Solution25;
using namespace std;

int main()
{
	Solution25::Reverse_Nodes_in_k_Group useClass;
	Solution25::Reverse_Nodes_in_k_Group::Reverse_Nodes_in_k_Group_Model getTestModel = useClass.GetTestData001();
	Solution25::Reverse_Nodes_in_k_Group::ListNode* result = useClass.reverseKGroup(getTestModel.head, getTestModel.k);

	getTestModel = useClass.GetTestData002();
	result = useClass.reverseKGroup(getTestModel.head, getTestModel.k);

	return 0;
}