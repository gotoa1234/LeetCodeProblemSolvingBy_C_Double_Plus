#include "Easy\0504.Base_7.cpp"
using namespace Solution504;

int main()
{
	Solution504::Base_7 useClass;
	Solution504::Base_7::Base_7_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.convertToBase7(getTestModel.num);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.convertToBase7(getTestModel.num);
}