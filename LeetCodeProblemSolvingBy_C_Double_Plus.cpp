#include <vector>
#include "Easy\0387.First_Unique_Character_in_a_String.cpp"
using namespace Solution387;

int main()
{
	Solution387::First_Unique_Character_in_a_String useClass;
	Solution387::First_Unique_Character_in_a_String::First_Unique_Character_in_a_String_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.firstUniqChar(getTestModel.s);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.firstUniqChar(getTestModel.s);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.firstUniqChar(getTestModel.s);
	return 0;
}