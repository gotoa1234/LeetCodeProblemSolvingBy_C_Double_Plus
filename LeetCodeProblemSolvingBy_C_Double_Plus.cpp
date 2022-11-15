#include "0058.Length_of_Last_Word.cpp"
using namespace Solution58;
using namespace std;

int main()
{
	Solution58::Length_of_Last_Word useClass;
	Solution58::Length_of_Last_Word::Length_of_Last_Word_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.lengthOfLastWord(getTestModel.s);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.lengthOfLastWord(getTestModel.s);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.lengthOfLastWord(getTestModel.s);
}