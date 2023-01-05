#include <unordered_map>
#include "Hard\0084.Largest_Rectangle_in_Histogram.cpp"
using namespace Solution84;

int main()
{
    Solution84::Largest_Rectangle_in_Histogram useClass;
    Solution84::Largest_Rectangle_in_Histogram::Largest_Rectangle_in_Histogram_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.largestRectangleArea(getTestModel.heights);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.largestRectangleArea(getTestModel.heights);

    return 0;
}