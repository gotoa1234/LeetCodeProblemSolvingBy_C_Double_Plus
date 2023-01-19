#include <unordered_map>
#include "Medium/0095.Unique_Binary_Search_Trees_II.cpp"
using namespace Solution95;

int main()
{
    Solution95::Unique_Binary_Search_Trees_II useClass;
    Solution95::Unique_Binary_Search_Trees_II::Unique_Binary_Search_Trees_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.generateTrees(getTestModel.n);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.generateTrees(getTestModel.n);

    return 0;
}