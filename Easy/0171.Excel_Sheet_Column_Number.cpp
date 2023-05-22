#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution171
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Easy/0171.Excel_Sheet_Column_Number.cpp"
    using namespace Solution171;

    int main()
    {
        Solution171::Excel_Sheet_Column_Number useClass;
        Solution171::Excel_Sheet_Column_Number::Excel_Sheet_Column_Number_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.titleToNumber(getTestModel.columnTitle);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.titleToNumber(getTestModel.columnTitle);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.titleToNumber(getTestModel.columnTitle);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �̦h������
    /// </summary>
    class Excel_Sheet_Column_Number
    {
#pragma region Model
    public:
        class Excel_Sheet_Column_Number_Model
        {
        public:
            string columnTitle;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�̷��D�ت��N����R�A��26�i�쪺�p��A�̫�@�Ӭ�26^0 �˼ƲĤG�Ӭ�26^1 �]��
        ///                ��for�j��q�᭱�}�l�p��C��char �M���[�`��N�O���G
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 6.3 MB Beats 13.30 %
        /// </summary>
        /// <returns></returns>        
        int titleToNumber(string columnTitle) {
            //A~Z(ASCII): 65 ~ 92 
            int result = 0;
            int maxLength = columnTitle.size();
            for (int index = maxLength - 1; index >= 0; index--)
            {
                result += (columnTitle[index] - 64) * pow(26, maxLength - 1 - index);
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
        Excel_Sheet_Column_Number_Model GetTestData001(void)
        {
            Excel_Sheet_Column_Number_Model result;
            result.columnTitle = "A";
            return result;//expect: 1
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Excel_Sheet_Column_Number_Model GetTestData002(void)
        {
            Excel_Sheet_Column_Number_Model result;
            result.columnTitle = "AB";
            return result;//expect:  28  B=2 + A =26 1
        };


        /// <summary>
        /// test 3
        /// </summary>   
        Excel_Sheet_Column_Number_Model GetTestData003(void)
        {
            Excel_Sheet_Column_Number_Model result;
            result.columnTitle = "ZY";
            return result;//expect:  701    26*26 + 25
        };
#pragma endregion TestData
    };
}