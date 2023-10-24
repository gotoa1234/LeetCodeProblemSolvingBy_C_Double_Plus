#include <iostream>
using namespace std;

namespace Solution9
{
#pragma region Paste to execute 
    /*
#include "Easy\0009.Palindrome_Number.cpp"
using namespace Solution9;
using namespace std;

int main()
{
    Solution9::Palindrome_Number useClass;
    Solution9::Palindrome_Number::Palindrome_Number_Model getTestModel = useClass.GetTestData001();
    bool result = useClass.myAtoi(getTestModel.x);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.myAtoi(getTestModel.x);

    getTestModel = useClass.GetTestData003();
    auto result3 = useClass.myAtoi(getTestModel.x);

    getTestModel = useClass.GetTestData004();
    auto result4 = useClass.myAtoi(getTestModel.x);

    getTestModel = useClass.GetTestData005();
    auto result5 = useClass.myAtoi(getTestModel.x);
    return 0;
}
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �O�_���^����
    /// ���ন�r���²��ALeetCode��ĳ����String���լD��
    /// </summary>
    class Palindrome_Number
    {
#pragma region Model
    public:
        class Palindrome_Number_Model
        {
        public:
            int x;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///          ����G�ư��t��/��0 => ��ƭ˴� => ����P�_ => �̫�P�_��ƭ˴��ȬO�_�P��ȬۦP
        ///      Runtime :  12 ms, faster than 87.84 % of C++ online submissions for Palindrome Number.
        /// Memory Usage : 5.8 MB,   less than 91.05 % of C++ online submissions for Palindrome Number.
        /// </summary>
        bool myAtoi(int x) {
            if (x < 0)
                return false;
            if (x != 0 && x % 10 == 0)
                return false;

            int tmep = x;
            int result = 0;
            int remainder = 0;
            while (tmep)
            {
                remainder = tmep % 10;
                if (result > (INT_MAX - (remainder)) / 10)
                {
                    return false;
                }
                result = result * 10 + remainder;
                tmep = tmep / 10;
            }
            return result == x ? true : false;
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Palindrome_Number_Model GetTestData001(void)
        {
            Palindrome_Number_Model result;
            result.x = 121;//
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Palindrome_Number_Model GetTestData002(void)
        {
            Palindrome_Number_Model result;
            result.x = -121;
            return result;
        };

        /// <summary>
        /// ���ո��3
        /// </summary>   
        Palindrome_Number_Model GetTestData003(void)
        {
            Palindrome_Number_Model result;
            result.x = 10;
            return result;
        };

        /// <summary>
        /// ���ո��4
        /// </summary>   
        Palindrome_Number_Model GetTestData004(void)
        {
            Palindrome_Number_Model result;
            result.x = 123;
            return result;
        };

        /// <summary>
        /// ���ո��5
        /// </summary>   
        Palindrome_Number_Model GetTestData005(void)
        {
            Palindrome_Number_Model result;
            result.x = 1234567899;
            return result;
        };
        
#pragma endregion TestData
    };
}