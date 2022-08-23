#include "0235.Lowest_Common_Ancestor_of_a_Binary_Search_Tree.cpp"
using namespace Solution235;
using namespace std;


int main()
{
	Solution235::Lowest_Common_Ancestor_of_a_Binary_Search_Tree useClass;
	Solution235::Lowest_Common_Ancestor_of_a_Binary_Search_Tree::Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	Solution235::Lowest_Common_Ancestor_of_a_Binary_Search_Tree::TreeNode* result = useClass.lowestCommonAncestor(getTestModel.root, getTestModel.p, getTestModel.q);

	getTestModel = useClass.GetTestData002();
	result = useClass.lowestCommonAncestor(getTestModel.root, getTestModel.p, getTestModel.q);

	return 0;
}
