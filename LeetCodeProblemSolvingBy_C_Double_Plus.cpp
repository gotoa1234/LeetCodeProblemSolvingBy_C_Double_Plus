#include <unordered_map>
#include "Hard/0140.Word_Break_II.cpp"
using namespace Solution140;

int main()
{
    Solution140::Word_Break_II useClass;
    Solution140::Word_Break_II::Word_Break_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);
    return 0;
}