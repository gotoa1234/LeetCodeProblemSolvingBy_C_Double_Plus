#include <unordered_map>
#include "Medium/0227.Basic_Calculator_II.cpp"
using namespace Solution227;

int main()
{
    Solution227::Basic_Calculator_II useClass;
    Solution227::Basic_Calculator_II::Basic_Calculator_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.calculate(getTestModel.s);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.calculate(getTestModel.s);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.calculate(getTestModel.s);
    return 0;
}