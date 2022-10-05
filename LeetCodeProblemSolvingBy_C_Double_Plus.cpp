#include "0030.Substring_with_Concatenation_of_All_Words.cpp"
using namespace Solution30;
using namespace std;

int main()
{
	Solution30::Substring_with_Concatenation_of_All_Words useClass;
	Solution30::Substring_with_Concatenation_of_All_Words::Substring_with_Concatenation_of_All_Words_Model getTestModel = useClass.GetTestData001();
	vector<int> result = useClass.findSubstring(getTestModel.s, getTestModel.words);

	getTestModel = useClass.GetTestData002();
	result = useClass.findSubstring(getTestModel.s, getTestModel.words);

	getTestModel = useClass.GetTestData003();
	result = useClass.findSubstring(getTestModel.s, getTestModel.words);

	return 0;
}