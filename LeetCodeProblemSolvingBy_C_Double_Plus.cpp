#include "0020.Valid_Parentheses.cpp"
using namespace Solution20;
using namespace std;

int main()
{
	Solution20::Valid_Parentheses useClass;
	Solution20::Valid_Parentheses::Valid_Parentheses_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.isValid(getTestModel.s);

	getTestModel = useClass.GetTestData002();
	result = useClass.isValid(getTestModel.s);

	getTestModel = useClass.GetTestData003();
	result = useClass.isValid(getTestModel.s);

	getTestModel = useClass.GetTestData004();
	result = useClass.isValid(getTestModel.s);

	return 0;
}