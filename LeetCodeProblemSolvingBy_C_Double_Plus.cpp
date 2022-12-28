#include <unordered_map>
#include "0080.Remove_Duplicates_from_Sorted_Array_II.cpp"
using namespace Solution80;

int main()
{
    Solution80::Remove_Duplicates_from_Sorted_Array_II useClass;
    Solution80::Remove_Duplicates_from_Sorted_Array_II::Remove_Duplicates_from_Sorted_Array_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.removeDuplicates(getTestModel.nums);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.removeDuplicates(getTestModel.nums);

    return 0;
}