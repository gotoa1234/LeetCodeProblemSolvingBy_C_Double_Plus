#include <vector>
#include "Easy\0344.Reverse_String.cpp"
using namespace Solution344;

int main()
{
	Solution344::Reverse_String useClass;
	Solution344::Reverse_String::Reverse_String_Model getTestModel = useClass.GetTestData001();
	useClass.reverseString(getTestModel.s);

	getTestModel = useClass.GetTestData002();
	useClass.reverseString(getTestModel.s);
	return 0;
}