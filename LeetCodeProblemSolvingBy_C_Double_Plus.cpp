#include "Medium\0106.Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp"
using namespace Solution106;
using namespace std;

int main()
{
	Solution106::Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal useClass;
	Solution106::Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal::Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.buildTree(getTestModel.inorder, getTestModel.postorder);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.buildTree(getTestModel.inorder, getTestModel.postorder);
}