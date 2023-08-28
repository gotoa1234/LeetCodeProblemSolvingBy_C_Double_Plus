#include "Easy\0415.Add_Strings.cpp"
using namespace Solution415;

int main()
{

	Solution415::Add_Strings useClass;
	Solution415::Add_Strings::Add_Strings_Model getTestModel = useClass.GetTestData001();
	string result = useClass.addStrings(getTestModel.num1, getTestModel.num2);

	getTestModel = useClass.GetTestData002();
	result = useClass.addStrings(getTestModel.num1, getTestModel.num2);

	getTestModel = useClass.GetTestData003();
	result = useClass.addStrings(getTestModel.num1, getTestModel.num2);

}