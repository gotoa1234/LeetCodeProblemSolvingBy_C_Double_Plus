#include <unordered_map>
#include "Medium/0152.Maximum_Product_Subarray.cpp"
using namespace Solution152;

int main()
{
    Solution152::Maximum_Product_Subarray useClass;
    Solution152::Maximum_Product_Subarray::Maximum_Product_Subarray_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.maxProduct(getTestModel.nums);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.maxProduct(getTestModel.nums);
    return 0;
}