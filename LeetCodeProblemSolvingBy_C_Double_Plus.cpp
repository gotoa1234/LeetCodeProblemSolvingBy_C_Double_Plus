#include <unordered_map>
#include "Medium/0210.Course_Schedule_II.cpp"
using namespace Solution210;

int main()
{
    Solution210::Course_Schedule_II useClass;
    Solution210::Course_Schedule_II::Course_Schedule_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.findOrder(getTestModel.numCourses, getTestModel.prerequisites);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.findOrder(getTestModel.numCourses, getTestModel.prerequisites);

    return 0;
}