#include <unordered_map>
#include "Medium/0436.Find_Right_Interval.cpp"
using namespace Solution436;

int main()
{
    Solution436::Find_Right_Interval useClass;
    Solution436::Find_Right_Interval::Find_Right_Interval_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.findRightInterval(getTestModel.intervals);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.findRightInterval(getTestModel.intervals);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.findRightInterval(getTestModel.intervals);
    return 0;
}