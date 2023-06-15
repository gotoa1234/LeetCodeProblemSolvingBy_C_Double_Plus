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

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.fractionToDecimal(getTestModel.numerator, getTestModel.denominator);
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
        ///         思路：主要克服兩個問題 
        ///               1. 用long取得整數Int的餘數結果。當Int爆了，表示進入"無理數"
        ///               2. 需要使用HashTable紀錄餘數值，若有重複的餘數值表示進入迴圈
        ///      Runtime：  0 ms Beats 100 %
        /// Memory Usage：6.2 MB Beats 94.84 %
        /// </summary>
        /// <returns></returns>
    public:
        string fractionToDecimal(int numerator, int denominator) {
            //防呆
            if (numerator == 0) 
                return "0";

            //1. 處理結果正負號
            string result;
            int sign = 1;            
            if ((numerator < 0 && denominator >0) ||
                (numerator > 0 && denominator < 0))
            {
                sign *= -1;
            }
            if (sign == -1)
                result.insert(result.begin(), '-');

            //2-1. 處理小數點前的整數值
            long numeratorPositive = abs(numerator);
            long denominatorPositive = abs(denominator);
            long remainder = numeratorPositive % denominatorPositive;
            result.append(to_string(numeratorPositive / denominatorPositive));
            
            //2-2. 在處理數值後若無餘數，表示沒有小數點，直接跳出
            if (remainder == 0)
                return result;
            result.append(".");

            //3-1. 使用 hashTable 紀錄餘數是否開始重複(定義：下一位的餘數值 % 分數值，此時的餘數是否已在HashTable)
            unordered_map<int, int> hashMap;
            //3-2. 開始迴圈跑。有2個可能會為0 => 1. 整除為0   2.int爆了，所以為0
            while (remainder != 0) 
            {
                //4-2. 找到重複
                if (hashMap.find(remainder) != hashMap.end())
                {
                    //5. 給結果小數點後面的數值補上()
                    result.insert(result.begin() + hashMap[remainder], '(');
                    result.append(")");
                    break;
                }
                //4-1. 逐步往下一位(乘以10)取餘數
                hashMap[remainder] = result.size();
                remainder *= 10;
                result.append(to_string(remainder / denominatorPositive));
                remainder = remainder % denominatorPositive;
            }
            return result;
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
            result.denominator = 334;
            return result;//expect: 0.(012)
        };

#pragma endregion TestData
    };
}