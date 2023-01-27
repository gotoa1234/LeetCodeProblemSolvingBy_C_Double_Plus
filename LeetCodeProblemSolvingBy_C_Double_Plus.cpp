#include "Easy\0100.Same_Tree.cpp"
using namespace Solution100;
using namespace std;


int main()
{
	Solution100::Recover_Binary_Search_Tree useClass;
	Solution100::Recover_Binary_Search_Tree::Recover_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.isSameTree(getTestModel.p, getTestModel.q);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.isSameTree(getTestModel.p, getTestModel.q);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.isSameTree(getTestModel.p, getTestModel.q);

}