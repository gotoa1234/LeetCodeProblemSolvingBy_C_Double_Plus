#include "0402.Longest_Palindrome.cpp"
using namespace Solution402;
using namespace std;
int main()
{
	Solution402::Longest_Palindrome useClass;
	Solution402::Longest_Palindrome::Longest_Palindrome_Model getTestModel = useClass.GetTestData001();
	int result = useClass.longestPalindrome(getTestModel.s);

	getTestModel = useClass.GetTestData002();
	result = useClass.longestPalindrome(getTestModel.s);

	//getTestModel = useClass.GetTestData003();
	//result = useClass.detectCycle(getTestModel.head);
	return 0;
}
