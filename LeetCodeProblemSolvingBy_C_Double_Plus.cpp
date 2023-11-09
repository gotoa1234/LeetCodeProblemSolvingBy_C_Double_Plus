#include "Easy\0696.Count_Binary_Substrings.cpp"
using namespace Solution696;
using namespace std;

int main()
{
	Solution696::Count_Binary_Substrings useClass;
	Solution696::Count_Binary_Substrings::Count_Binary_Substrings_Model getTestModel = useClass.GetTestData001();
	int result = useClass.countBinarySubstrings(getTestModel.s);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.countBinarySubstrings(getTestModel.s);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.countBinarySubstrings(getTestModel.s);

	return 0;
}