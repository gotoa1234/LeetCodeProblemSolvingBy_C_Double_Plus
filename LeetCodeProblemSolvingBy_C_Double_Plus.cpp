#include <unordered_map>
#include "0062.Unique_Paths.cpp"
using namespace Solution62;

int main()
{
    Solution62::Unique_Paths useClass;
    Solution62::Unique_Paths::Unique_Paths_Model getTestModel = useClass.GetTestData001();
    int result = useClass.uniquePaths(getTestModel.m, getTestModel.n);
    result = useClass.uniquePaths2(getTestModel.m, getTestModel.n);
    getTestModel = useClass.GetTestData002();
    result = useClass.uniquePaths(getTestModel.m, getTestModel.n);
   
    return 0;
}