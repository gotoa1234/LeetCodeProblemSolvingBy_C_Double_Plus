#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution166
{
#pragma region Paste to execute 
    /*
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
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 分數到循環小數
    /// </summary>
    class Fraction_to_Recurring_Decimal
    {
#pragma region Model
    public:
        class Fraction_to_Recurring_Decimal_Model
        {
        public:
            int numerator;
            int denominator;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路：         
        ///      Runtime：
        /// Memory Usage：
        /// </summary>
        /// <returns></returns>
    public:
        string fractionToDecimal(int numerator, int denominator) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Fraction_to_Recurring_Decimal_Model GetTestData001(void)
        {
            Fraction_to_Recurring_Decimal_Model result;
            result.numerator = 1;
            result.denominator = 2;
            return result;//expect: 0.5
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Fraction_to_Recurring_Decimal_Model GetTestData002(void)
        {
            Fraction_to_Recurring_Decimal_Model result;
            result.numerator = 2;
            result.denominator = 1;
            return result;//expect: 2            
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Fraction_to_Recurring_Decimal_Model GetTestData003(void)
        {
            Fraction_to_Recurring_Decimal_Model result;
            result.numerator = 4;
            result.denominator = 333;
            return result;//expect: 0.(012)
        };

#pragma endregion TestData
    };
}