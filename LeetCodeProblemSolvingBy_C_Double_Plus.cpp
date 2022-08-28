#include <vector>
#include "0438.Find_All_Anagrams_in_a_String.cpp"
using namespace Solution438;

int main()
{
	Solution438::Find_All_Anagrams_in_a_String useClass;
	Solution438::Find_All_Anagrams_in_a_String::Find_All_Anagrams_in_a_String_Model getTestModel = useClass.GetTestData002();
	vector<int> result = useClass.findAnagrams(getTestModel.s, getTestModel.p);

	getTestModel = useClass.GetTestData001();
	result = useClass.findAnagrams(getTestModel.s, getTestModel.p);

	result = useClass.findAnagrams("baa", "aa");
	return 0;
}
