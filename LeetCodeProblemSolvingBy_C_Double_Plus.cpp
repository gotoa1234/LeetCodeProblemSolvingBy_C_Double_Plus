#include <unordered_map>
#include "0067.Add_Binary.cpp"
using namespace Solution67;

int main()
{
    Solution67::Add_Binary useClass;
    Solution67::Add_Binary::Add_Binary_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.addBinary(getTestModel.a, getTestModel.b);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.addBinary(getTestModel.a, getTestModel.b);

    return 0;
}