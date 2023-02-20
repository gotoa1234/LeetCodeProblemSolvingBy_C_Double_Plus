#include "Hard/0115.Distinct_Subsequences.cpp"
using namespace Solution115;
using namespace std;

int main()
{
	Solution115::Distinct_Subsequences useClass;
	Solution115::Distinct_Subsequences::Distinct_Subsequences_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.numDistinct(getTestModel.s, getTestModel.t);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.numDistinct(getTestModel.s, getTestModel.t);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.numDistinct(getTestModel.s, getTestModel.t);

	getTestModel = useClass.GetTestData004();
	auto result4 = useClass.numDistinct(getTestModel.s, getTestModel.t);
}