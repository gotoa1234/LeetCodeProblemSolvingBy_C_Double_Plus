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
    /// ���ƨ�`���p��
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
        ///         ����G�D�n�J�A��Ӱ��D 
        ///               1. ��long���o���Int���l�Ƶ��G�C��Int�z�F�A��ܶi�J"�L�z��"
        ///               2. �ݭn�ϥ�HashTable�����l�ƭȡA�Y�����ƪ��l�ƭȪ�ܶi�J�j��
        ///      Runtime�G  0 ms Beats 100 %
        /// Memory Usage�G6.2 MB Beats 94.84 %
        /// </summary>
        /// <returns></returns>
    public:
        string fractionToDecimal(int numerator, int denominator) {
            //���b
            if (numerator == 0) 
                return "0";

            //1. �B�z���G���t��
            string result;
            int sign = 1;            
            if ((numerator < 0 && denominator >0) ||
                (numerator > 0 && denominator < 0))
            {
                sign *= -1;
            }
            if (sign == -1)
                result.insert(result.begin(), '-');

            //2-1. �B�z�p���I�e����ƭ�
            long numeratorPositive = abs(numerator);
            long denominatorPositive = abs(denominator);
            long remainder = numeratorPositive % denominatorPositive;
            result.append(to_string(numeratorPositive / denominatorPositive));
            
            //2-2. �b�B�z�ƭȫ�Y�L�l�ơA��ܨS���p���I�A�������X
            if (remainder == 0)
                return result;
            result.append(".");

            //3-1. �ϥ� hashTable �����l�ƬO�_�}�l����(�w�q�G�U�@�쪺�l�ƭ� % ���ƭȡA���ɪ��l�ƬO�_�w�bHashTable)
            unordered_map<int, int> hashMap;
            //3-2. �}�l�j��]�C��2�ӥi��|��0 => 1. �㰣��0   2.int�z�F�A�ҥH��0
            while (remainder != 0) 
            {
                //4-2. ��쭫��
                if (hashMap.find(remainder) != hashMap.end())
                {
                    //5. �����G�p���I�᭱���ƭȸɤW()
                    result.insert(result.begin() + hashMap[remainder], '(');
                    result.append(")");
                    break;
                }
                //4-1. �v�B���U�@��(���H10)���l��
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