#include "0098.Validate_Binary_Search_Tree.cpp"
using namespace Solution98;
using namespace std;

int main()
{
	Solution98::Validate_Binary_Search_Tree useClass;
	Solution98::Validate_Binary_Search_Tree::Validate_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.isValidBST(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	result = useClass.isValidBST(getTestModel.root);

	return 0;
}
