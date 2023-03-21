#include <unordered_map>
#include "Hard/0132.Palindrome_Partitioning_II.cpp"
using namespace Solution132;

int main()
{
    Solution132::Palindrome_Partitioning_II useClass;
    Solution132::Palindrome_Partitioning_II::Palindrome_Partitioning_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.minCut("cbdefc");

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.minCut(getTestModel.s);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.minCut(getTestModel.s);
    return 0;
}