#include <unordered_map>
#include "0078.Subsets.cpp"
using namespace Solution78;

int main()
{
    Solution78::Subsets useClass;
    Solution78::Subsets::Subsets_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.subsets(getTestModel.nums);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.subsets(getTestModel.nums);
    return 0;
}