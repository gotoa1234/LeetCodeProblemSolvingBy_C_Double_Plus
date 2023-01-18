#include <unordered_map>
#include "Medium/0092.Reverse_Linked_List_II.cpp"
using namespace Solution92;

int main()
{
    Solution92::Reverse_Linked_List_II useClass;
    Solution92::Reverse_Linked_List_II::Reverse_Linked_List_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.reverseBetween(getTestModel.head, getTestModel.left, getTestModel.right);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.reverseBetween(getTestModel.head, getTestModel.left, getTestModel.right);

    return 0;
}