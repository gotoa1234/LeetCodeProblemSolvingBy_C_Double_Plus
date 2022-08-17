#include "0009.Palindrome_Number.cpp"
using namespace Solution9;
using namespace std;

int main()
{
    Solution9::Palindrome_Number useClass;
	Solution9::Palindrome_Number::Palindrome_Number_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.myAtoi(getTestModel.x);
	return 0;
}
