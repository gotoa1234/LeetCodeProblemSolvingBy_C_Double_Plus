#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution438
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0438.Find_All_Anagrams_in_a_String.cpp"
    using namespace Solution438;

    int main()
    {
        Solution438::Find_All_Anagrams_in_a_String useClass;
        Solution438::Find_All_Anagrams_in_a_String::Find_All_Anagrams_in_a_String_Model getTestModel = useClass.GetTestData001();
        vector<int> result = useClass.findAnagrams(getTestModel.s, getTestModel.p);

        getTestModel = useClass.GetTestData002();
        result = useClass.findAnagrams(getTestModel.s, getTestModel.p);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �d��r�Ŧꤤ���Ҧ��r��
    /// </summary>
    class Find_All_Anagrams_in_a_String
    {
#pragma region Model
    public:
        class Find_All_Anagrams_in_a_String_Model
        {
        public:
            string s;//���w�r��
            string p;//�r��
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///            ����G��2�i���������A1�i�������ӥX�{���W�v�A�t1�i�O����e�Ҧ����W�v
        ///                 �u����2�i��̭����r���W�v�ۦP�ɤ~�|�O�r�������ޥؼ�
        ///         Runtime: 15 ms, faster than 86.14% of C++ online submissions for Find All Anagrams in a String.
        //    Memory Usage : 8.7 MB,  less than 39.67% of C++ online submissions for Find All Anagrams in a String.
        ///Time complexity :
        /// <returns></returns>
        vector<int> findAnagrams(string s, string p) {
           
            if (s.size() < p.size())
                return vector<int>();

            //1. �����W�v�P��e�W�v
			vector<int> frequence(26, 0);
            vector<int> currentFrequence(26, 0);

            //2. �ؼСB��e�W�v������Ĥ@������
			for (int index = 0; index < p.size(); index++)
            {
                frequence[p[index] - 'a']++;
                currentFrequence[s[index] - 'a']++;
            }

            //3. �ۦP��ܯ���0 ���r�����@
            vector<int> result;
            if (frequence == currentFrequence)
                result.push_back(0);

            //4-1. ���򩹫e��s�W�v
            for (int index = p.size(); index < s.size(); index++)
            {
                currentFrequence[s[index] - 'a']++;
                currentFrequence[s[index - p.size()] - 'a']--;

                //4-2. �W�v�ۦP��ܧ��ؼ�
                if (frequence == currentFrequence)
                    result.push_back(index - (p.size()-1));
            }
            return result;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��2
        /// </summary>        
        Find_All_Anagrams_in_a_String_Model GetTestData001(void)
        {
            Find_All_Anagrams_in_a_String_Model result;
            result.s = "cbaebabacd";
            result.p = "abc";
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Find_All_Anagrams_in_a_String_Model GetTestData002(void)
        {
            Find_All_Anagrams_in_a_String_Model result;
            result.s = "abab"; 
            result.p = "ab";
            return result;

        };

#pragma endregion TestData
    };
}