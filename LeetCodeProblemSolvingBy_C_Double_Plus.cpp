#include "Easy/0094.Binary_Tree_Inorder_Traversal.cpp"
using namespace Solution94;
using namespace std;

int main()
{
	Solution94::Recover_Binary_Search_Tree useClass;
	Solution94::Recover_Binary_Search_Tree::Recover_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.inorderTraversal(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.inorderTraversal(getTestModel.root);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.inorderTraversal(getTestModel.root);
}