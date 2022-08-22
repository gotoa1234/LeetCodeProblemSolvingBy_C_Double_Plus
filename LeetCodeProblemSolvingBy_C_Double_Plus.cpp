#include "0589.N_aryTree_Preorder_Traversal.cpp"
using namespace Solution589;
using namespace std;
int main()
{
	Solution589::N_aryTree_Preorder_Traversal useClass;
	Solution589::N_aryTree_Preorder_Traversal::N_aryTree_Preorder_Traversal_Model getTestModel = useClass.GetTestData002();
	vector<int> result = useClass.preorder(getTestModel.root);

	/*getTestModel = useClass.GetTestData002();*/
	/*result = useClass.levelOrder(getTestModel.s);*/

	//getTestModel = useClass.GetTestData003();
	//result = useClass.detectCycle(getTestModel.head);
	return 0;
}
