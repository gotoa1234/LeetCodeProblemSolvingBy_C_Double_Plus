#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution165
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0165.Compare_Version_Numbers.cpp"
    using namespace Solution165;

    int main()
    {
        Solution165::Compare_Version_Numbers useClass;
        Solution165::Compare_Version_Numbers::Compare_Version_Numbers_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.compareVersion(getTestModel.version1, getTestModel.version2);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.compareVersion(getTestModel.version1, getTestModel.version2);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ���������
    /// </summary>
    class Compare_Version_Numbers
    {
#pragma region Model
    public:
        class Compare_Version_Numbers_Model
        {
        public:
            string version1;
            string version2;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ����G�bC++������·ШS��split���Φr��A�]���ݭn�ۦ��`.`����
        ///               �C����V1�PV2 `.`�e���r�갵��ƭȪ�����A�Y���䤤�@�Ӫ����j�N���X
        ///               �_�h�@�����A�Y�᳣̫�L�k���X�j�p�A��ܬ۵��^��0
        ///      Runtime�G  0 ms Beats 100 %
        /// Memory Usage�G 6.2 MB Beats 68.31 %
        /// </summary>
        /// <returns></returns>
    public:
        int compareVersion(string version1, string version2) 
        {
            string v1CompareString;
            string v2CompareString;
            int v1MoveIndex = 0;
            int v2MoveIndex = 0;
            //1. �����Ӫ���
            for (int v1Index = 0, v2Index = 0;
                v1Index < version1.size() || v2Index < version2.size();
				v1Index++, v2Index++)
            {
                //2-1. ���o����1 �b.�H�e�����
                while (v1Index < version1.size() && version1[v1Index] != '.')
                {
                    v1CompareString.push_back(version1[v1Index]);
                    v1Index++;
                }
                
                //2-2. ���o����2 �b.�H�e�����
                while (v2Index < version2.size() && version2[v2Index] != '.')
                {
                    v2CompareString.push_back(version2[v2Index]);
                    v2Index++;
                }
                
                //3. �ন��ƨåB���
                auto v1RealVersion = atoi(v1CompareString.c_str());
                auto v2RealVersion = atoi(v2CompareString.c_str());
                if (v1RealVersion > v2RealVersion)
                    return 1;
                else if (v1RealVersion < v2RealVersion)
                    return -1;
                //4. ��ܭn���U�@��.�e���ƭȤ���A�o�����Ȧs��ƲM��
                v1CompareString.clear();
                v2CompareString.clear();
            }
            //5. �p�GVersion1 �P Version2 ��������A��ܥu������(0)���G
            return 0;
        }


    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Compare_Version_Numbers_Model GetTestData001(void)
        {
            Compare_Version_Numbers_Model result;
            result.version1 = "1.01";
            result.version2 = "1.001";
            return result;//expect: 0
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Compare_Version_Numbers_Model GetTestData002(void)
        {
            Compare_Version_Numbers_Model result;
            result.version1 = "001.0";
            result.version2 = "00101.0.0";
            return result;//expect: 0           
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Compare_Version_Numbers_Model GetTestData003(void)
        {
            Compare_Version_Numbers_Model result;
            result.version1 = "0.1";
            result.version2 = "1.1";
            return result;//expect: -1
        };

#pragma endregion TestData
    };
}