#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;

namespace Solution97
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0097.Interleaving_String.cpp"
    using namespace Solution97;

    int main()
    {
        Solution97::Interleaving_String useClass;
        Solution97::Interleaving_String::Interleaving_String_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.isInterleave(getTestModel.s1,getTestModel.s2,getTestModel.s3);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.isInterleave(getTestModel.s1,getTestModel.s2,getTestModel.s3);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.isInterleave(getTestModel.s1,getTestModel.s2,getTestModel.s3);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ��´�r�Ŧ�
    /// </summary>
    class Interleaving_String
    {
#pragma region Model
    public:
        class Interleaving_String_Model
        {
        public:
             string s1; 
             string s2; 
             string s3;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�C����s1�Ps2���@�ӭȻPs3����A�Y�o�{�s�b�B�X�k��JDP���A�קK�Aindex < 0 �ɦ^���ˬd�ɭ��ƧP�_
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 7.2 MB Beats 46.45 %
        /// </summary>
        /// <returns></returns>
        bool isInterleave(string s1, string s2, string s3) 
        {
            if (s3.size() != s1.size() + s2.size())
                return false;
            //�]�wDP
            vector<vector<int>>dp(s1.size() + 1, (vector<int>(s2.size() + 1, -1)));
            return FindInterleave(s1, s2, s3, s1.size() - 1, s2.size() - 1, s3.size() - 1, dp);
        }

        bool FindInterleave(
            string& s1, string& s2, string& s3, int s1Index, int s2Index, int s3Index, vector<vector<int>>& dp
        ) 
        {
            //1. �ư���0���˯�
            if (s1Index < 0 && s2Index < 0 && s3Index < 0) {
                return true;
            }
            //2. s1,s2���ެҦX�k�A�B�bdp���A���򪽱��^��dp���G 
            if (s1Index >= 0 && s2Index >= 0 && dp[s1Index][s2Index] != -1) {
                return dp[s1Index][s2Index];
            }
            //3-1. s1,s2���ެҦX�k�A�����bdp���A�B�Ps3�۹����A�����idp�åB�~��M��
            if (s1Index >= 0 && s1[s1Index] == s3[s3Index] && s2Index >= 0 && s2[s2Index] == s3[s3Index]) {
                return dp[s1Index][s2Index] = (FindInterleave(s1, s2, s3, s1Index - 1,     s2Index, s3Index - 1, dp) 
                                            || FindInterleave(s1, s2, s3, s1Index    , s2Index - 1, s3Index - 1, dp)
                    );
            }
            else if (s1Index >= 0 && s1[s1Index] == s3[s3Index])//3-2. ����1�ŦX
                return FindInterleave(s1, s2, s3, s1Index - 1, s2Index, s3Index - 1, dp);
            else if (s2Index >= 0 && s2[s2Index] == s3[s3Index])//3-3. ����2�ŦX
                return FindInterleave(s1, s2, s3, s1Index, s2Index - 1, s3Index - 1, dp);
            
            //�W�z2~3 ���󳣤��X�A�h�����P�_�L�k�զ�s3
            return false;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Interleaving_String_Model GetTestData001(void)
        {
            Interleaving_String_Model result;
            result.s1 = "aabcc";
            result.s2 = "dbbca";
            result.s3 = "aadbbcbcac";
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Interleaving_String_Model GetTestData002(void)
        {
          Interleaving_String_Model result;
            result.s1 = "aabcc";
            result.s2 = "dbbca";
            result.s3 = "aadbbbaccc";
            return result;//expect: false
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Interleaving_String_Model GetTestData003(void)
        {
           Interleaving_String_Model result;
            result.s1 = "";
            result.s2 = "ca";
            result.s3 = "ac";
            return result;//expect: true
        };
#pragma endregion TestData
    };
}