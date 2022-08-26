#include <vector>
#include "0070.Climbing_Stairs.cpp"
using namespace Solution70;

int main()
{
    Solution70::Climbing_Stairs useClass;
    Solution70::Climbing_Stairs::Climbing_Stairs_Model getTestModel = useClass.GetTestData001();
    int result = useClass.climbStairs(getTestModel.n);

    getTestModel = useClass.GetTestData002();
    result = useClass.climbStairs(getTestModel.n);
    result = useClass.climbStairs(4);
    result = useClass.climbStairs(5);
    result = useClass.climbStairs(6);
    result = useClass.climbStairs(7);

    return 0;
}