#include <unordered_map>
#include "Medium/0179.Largest_Number.cpp"
using namespace Solution179;

int main()
{
    Solution179::Largest_Number useClass;
    Solution179::Largest_Number::Largest_Number_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.largestNumber(getTestModel.nums);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.largestNumber(getTestModel.nums);
    return 0;
}