#include "Medium\0221.Maximal_Square.cpp"
using namespace Solution221;
using namespace std;

int main()
{
	vector<vector<int>> result = {};
	Solution221::Maximal_Square useClass;
	Solution221::Maximal_Square::Maximal_Square_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.maximalSquare(getTestModel.matrix);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.maximalSquare(getTestModel.matrix);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.maximalSquare(getTestModel.matrix);
	return 0;
}
