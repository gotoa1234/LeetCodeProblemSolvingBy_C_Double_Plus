#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

namespace Solution227
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0227.Basic_Calculator_II.cpp"
    using namespace Solution227;

    int main()
    {
        Solution227::Basic_Calculator_II useClass;
        Solution227::Basic_Calculator_II::Basic_Calculator_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.calculate(getTestModel.s);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.calculate(getTestModel.s);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.calculate(getTestModel.s);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �򥻭p���
    /// </summary>
    class Basic_Calculator_II
    {
#pragma region Model
    public:
        class Basic_Calculator_II_Model
        {
        public:
            string s;            
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G���I��2�� 
        ///                1. �B��W�h��* / �� + - �̫�n�`�N�O�_����̫�@�Ӧr��
        ///                2. ���i��X�{�s�u���ƭȡA�n�i��*10���ֶi�p��
        ///      Runtime :  10 ms Beats 97.59 %
        /// Memory Usage : 9.5 MB Beats 96.29 %
        /// </summary>
        /// <returns></returns>        
        int calculate(string s) {
            long result=0;
            long currentResult = 0;
            long tempValue = 0;
            long strLength = s.size();
            char lastOpeatorChar = '+';
            //1. �M���r�ꪺ�r��
            for (int index = 0; index < strLength; index++) 
            {
                char currenChar = s[index];
                //2-1. �ƭȭn���֭p�A�p�G���s���EX:42 => tempValue �e�@���ƭȷ|�O4 �����N�|�Otempvalue = 4 * 10 + 2
                if (currenChar >= '0' && currenChar <= '9') 
                    tempValue = tempValue * 10 + currenChar - '0';   
                //2-2. �r�����B��l�A�Ψ��쩳 
                if (currenChar == '+' || currenChar == '-' || currenChar == '*' || currenChar == '/' || index == strLength - 1) 
                {
                    //3-1. �J��w���N�ۤv���Ȱ��p��
                    if(lastOpeatorChar == '+')
                        currentResult += tempValue;
                    else if (lastOpeatorChar == '-')
                        currentResult -= tempValue;
                    else if (lastOpeatorChar == '*')
                        currentResult *= tempValue;
                    else if (lastOpeatorChar == '/')
                        currentResult /= tempValue;

                    //3-2. �Y��+ - �ɩΨ��쩳�N��e���B�⵲�G�ֶi�ܯu�ꪺ���GResult��
                    //     ���Y��* / �h�i�H�o�{�|��currentResult�O�d�A������* / ��[��W�h
                    if (currenChar == '+' || 
                        currenChar == '-' || 
                        index == strLength - 1) 
                    {
                        result += currentResult;
                        currentResult = 0;
                    }
                    //3-3. ��e���B�⤸�������̫�@�����B�⤸
                    lastOpeatorChar = currenChar;
                    tempValue = 0;
                }
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
        Basic_Calculator_II_Model GetTestData001(void)
        {
            Basic_Calculator_II_Model result;
            result.s = "3+2*2";
            return result;//expect: 7
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Basic_Calculator_II_Model GetTestData002(void)
        {
            Basic_Calculator_II_Model result;
            result.s = "3/2 ";
            return result;//expect: 1
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Basic_Calculator_II_Model GetTestData003(void)
        {
            Basic_Calculator_II_Model result;
            result.s = " 3+5 / 2 ";
            return result;//expect: 5
        };

#pragma endregion TestData
    };
}