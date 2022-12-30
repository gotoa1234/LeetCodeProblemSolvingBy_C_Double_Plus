#include <unordered_map>
#include "medium/0082.Remove_Duplicates_from_Sorted_List_II.cpp"
using namespace Solution82;

int main()
{
    Solution82::Remove_Duplicates_from_Sorted_List_II useClass;
    Solution82::Remove_Duplicates_from_Sorted_List_II::Remove_Duplicates_from_Sorted_List_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.deleteDuplicates(getTestModel.head);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.deleteDuplicates(getTestModel.head);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.deleteDuplicates(getTestModel.head);
    return 0;
}