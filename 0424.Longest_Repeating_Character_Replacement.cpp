#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution424
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0424.Longest_Repeating_Character_Replacement.cpp"
    using namespace Solution424;

    int main()
    {
        Solution424::Longest_Repeating_Character_Replacement useClass;
        Solution424::Longest_Repeating_Character_Replacement::Longest_Repeating_Character_Replacement_Model getTestModel = useClass.GetTestData001();
        int result = useClass.characterReplacement(getTestModel.s, getTestModel.k);

        getTestModel = useClass.GetTestData002();
        result = useClass.characterReplacement(getTestModel.s, getTestModel.k);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �̪����Ʀr�Ŵ���
    /// </summary>
    class Longest_Repeating_Character_Replacement
    {
#pragma region Model
    public:
        class Longest_Repeating_Character_Replacement_Model
        {
        public:
            string s;
            int k;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///            ����G���D�إu���j�g�^��r���A�]���i�H�إߤ@�Ӧr��������ƶq
        ///                 �ڭ̪��D�i�����ƶqk�A�i�إ߲��ʯ��ޡA�Y�d�򤧶��X�{
        ///                 ���ƪ��r��+�ƶqk �Y�i���D�̪����סC
        ///        Runtime : 12 ms, faster than 72.63% of C++ online submissions for Longest Repeating Character Replacement.
        ///   Memory Usage :  7 MB,   less than 85.10% of C++ online submissions for Longest Repeating Character Replacement.
        ///Time complexity :
        /// <returns></returns>
        int characterReplacement(string s, int k) {
            //1. �إߦr���ƶq��
            vector<int> table(26, 0);
            //2. �إߦ첾���ޡA�Y���Ʈɸӯ��޻P ��e���ު��Z���|�Ԫ�
            int moveIndex = 0;            
            int result = 0;
            //3. �������޶��̤j���Ʀr���ƶq  ABCDBEBG
            int maxCount = 0;
            for (int index = 0; index < s.size(); index++)
            {
                table[s[index] - 'A']++;
				maxCount = max(table[s[index] - 'A'], maxCount);
                //4-1. (��e���� - �첾���� - ��e���Ʀr����) > (�j��)�i������ 
                //"�i�JWhile"��ܨS���Ԫ��Z��
                while (index - moveIndex + 1 - maxCount > k)
                {
                    //4-2. ���k�v���첾
                    table[s[moveIndex] - 'A']--;
                    moveIndex++;
                }                
                result = max(result, index - moveIndex + 1);
            }
            return result;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��2
        /// </summary>        
        Longest_Repeating_Character_Replacement_Model GetTestData001(void)
        {
            Longest_Repeating_Character_Replacement_Model result;
            result.s = "ABCDBEBG";
            result.k = 2;
            return result;//expect:4
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Longest_Repeating_Character_Replacement_Model GetTestData002(void)
        {
            Longest_Repeating_Character_Replacement_Model result;
            result.s = "AABABBA";
            result.k = 1;
            return result;//expect:4

        };

#pragma endregion TestData
    };
}