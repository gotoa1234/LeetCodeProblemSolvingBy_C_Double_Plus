#include "Medium\0105.Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp"
using namespace Solution105;
using namespace std;

int main()
{
	Solution105::Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal useClass;
	Solution105::Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal::Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.buildTree(getTestModel.preorder, getTestModel.inorder);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.buildTree(getTestModel.preorder, getTestModel.inorder);
}