#include <unordered_map>
#include "Medium/0089.Gray_Code.cpp"
using namespace Solution89;

int main()
{
    Solution89::Gray_Code useClass;
    Solution89::Gray_Code::Gray_Code_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.grayCode(getTestModel.n);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.grayCode(getTestModel.n);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.grayCode(getTestModel.n);
    return 0;
}