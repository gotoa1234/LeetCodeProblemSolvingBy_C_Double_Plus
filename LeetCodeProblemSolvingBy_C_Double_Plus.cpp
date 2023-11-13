#include "Easy\0021.Merge_Two_Sorted_Lists.cpp"
using namespace Solution21;
using namespace std;

int main()
{
    Solution21::Merge_Two_Sorted_Lists useClass;
    Solution21::Merge_Two_Sorted_Lists::Merge_Two_Sorted_Lists_Model getTestModel = useClass.GetTestData001();
    Solution21::Merge_Two_Sorted_Lists::ListNode* result = useClass.mergeTwoLists(getTestModel.list1, getTestModel.list2);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.mergeTwoLists(getTestModel.list1, getTestModel.list2);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.mergeTwoLists(getTestModel.list1, getTestModel.list2);

    getTestModel = useClass.GetTestData004();
    auto result4 = useClass.mergeTwoLists(getTestModel.list1, getTestModel.list2);
    return 0;
}
