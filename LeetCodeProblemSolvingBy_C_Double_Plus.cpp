#include "0043.Multiply_Strings.cpp"
using namespace Solution43;
using namespace std;

int main()
{
	string result = "";
	Solution43::Multiply_Strings useClass;
	Solution43::Multiply_Strings::Multiply_Strings_Model getTestModel = useClass.GetTestData001();
	result = useClass.multiply(getTestModel.num1, getTestModel.num2);

	getTestModel = useClass.GetTestData002();
	result = useClass.multiply(getTestModel.num1, getTestModel.num2);

	getTestModel = useClass.GetTestData003();
	result = useClass.multiply(getTestModel.num1, getTestModel.num2);
	return 0;
}
