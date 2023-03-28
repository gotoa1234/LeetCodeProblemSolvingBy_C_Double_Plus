#include "Easy\0145.Binary_Tree_Postorder_Traversal.cpp"
using namespace Solution145;
using namespace std;


int main()
{
	Solution145::Binary_Tree_Postorder_Traversal useClass;
	Solution145::Binary_Tree_Postorder_Traversal::Binary_Tree_Postorder_Traversal_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.postorderTraversal(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.postorderTraversal(getTestModel.root);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.postorderTraversal(getTestModel.root);
}