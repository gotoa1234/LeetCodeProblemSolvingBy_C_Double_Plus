#include "0015.3Sum.cpp"
using namespace Solution15;
using namespace std;

int main()
{
	Solution15::Three_Sum useClass;
	Solution15::Three_Sum::Three_Sum_Model getTestModel = useClass.GetTestData001();
	vector<vector<int>> result = useClass.ThreeSum(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	result = useClass.ThreeSum(getTestModel.nums);

	getTestModel = useClass.GetTestData003();
	result = useClass.ThreeSum(getTestModel.nums);
	return 0;
}