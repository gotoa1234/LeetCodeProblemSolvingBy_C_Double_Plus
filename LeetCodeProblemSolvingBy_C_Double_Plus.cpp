#include <unordered_map>
#include "0076.Minimum_Window_Substring.cpp"
using namespace Solution76;

int main()
{
    Solution76::Minimum_Window_Substring useClass;
    Solution76::Minimum_Window_Substring::Minimum_Window_Substring_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.minWindow(getTestModel.s, getTestModel.t);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.minWindow(getTestModel.s, getTestModel.t);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.minWindow(getTestModel.s, getTestModel.t);
    return 0;
}