#include <unordered_map>
#include "Hard/0149.Max_Points_on_a_Line.cpp"
using namespace Solution149;

int main()
{
    Solution149::Max_Points_on_a_Line useClass;
    Solution149::Max_Points_on_a_Line::Max_Points_on_a_Line_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.maxPoints(getTestModel.points);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.maxPoints(getTestModel.points);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.maxPoints(getTestModel.points);
}