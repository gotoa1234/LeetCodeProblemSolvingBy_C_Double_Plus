#include <unordered_map>
#include "Medium/0166.Fraction_to_Recurring_Decimal.cpp"
using namespace Solution166;

int main()
{
    Solution166::Fraction_to_Recurring_Decimal useClass;
    Solution166::Fraction_to_Recurring_Decimal::Fraction_to_Recurring_Decimal_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.fractionToDecimal(getTestModel.numerator, getTestModel.denominator);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.fractionToDecimal(getTestModel.numerator, getTestModel.denominator);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.fractionToDecimal(getTestModel.numerator, getTestModel.denominator);
    return 0;
}