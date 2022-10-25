#include "0040.Combination_Sum_II.cpp"
using namespace Solution40;
using namespace std;

int main()
{
	vector<vector<int>> result = {};
	Solution40::Combination_Sum_II useClass;
	Solution40::Combination_Sum_II::Combination_Sum_II_Model getTestModel = useClass.GetTestData001();
	result = useClass.combinationSum2(getTestModel.candidates, getTestModel.target);

	getTestModel = useClass.GetTestData002();
	result = useClass.combinationSum2(getTestModel.candidates, getTestModel.target);

	getTestModel = useClass.GetTestData003();
	result = useClass.combinationSum2(getTestModel.candidates, getTestModel.target);
	return 0;
}