#include <unordered_map>
#include "Medium/0096.Unique_Binary_Search_Trees.cpp"
using namespace Solution96;

int main()
{
    Solution96::Unique_Binary_Search_Trees useClass;
    Solution96::Unique_Binary_Search_Trees::Unique_Binary_Search_Trees_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.numTrees(getTestModel.n);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.numTrees(getTestModel.n);

    return 0;
}