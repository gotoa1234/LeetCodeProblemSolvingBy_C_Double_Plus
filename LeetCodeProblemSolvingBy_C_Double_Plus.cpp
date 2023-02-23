#include "Easy\0125.Valid_Palindrome.cpp"
using namespace Solution125;
using namespace std;

int main()
{
    Solution125::Valid_Palindrome useClass;
    Solution125::Valid_Palindrome::Valid_Palindrome_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.isPalindrome(getTestModel.s);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.isPalindrome(getTestModel.s);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.isPalindrome(getTestModel.s);
}