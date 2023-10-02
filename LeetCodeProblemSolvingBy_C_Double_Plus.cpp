#include "Easy\0507.Perfect_Number.cpp"
using namespace Solution507;

int main()
{
	Solution507::Perfect_Number useClass;
	Solution507::Perfect_Number::Perfect_Number_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.checkPerfectNumber(getTestModel.num);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.checkPerfectNumber(getTestModel.num);
}