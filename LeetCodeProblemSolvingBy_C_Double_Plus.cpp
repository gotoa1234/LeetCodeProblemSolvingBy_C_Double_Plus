#include <unordered_map>
#include "Medium/0131.Palindrome_Partitioning.cpp"
using namespace Solution131;

int main()
{
    Solution131::Palindrome_Partitioning useClass;
    Solution131::Palindrome_Partitioning::Palindrome_Partitioning_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.partition(getTestModel.s);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.partition(getTestModel.s);

    return 0;
}