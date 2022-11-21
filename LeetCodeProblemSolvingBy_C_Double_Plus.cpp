#include <unordered_map>
#include "0064.Minimum_Path_Sum.cpp"
using namespace Solution64;

int main()
{
    Solution64::Minimum_Path_Sum useClass;
    Solution64::Minimum_Path_Sum::Minimum_Path_Sum_Model getTestModel = useClass.GetTestData001();
    int result = useClass.minPathSum(getTestModel.grid);

    getTestModel = useClass.GetTestData002();
    result = useClass.minPathSum(getTestModel.grid);
    return 0;
}