#include "Easy\0110.Balanced_Binary_Tree.cpp"
using namespace Solution110;
using namespace std;

int main()
{
	Solution110::Balanced_Binary_Tree useClass;
	Solution110::Balanced_Binary_Tree::Balanced_Binary_Tree_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.isBalanced(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.isBalanced(getTestModel.root);
}