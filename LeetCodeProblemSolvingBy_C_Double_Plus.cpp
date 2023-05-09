#include "Easy\0258.Add_Digits.cpp"
using namespace Solution258;
using namespace std;
int main()
{
	Solution258::Add_Digits useClass;
	Solution258::Add_Digits::Add_Digits_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.addDigits(getTestModel.num);

	return 0;
}