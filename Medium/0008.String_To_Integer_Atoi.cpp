#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution8
{
#pragma region Paste to execute 
    /*
    #include "0008.String_To_Integer_Atoi.cpp"
    using namespace Solution8;
    using namespace std;

    Solution8::String_To_Integer_Atoi useClass;
    Solution8::String_To_Integer_Atoi::String_To_Integer_Atoi_Model getTestModel = useClass.GetTestData001();
    int result = useClass.myAtoi(getTestModel.s);
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �r������: ���w�@�r��A���X�J�쪺�Ĥ@�ռƦr�૬
    /// ���u�䴩32bit����� int ���A�A�Y����ɷ����^0
    /// </summary>
    class String_To_Integer_Atoi
    {
#pragma region Model
    public:
        class String_To_Integer_Atoi_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        /// ����G�w�B�z�ť� => �B�z +,- => �C�Ӧr���}�l�p��A�Y�D�Ʀr�h���X�A�åB�� int ����B�z(-2^32 ~ 2^32)
        ///      Runtime : 3 ms, faster than 82.92% of C++ online submissions for String to Integer(atoi).
        /// Memory Usage : 7 MB,   less than 89.40% of C++ online submissions for String to Integer(atoi).
        /// </summary>
        int myAtoi(string s) {
            int result = 0;

            //�M���ť�
            for (; s[0] == ' ';)
                s.erase(s.begin());
            int sign = 1;

            //+ - �B�z
            if (s[0] == '+' || s[0] == '-')
            {
                sign = s[0] == '-' ? -1 : 1;
                s.erase(s.begin());
            }

            //�r���p��
            for (int index = 0; index < s.size(); index++)
            {
                if (!isdigit(s[index]))
                    break;
                //C++����B�z
                if (result > (INT_MAX - s[index] + 48) / 10)
                {
                    return sign == -1 ? INT_MIN : INT_MAX;
                }
                result = result * 10 + (s[index] - 48);
            }
            return sign * result;
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        String_To_Integer_Atoi_Model GetTestData001(void)
        {
            String_To_Integer_Atoi_Model result;
            result.s = "42";
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        String_To_Integer_Atoi_Model GetTestData002(void)
        {
            String_To_Integer_Atoi_Model result;
            result.s = "   -42";
            return result;
        };

        /// <summary>
        /// ���ո��3
        /// </summary>   
        String_To_Integer_Atoi_Model GetTestData003(void)
        {
            String_To_Integer_Atoi_Model result;
            result.s = "4193 with words";
            return result;
        };
#pragma endregion TestData
    };
}