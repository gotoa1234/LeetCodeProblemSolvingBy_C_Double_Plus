#include "Easy\0268.Missing_Number.cpp"
using namespace Solution268;

int main()
{

	Solution268::Missing_Number useClass;
	Solution268::Missing_Number::Missing_Number_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.missingNumber(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.missingNumber(getTestModel.nums);
}