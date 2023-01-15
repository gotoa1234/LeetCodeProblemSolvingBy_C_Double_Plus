#include <unordered_map>
#include "Medium\0090.Subsets_II.cpp"
using namespace Solution90;

int main()
{
    Solution90::Subsets_II useClass;
    Solution90::Subsets_II::Subsets_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.Subsets_IIWithDup(getTestModel.nums);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.Subsets_IIWithDup(getTestModel.nums);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.Subsets_IIWithDup(getTestModel.nums);
    return 0;
}