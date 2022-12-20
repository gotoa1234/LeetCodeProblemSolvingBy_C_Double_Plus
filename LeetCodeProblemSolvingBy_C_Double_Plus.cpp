#include <unordered_map>
#include "0068.Text_Justification.cpp"
using namespace Solution68;

int main()
{
    Solution68::Text_Justification useClass;
    Solution68::Text_Justification::Text_Justification_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.fullJustify(getTestModel.words, getTestModel.maxWidth);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.fullJustify(getTestModel.words, getTestModel.maxWidth);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.fullJustify(getTestModel.words, getTestModel.maxWidth);

    return 0;
}