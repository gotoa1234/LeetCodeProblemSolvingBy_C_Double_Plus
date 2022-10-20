#include "0039.Combination_Sum.cpp"
using namespace Solution39;
using namespace std;

int main()
{
	vector<vector<int>> result = {};
	Solution39::Combination_Sum useClass;
	Solution39::Combination_Sum::Combination_Sum_Model getTestModel = useClass.GetTestData001();
	result = useClass.combinationSum(getTestModel.candidates, getTestModel.target);

	getTestModel = useClass.GetTestData002();
	result = useClass.combinationSum(getTestModel.candidates, getTestModel.target);

	getTestModel = useClass.GetTestData003();
	result = useClass.combinationSum(getTestModel.candidates, getTestModel.target);
	return 0;
}
