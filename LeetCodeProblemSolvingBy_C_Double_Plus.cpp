#include <unordered_map>
#include "Medium/0097.Interleaving_String.cpp"
using namespace Solution97;

int main()
{
    Solution97::Interleaving_String useClass;
    Solution97::Interleaving_String::Interleaving_String_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.isInterleave(getTestModel.s1, getTestModel.s2, getTestModel.s3);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.isInterleave(getTestModel.s1, getTestModel.s2, getTestModel.s3);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.isInterleave(getTestModel.s1, getTestModel.s2, getTestModel.s3);

    return 0;
}