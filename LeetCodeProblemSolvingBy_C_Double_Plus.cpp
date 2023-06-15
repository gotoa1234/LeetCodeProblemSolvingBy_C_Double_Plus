#include <unordered_map>
#include "Medium/0162.Find_Peak_Element.cpp"
using namespace Solution162;

int main()
{
    Solution162::Find_Peak_Element useClass;
    Solution162::Find_Peak_Element::Find_Peak_Element_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.findMin(getTestModel.nums);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.findMin(getTestModel.nums);
    return 0;
}