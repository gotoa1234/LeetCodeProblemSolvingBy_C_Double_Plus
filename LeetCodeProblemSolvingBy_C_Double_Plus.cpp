#include <unordered_map>
#include "0063.Unique_Paths_II.cpp"
using namespace Solution63;

int main()
{
    Solution63::Unique_Paths_II useClass;
    Solution63::Unique_Paths_II::Unique_Paths_II_Model getTestModel = useClass.GetTestData001();
    int result = useClass.uniquePathsWithObstacles(getTestModel.obstacleGrid);

    getTestModel = useClass.GetTestData002();
    result = useClass.uniquePathsWithObstacles(getTestModel.obstacleGrid);

    getTestModel = useClass.GetTestData003();
    result = useClass.uniquePathsWithObstacles(getTestModel.obstacleGrid);
    return 0;
}