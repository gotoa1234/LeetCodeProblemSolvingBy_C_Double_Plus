#include "Easy\0112.Path_Sum.cpp"
using namespace Solution112;
using namespace std;

int main()
{
	Solution112::Path_Sum useClass;
	Solution112::Path_Sum::Path_Sum_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.hasPathSum(getTestModel.root, getTestModel.targetSum);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.hasPathSum(getTestModel.root, getTestModel.targetSum);
}