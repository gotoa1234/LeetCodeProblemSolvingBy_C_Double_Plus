#include "Medium\0113.Path_Sum_II.cpp"
using namespace Solution113;
using namespace std;

int main()
{
	Solution113::Path_Sum useClass;
	Solution113::Path_Sum::Path_Sum_II_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.pathSum(getTestModel.root, getTestModel.targetSum);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.pathSum(getTestModel.root, getTestModel.targetSum);
}