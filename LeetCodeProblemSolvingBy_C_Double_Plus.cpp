#include <unordered_map>
#include "Hard/0154.Find_Minimum_in_Rotated_Sorted_Array_II.cpp"
using namespace Solution154;

int main()
{
    Solution154::Find_Minimum_in_Rotated_Sorted_Array_II useClass;
    Solution154::Find_Minimum_in_Rotated_Sorted_Array_II::Find_Minimum_in_Rotated_Sorted_Array_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.findMin(getTestModel.nums);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.findMin(getTestModel.nums);

    return 0;
}