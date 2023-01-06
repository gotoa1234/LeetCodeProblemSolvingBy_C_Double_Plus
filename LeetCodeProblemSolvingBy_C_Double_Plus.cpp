#include <unordered_map>
#include "Hard/0085.Maximal_Rectangle.cpp"
using namespace Solution85;

int main()
{
    Solution85::Maximal_Rectangle useClass;
    Solution85::Maximal_Rectangle::Maximal_Rectangle_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.maximalRectangle(getTestModel.matrix);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.maximalRectangle(getTestModel.matrix);

    return 0;
}