#include <unordered_map>
#include "easy\0083.Remove_Duplicates_from_Sorted_List.cpp"
using namespace Solution83;

int main()
{
    Solution83::Remove_Duplicates_from_Sorted_List useClass;
    Solution83::Remove_Duplicates_from_Sorted_List::Remove_Duplicates_from_Sorted_List_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.deleteDuplicates(getTestModel.head);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.deleteDuplicates(getTestModel.head);

    return 0;
}