#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

namespace Solution3
{
#pragma region Paste to execute 
    /*
    #include "0003.Longest_Substring_Without_Repeating_Characters.cpp"
    using namespace Solution3;
    using namespace std;
    
    int main()
    {
    
        Solution3::Longest_Substring_Without_Repeating_Characters useClass;
        Solution3::Longest_Substring_Without_Repeating_Characters::Longest_Substring_Without_Repeating_Characters_Model getTestModel = useClass.GetTestData001();
        int result = useClass.lengthOfLongestSubstring(getTestModel.s);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �̱`�l�r��B�S�����Ʀr��: ��X�l�r��B�̭��S���ۦP���r��
    /// ����G���@�M�r��A�����C�Ӧr��(Hash����)�A�C���e�@���P�_�O�_�s�b�A�p�G�s�b�p���e�r���P�W���J��Ӧr�����Z���O�_����s�̤j�Z��
    ///      Runtime : 11 ms, faster than 83.40% of C++ online submissions for Longest Substring Without Repeating Characters.
    /// Memory Usage : 8.3 MB, less than 58.26 % of C++ online submissions for Longest Substring Without Repeating Characters.
    /// </summary>
    class Longest_Substring_Without_Repeating_Characters
    {
#pragma region Model
    public:
        class Longest_Substring_Without_Repeating_Characters_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        int lengthOfLongestSubstring(string s) {
            int finalMax = 0;//�̲ת���
            int exploreLength = 0;//��������
            unordered_map<char, int> hashMap;//�����r����

            for (int index = 0; index < s.size(); index++)
            {
                if (hashMap.find(s[index]) == hashMap.end() ||
                    index - hashMap[s[index]] > exploreLength
                    )
                {
                    //�S���J�L���r���i�H�����W�[����
                    exploreLength++;
                }
                else//�p�G�S�bHash��A�h�n�O��
                {
                    //������e�̪��Z��
                    finalMax = max(finalMax, exploreLength);
                    //�p��X�D�J�ۦP���r����������
                    exploreLength = index - hashMap[s[index]];
                }
                //�û���s�r��Hash��
                hashMap[s[index]] = index;
            }

            //�̫�A���@�����Ӫ�
            //�����ҡGexploreLength ���i���finalMax�A�̫᪺�l�r��O�̪���
            return max(finalMax, exploreLength);
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Longest_Substring_Without_Repeating_Characters_Model GetTestData001(void)
        {
            Longest_Substring_Without_Repeating_Characters_Model result;
            result.s = "abcabcbb";
            return result;//expcet: 3
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Longest_Substring_Without_Repeating_Characters_Model GetTestData002(void)
        {
            Longest_Substring_Without_Repeating_Characters_Model result;
            result.s = "bbbbb";
            return result;//expect: 1
        };

        /// <summary>
        /// ���ո��3
        /// </summary>   
        Longest_Substring_Without_Repeating_Characters_Model GetTestData003(void)
        {
            Longest_Substring_Without_Repeating_Characters_Model result;
            result.s = "pwwkew";
            return result;//except: 3
        };

        /// <summary>
        /// ���ո��4 - �D�x��
        /// </summary>   
        Longest_Substring_Without_Repeating_Characters_Model GetTestData004(void)
        {
            Longest_Substring_Without_Repeating_Characters_Model result;
            result.s = "bcabcde";
            return result;
        };
    };
#pragma endregion TestData
}