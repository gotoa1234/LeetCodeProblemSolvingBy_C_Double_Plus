#include <unordered_map>
#include "Medium/0128.Longest_Consecutive_Sequence.cpp"
using namespace Solution128;

int main()
{
    Solution128::Longest_Consecutive_Sequence useClass;
    Solution128::Longest_Consecutive_Sequence::Longest_Consecutive_Sequence_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.longestConsecutive(getTestModel.nums);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.longestConsecutive(getTestModel.nums);


    return 0;
}