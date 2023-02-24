#include <unordered_map>
#include "Medium/0129.Sum_Root_to_Leaf_Numbers.cpp"
using namespace Solution129;

int main()
{
    Solution129::Sum_Root_to_Leaf_Numbers useClass;
    Solution129::Sum_Root_to_Leaf_Numbers::Sum_Root_to_Leaf_Numbers_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.sumNumbers(getTestModel.root);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.sumNumbers(getTestModel.root);
    return 0;
}