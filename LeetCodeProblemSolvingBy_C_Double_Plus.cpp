#include "0044.Wildcard_Matching.cpp"
using namespace Solution44;
using namespace std;

int main()
{
	bool result = false;
	Solution44::Wildcard_Matching useClass;
	Solution44::Wildcard_Matching::Wildcard_Matching_Model getTestModel = useClass.GetTestData001();
	result = useClass.isMatch(getTestModel.s, getTestModel.p);

	getTestModel = useClass.GetTestData002();
	result = useClass.isMatch(getTestModel.s, getTestModel.p);

	getTestModel = useClass.GetTestData003();
	result = useClass.isMatch(getTestModel.s, getTestModel.p);

	getTestModel = useClass.GetTestData004();
	result = useClass.isMatch(getTestModel.s, getTestModel.p);

	getTestModel = useClass.GetTestData005();
	result = useClass.isMatch(getTestModel.s, getTestModel.p);
	return 0;
}