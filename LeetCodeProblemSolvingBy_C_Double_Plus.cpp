#include "0024.Swap_Nodes_in_Pairs.cpp"
using namespace Solution24;
using namespace std;

int main()
{
	Solution24::Swap_Nodes_in_Pairs useClass;
	Solution24::Swap_Nodes_in_Pairs::Swap_Nodes_in_Pairs_Model getTestModel = useClass.GetTestData001();
	Solution24::Swap_Nodes_in_Pairs::ListNode* result = useClass.swapPairs(getTestModel.head);

	getTestModel = useClass.GetTestData002();
	result = useClass.swapPairs(getTestModel.head);

	getTestModel = useClass.GetTestData003();
	result = useClass.swapPairs(getTestModel.head);
	return 0;
}