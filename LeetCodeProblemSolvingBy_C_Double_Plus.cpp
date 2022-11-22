#include <unordered_map>
#include "0066.Plus_One.cpp"
using namespace Solution66;

int main()
{
    Solution66::Plus_One useClass;
    Solution66::Plus_One::Plus_One_Model getTestModel = useClass.GetTestData001();
    auto result = useClass.plusOne(getTestModel.digits);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.plusOne(getTestModel.digits);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.plusOne(getTestModel.digits);

    return 0;
}