#include "0049.Group_Anagrams.cpp"
using namespace Solution49;
using namespace std;

int main()
{

	Solution49::Group_Anagrams useClass;
	Solution49::Group_Anagrams::Group_Anagrams_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.groupAnagrams(getTestModel.strs);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.groupAnagrams(getTestModel.strs);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.groupAnagrams(getTestModel.strs);
	return 0;
}