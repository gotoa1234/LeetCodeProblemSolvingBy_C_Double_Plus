#include "Medium\0099.Recover_Binary_Search_Tree.cpp"
using namespace Solution99;
using namespace std;

int main()
{

	Solution99::Recover_Binary_Search_Tree useClass;
	Solution99::Recover_Binary_Search_Tree::Recover_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	useClass.recoverTree(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	useClass.recoverTree(getTestModel.root);

}