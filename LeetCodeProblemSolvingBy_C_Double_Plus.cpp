#include <unordered_map>
#include "Medium/0147.Insertion_Sort_List.cpp"
using namespace Solution147;

int main()
{
    Solution147::Insertion_Sort_List useClass;
    Solution147::Insertion_Sort_List::Insertion_Sort_List_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.insertionSortList(getTestModel.head);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.insertionSortList(getTestModel.head);

    return 0;
}