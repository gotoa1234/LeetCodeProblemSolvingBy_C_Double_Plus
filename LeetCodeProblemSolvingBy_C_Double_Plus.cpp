#include <unordered_map>
#include "Hard/0087.Scramble_String.cpp"
using namespace Solution87;

int main()
{
    Solution87::Scramble_String useClass;
    Solution87::Scramble_String::Scramble_String_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.isScramble(getTestModel.s1, getTestModel.s2);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.isScramble(getTestModel.s1, getTestModel.s2);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.isScramble(getTestModel.s1, getTestModel.s2);
    return 0;
}