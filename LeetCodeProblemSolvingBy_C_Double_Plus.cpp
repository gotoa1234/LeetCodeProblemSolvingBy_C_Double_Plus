#include <unordered_map>
#include "0069.Sqrt_x.cpp"
using namespace Solution69;

int main()
{
    Solution69::Sqrt_x useClass;
    Solution69::Sqrt_x::Sqrt_x_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.mySqrt(getTestModel.x);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.mySqrt(getTestModel.x);

    return 0;
}