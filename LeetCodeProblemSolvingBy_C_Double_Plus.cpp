#include <unordered_map>
#include "Easy/0136.Single_Number.cpp"
using namespace Solution136;

int main()
{
    Solution136::Single_Number useClass;
    Solution136::Single_Number::Single_Number_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.singleNumber(getTestModel.nums);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.singleNumber(getTestModel.nums);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.singleNumber(getTestModel.nums);
    return 0;
}