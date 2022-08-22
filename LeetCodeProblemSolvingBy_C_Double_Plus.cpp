#include "0102.Binary_Tree_Level_Order_Traversal.cpp"
using namespace Solution102;
using namespace std;
int main()
{
	Solution102::Binary_Tree_Level_Order_Traversal useClass;
	Solution102::Binary_Tree_Level_Order_Traversal::Binary_Tree_Level_Order_Traversal_Model getTestModel = useClass.GetTestData001();
	vector<vector<int>> result = useClass.levelOrder(getTestModel.root);

	/*getTestModel = useClass.GetTestData002();*/
	/*result = useClass.levelOrder(getTestModel.s);*/

	//getTestModel = useClass.GetTestData003();
	//result = useClass.detectCycle(getTestModel.head);
	return 0;
}
