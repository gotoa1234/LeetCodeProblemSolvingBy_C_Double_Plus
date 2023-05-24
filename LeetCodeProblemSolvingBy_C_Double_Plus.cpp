#include <unordered_map>
#include "Medium/0207.Course_Schedule.cpp"
using namespace Solution207;

int main()
{
    Solution207::Course_Schedule useClass;
    Solution207::Course_Schedule::Course_Schedule_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.canFinish(getTestModel.numCourses, getTestModel.prerequisites);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.canFinish(getTestModel.numCourses, getTestModel.prerequisites);

    return 0;
}