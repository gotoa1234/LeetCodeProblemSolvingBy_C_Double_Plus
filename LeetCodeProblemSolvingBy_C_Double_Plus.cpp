#include <unordered_map>
#include "Medium/0148.Sort_List.cpp"
using namespace Solution148;

int main()
{
    Solution148::Sort_List useClass;
    Solution148::Sort_List::Sort_List_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.sortList(getTestModel.head);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.sortList(getTestModel.head);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.sortList(getTestModel.head);
    return 0;
}