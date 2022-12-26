#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution76
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0076.Minimum_Window_Substring.cpp"
    using namespace Solution76;

    int main()
    {
        Solution76::Minimum_Window_Substring useClass;
        Solution76::Minimum_Window_Substring::Minimum_Window_Substring_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.minWindow(getTestModel.s, getTestModel.t);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.minWindow(getTestModel.s, getTestModel.t);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.minWindow(getTestModel.s, getTestModel.t);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �̤p�����l�r��
    /// </summary>
    class Minimum_Window_Substring
    {
#pragma region Model
    public:
        class Minimum_Window_Substring_Model
        {
        public:
            string s;
            string t;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�ݭn�Q�Τ@��ascii��������Ҧ��r���X�{�����ơA�åB�Q�ηưʪ��覡��sleftIndex�PrightIndex��X��
        ///               ���D���ǽ����A�i�����ݥN�X�����B�J���{
        ///      Runtime :   7 ms Beats 97.85 %
        /// Memory Usage : 7.8 MB Beats 93.94 %
        /// </summary>
        /// <returns></returns>
        string minWindow(string s, string t) 
        {
            //��A=65 z=122 so 122 - 65 = 57+1 �ݭn58���Ŷ���r��
            int asciiRecordTable[58] = { 0 };
            //1. Ascii ����
            int useCount = 0;
            for (int index = 0; index < t.size(); index++) 
            {
                if (asciiRecordTable[t[index] - 65] == 0)
                    useCount++;
                asciiRecordTable[t[index] - 65]++;
            }
            
            //2. �Ʈ� - �@�w�O����X�ŦXt�r�ꪺ�Ҧ��r��
            int targetEbdIndex = INT_MAX;
            int targetStartIndex = 0;
            for(int leftIndex = 0, rightIndex = 0; rightIndex < s.size(); rightIndex++)
            {
                //2-1. ����useCount = 0 ��ܩҦ���t�r�����X�{�F
                asciiRecordTable[s[rightIndex] - 65]--;
                if (asciiRecordTable[s[rightIndex] - 65] == 0) {
                    useCount--;//�C���1�Ӵ�1
                }
                //2-2. ���짹����A�i��Ʈ�
				while (useCount == 0)
				{
					if (targetEbdIndex > rightIndex - leftIndex + 1)
					{
                        //3. ����p���d��r��A�h��s���G��
						targetEbdIndex = min(targetEbdIndex, rightIndex - leftIndex + 1);
						targetStartIndex = leftIndex;
					}
					asciiRecordTable[s[leftIndex] - 65]++;
					if (asciiRecordTable[s[leftIndex] - 65] > 0)
						useCount++;//useCount�j��0�ɪ�ܥX�{�s��t�r���A�n���X2-2�i��ư�
					leftIndex++;
				}
            }
            return targetEbdIndex == INT_MAX ? "" : s.substr(targetStartIndex, targetEbdIndex);
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Minimum_Window_Substring_Model GetTestData001(void)
        {
            Minimum_Window_Substring_Model result;
            result.s = "ADOBECODEBANC";
            result.t = "ABC";
            return result;//expect: "BANC"
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Minimum_Window_Substring_Model GetTestData002(void)
        {
            Minimum_Window_Substring_Model result;
            result.s = "a";
            result.t = "a";
            return result;//expect:"a"
        };

        /// <summary>
       /// test 3
       /// </summary>  
        Minimum_Window_Substring_Model GetTestData003(void)
        {
            Minimum_Window_Substring_Model result;
            result.s = "a";
            result.t = "aa";
            return result;//expect:""
        };
#pragma endregion TestData
    };
}