#include "Hard\0124.Binary_Tree_Maximum_Path_Sum.cpp"
using namespace Solution124;
using namespace std;

int main()
{
	Solution124::Binary_Tree_Maximum_Path_Sum useClass;
	Solution124::Binary_Tree_Maximum_Path_Sum::Binary_Tree_Maximum_Path_Sum_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.maxPathSum(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.maxPathSum(getTestModel.root);
}