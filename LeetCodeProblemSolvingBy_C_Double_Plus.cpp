#include "0047.Permutations_II.cpp"
using namespace Solution47;
using namespace std;

int main()
{

	Solution47::Permutations_II useClass;
	Solution47::Permutations_II::Permutations_II_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.permuteUnique_bad(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.permuteUnique_bad(getTestModel.nums);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.permuteUnique_bad(getTestModel.nums);
	//getTestModel = useClass.GetTestData003();
	//auto result3 = useClass.permuteUnique(getTestModel.nums);
	return 0;
}
