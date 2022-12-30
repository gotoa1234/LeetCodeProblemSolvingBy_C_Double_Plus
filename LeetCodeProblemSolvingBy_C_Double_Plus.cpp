#include <unordered_map>
#include "Medium/0081.Search_in_Rotated_Sorted_Array_II.cpp"
using namespace Solution81;

int main()
{
    Solution81::Search_in_Rotated_Sorted_Array_II useClass;
    Solution81::Search_in_Rotated_Sorted_Array_II::Search_in_Rotated_Sorted_Array_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.search(getTestModel.nums, getTestModel.target);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.search(getTestModel.nums, getTestModel.target);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.search(getTestModel.nums, getTestModel.target);
    return 0;
}