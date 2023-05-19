#include <unordered_map>
#include "Medium/0150.Evaluate_Reverse_Polish_Notation.cpp"
using namespace Solution150;

int main()
{
    Solution150::Evaluate_Reverse_Polish_Notation useClass;
    Solution150::Evaluate_Reverse_Polish_Notation::Evaluate_Reverse_Polish_Notation_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.evalRPN(getTestModel.tokens);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.evalRPN(getTestModel.tokens);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.evalRPN(getTestModel.tokens);
    return 0;
}