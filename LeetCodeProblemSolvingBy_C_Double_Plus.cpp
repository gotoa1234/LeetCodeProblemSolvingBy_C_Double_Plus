#include "0014.Longest_Common_Prefix.cpp"
using namespace Solution14;
using namespace std;

int main()
{
	Solution14::Longest_Common_Prefix useClass;
	Solution14::Longest_Common_Prefix::Longest_Common_Prefix_Model getTestModel = useClass.GetTestData001();
	string result = useClass.longestCommonPrefix(getTestModel.strs);

	getTestModel = useClass.GetTestData002();
	result = useClass.longestCommonPrefix(getTestModel.strs);
	vector<string> input = { "ab", "ac"};
	result = useClass.longestCommonPrefix(input);
	return 0;
}