#include "Easy\0263.Ugly_Number.cpp"
using namespace Solution263;

int main()
{

	Solution263::Ugly_Number useClass;
	Solution263::Ugly_Number::Ugly_Number_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.isUgly(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	bool result2 = useClass.isUgly(getTestModel.n);

	getTestModel = useClass.GetTestData003();
	bool result3 = useClass.isUgly(getTestModel.n);
}