#include <unordered_map>
#include "0077.Combinations.cpp"
using namespace Solution77;

int main()
{
    Solution77::Combinations useClass;
    Solution77::Combinations::Combinations_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.combine(getTestModel.n, getTestModel.k);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.combine(getTestModel.n, getTestModel.k);
    return 0;
}