#include <unordered_map>
#include "Medium/0139.Word_Break.cpp"
using namespace Solution139;

int main()
{
    Solution139::Word_Break useClass;
    Solution139::Word_Break::Word_Break_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);
    return 0;
}