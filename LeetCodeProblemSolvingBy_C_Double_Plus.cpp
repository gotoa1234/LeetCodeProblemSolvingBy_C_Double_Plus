#include <vector>
#include "Easy\0001_two_sum.cpp"
using namespace Solution1;
int main()
{
    Solution1::Two_Sum useClass;
    Solution1::Two_Sum::Two_Sum_Model getTestModel = useClass.GetTestData001();
    vector<int> result = useClass.twoSum(getTestModel.nums, getTestModel.target);
    return 0;
}