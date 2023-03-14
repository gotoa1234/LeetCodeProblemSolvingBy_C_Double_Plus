#include <unordered_map>
#include "Medium/0143.Reorder_List.cpp"
using namespace Solution143;
using namespace std;

int main()
{
    Solution143::Reorder_List useClass;
    Solution143::Reorder_List::Reorder_List_Model getTestModel = useClass.GetTestData001();
    useClass.reorderList(getTestModel.head);

    getTestModel = useClass.GetTestData002();
    useClass.reorderList(getTestModel.head);

    return 0;
}