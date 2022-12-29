#include <iostream>
#include <vector>
using namespace std;

namespace Solution7
{
#pragma region Paste to execute 
    /*
    #include "0007.Reverse_Integer.cpp"
    using namespace Solution7;
    using namespace std;

    Solution7::Reverse_Integer useClass;
    Solution7::Reverse_Integer::Reverse_Integer_Model getTestModel = useClass.GetTestData001();
    int result = useClass.reverse(getTestModel.x);
    */
#pragma endregion Paste to execute

    /// <summary>
    /// ������ - ����1��32bit����ơC��^�ۤϪ���ƭ� EX: ��J123 ��^321 
    /// ���u�䴩32bit����� int ���A�A�Y����ɷ����^0
    /// </summary>
    class Reverse_Integer
    {
#pragma region Model
    public:
        class Reverse_Integer_Model
        {
        public:
            int x;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        /// ����G�j�����A�N��J���ƭ�%10���l�ơA�åB��J����/10 ��i�J�U�@�j�� * 10 �B��
        ///     EX: Input = 102 
        /// STEP 1: 102 % 10 => ���o 2 ��J"���G"  102/10  =>���o10
        /// STEP 2: ���G (2 * 10) + (10 % 10) = �ĤG�h���G 20   10 /10 => ���o1
        /// STEP 3: ���G (20 * 10) + (1 % 10) = �ĤT�h���G�A�]�O���൲�G
        ///      Runtim e:   0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
        /// Memory Usage : 5.9 MB,   less than 76.34 % of C++ online submissions for Reverse Integer.
        /// </summary>
        int reverse(int x) {
            int result = 0;
            int remainder = 0;
            while (x)
            {
                if (result > INT_MAX / 10 || result < INT_MIN / 10)
                {
                    return 0;
                }
                remainder = x % 10;
                result = result * 10 + remainder;
                x = x / 10;
            }
            return result;
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Reverse_Integer_Model GetTestData001(void)
        {
            Reverse_Integer_Model result;
            result.x = 123;

            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Reverse_Integer_Model GetTestData002(void)
        {
            Reverse_Integer_Model result;
            result.x = -123;
            return result;
        };

        /// <summary>
        /// ���ո��3
        /// </summary>   
        Reverse_Integer_Model GetTestData003(void)
        {
            Reverse_Integer_Model result;
            result.x = 120;
            return result;
        };
#pragma endregion TestData
    };
}