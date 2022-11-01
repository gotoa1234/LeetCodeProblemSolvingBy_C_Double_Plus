#include "0046.Permutations.cpp"
using namespace Solution46;
using namespace std;

int main()
{

	Solution46::Permutations useClass;
	Solution46::Permutations::Permutations_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.permute(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.permute(getTestModel.nums);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.permute(getTestModel.nums);
	return 0;
}