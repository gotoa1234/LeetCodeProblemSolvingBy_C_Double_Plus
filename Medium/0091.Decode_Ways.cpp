#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

namespace Solution91
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0091.Decode_Ways.cpp"
    using namespace Solution91;

    int main()
    {
        Solution91::Decode_Ways useClass;
        Solution91::Decode_Ways::Decode_Ways_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.grayCode(getTestModel.n);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.grayCode(getTestModel.n);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.grayCode(getTestModel.n);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �ѽX�覡
    /// </summary>
    class Decode_Ways
    {
#pragma region Model
    public:
        class Decode_Ways_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G��1x ~ 26�������n�֭p2���A�Y�D�o�d�򪺼ƭȫh���ƫ�1 EX: 4567�o�ر��p����1
        ///                �A�Q�β֭p���覡�A�ϥ�2���ܼơA���O����e�֭p�P�e���֭p
        ///      Runtime :  0 ms Beats  100 %
        /// Memory Usage :  6 MB Beats 94.8 %
        /// </summary>
        /// <returns></returns>
        int numDecodings(string s) {
            
            if (s.empty() || s[0] == '0') 
                return 0;
            int totalCount = 1, lastCount = 1;
            //1. �M���C�Ӧr��
            for (int index = 1; index < s.size(); ++index)
            {
                //2-1. ��0�ɵ������i��զ�
                if (s[index] == '0') //�۷����L�����A���O�٭n�P�_ '10' �o�ت��p�A�ҥH���iContinue
                    totalCount = 0;

                //3-1. 1X ~ 26 ����(A~Z) �����i�զ�
                if (  s[index - 1] == '1' || 
                     (s[index - 1] == '2' && s[index] <= '6')
                   ) 
                {
                    totalCount = totalCount + lastCount;
                    lastCount = totalCount - lastCount;
                }
                else //3-2. �̫�@�إi��O�W�߼ƭ�
                {
                    lastCount = totalCount;//�ȫO������
                }
            }
            return totalCount;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Decode_Ways_Model GetTestData001(void)
        {
            Decode_Ways_Model result;
            result.s = "12";
            return result;//expect: 2
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Decode_Ways_Model GetTestData002(void)
        {
            Decode_Ways_Model result;
            result.s = "2212451026";
            return result;//expect: 3  Re:226
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Decode_Ways_Model GetTestData003(void)
        {
            Decode_Ways_Model result;
            result.s = "06";
            return result;//expect: 0
        };

        /// <summary>
       /// test 4
       /// </summary>   
        Decode_Ways_Model GetTestData004(void)
        {
            Decode_Ways_Model result;
            result.s = "2222";
            return result;//expect: 5
        };
#pragma endregion TestData
    };
}