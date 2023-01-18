#include <unordered_map>
#include "Medium/0091.Decode_Ways.cpp"
using namespace Solution91;

int main()
{
    Solution91::Decode_Ways useClass;
    Solution91::Decode_Ways::Decode_Ways_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.numDecodings(getTestModel.s);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.numDecodings(getTestModel.s);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.numDecodings(getTestModel.s);

    return 0;
}