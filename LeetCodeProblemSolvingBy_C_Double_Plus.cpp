#include "0018.4Sum.cpp"
using namespace Solution18;
using namespace std;

int main()
{
	Solution18::Four_Sum useClass;
	Solution18::Four_Sum::Four_Sum_Model getTestModel = useClass.GetTestData001();
	vector<vector<int>> result = useClass.fourSum(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData002();
	result = useClass.fourSum(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData003();
	result = useClass.fourSum(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData004();
	result = useClass.fourSum(getTestModel.nums, getTestModel.target);
	return 0;
}