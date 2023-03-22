#include <unordered_map>
#include "Medium/0138.Copy_List_with_Random_Pointer.cpp"
using namespace Solution138;

int main()
{
    Solution138::Copy_List_with_Random_Pointer useClass;
    Solution138::Copy_List_with_Random_Pointer::Copy_List_with_Random_Pointer_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.copyRandomList(getTestModel.head);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.copyRandomList(getTestModel.head);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.copyRandomList(getTestModel.head);

    return 0;
}