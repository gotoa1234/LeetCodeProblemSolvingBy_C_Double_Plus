#include "Medium\0117.Populating_Next_Right_Pointers_in_Each_Node_II.cpp"
using namespace Solution117;
using namespace std;

int main()
{
    Solution117::Populating_Next_Right_Pointers_in_Each_Node_II useClass;
    Solution117::Populating_Next_Right_Pointers_in_Each_Node_II::Populating_Next_Right_Pointers_in_Each_Node_II_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.connect(getTestModel.root);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.connect(getTestModel.root);
}