#include "0003.Longest_Substring_Without_Repeating_Characters.cpp"
using namespace Solution3;
using namespace std;

int main()
{

	Solution3::Longest_Substring_Without_Repeating_Characters useClass;
	Solution3::Longest_Substring_Without_Repeating_Characters::Longest_Substring_Without_Repeating_Characters_Model getTestModel = useClass.GetTestData001();
	int result = useClass.lengthOfLongestSubstring(getTestModel.s);
	return 0;
}