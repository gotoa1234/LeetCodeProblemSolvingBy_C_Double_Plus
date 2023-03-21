#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution132
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0132.Palindrome_Partitioning_II.cpp"
    using namespace Solution132;

    int main()
    {
        Solution132::Palindrome_Partitioning_II useClass;
        Solution132::Palindrome_Partitioning_II::Palindrome_Partitioning_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.minCut(getTestModel.s);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.minCut(getTestModel.s);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.minCut(getTestModel.s);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �^�幺��2
    /// </summary>
    class Palindrome_Partitioning_II
    {
#pragma region Model
    public:
        class Palindrome_Partitioning_II_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Q�ΰʺA�W���A�C����dp���|���e��dp���p�⵲�G�A��dp�p�⪺�O�O�_�^�妳�X�{
        ///                �Y���X�{���ɭԫh�|�⤧�edp[] ���p���ȵ�����U���ȡC
        ///                �]���C�Ӷ��q�[���@�r���ɳ��|���W1 (�����^���)�A�Y�X�{�^�媺���p�U�h�|���L�@���֥[
        ///      Runtime :  11 ms Beats 96.57 %
        /// Memory Usage : 6.4 MB Beats 89.30 %
        ///   EX: cbdefc => �إ�dp[6 + 1] �w�]dp[0] = -1
        ///       ��l�� : dp���e => -1 , X , X , X , X , X, X
        ///       step 1 : -1, 0, X , X , X , X , X
        ///       step 2 : -1, 0, 1 , X , X , X , X
        ///       step 3 : -1, 0, 1 , 2 , X , X , X
        ///       step 4 : -1, 0, 1 , 2 , 3 , X , X
        ///       step 5 : -1, 0, 1 , 2 , 3 , 4 , X
        ///       step 6 : -1, 0, 1 , 2 , 3 , 4 , 5 
        ///       �̫ᵲ�G��5
        /// </summary>
        /// <returns></returns>        
        int minCut(string s) {
            int stringLength = s.size();
            //1. �إߨϥ�DP
            vector<int> dp(stringLength + 1, INT_MAX);
            //2. �@�}�l��-1
            dp[0] = -1;    
            //3. �إߤ@�Ӱt���ܼơA�Ω����
            int pair = 1;
            //4-1. �M���r��s
            for (int index = 0; index < stringLength; index++) 
            {
                //4-2. �^�媺�_�r��B�z EX: "a" , "aba" , "abcde" �Ѥ����}�l�����k�X��
                for (int innerIndex = 0;
                    index - innerIndex >= 0 && index + innerIndex < stringLength && s[index + innerIndex] == s[index - innerIndex];
                    innerIndex++)
                {
                    dp[index + innerIndex + 1] = min(dp[index + innerIndex + 1], 1 + dp[index - innerIndex]);
                }
                //4-3. �^�媺���r��B�z EX: "aa" , "abab" , "abcdee" ���k�X��
                for (int innerIndex = 0;
                    index - innerIndex >= 0 && index + innerIndex + pair < stringLength && s[index + innerIndex + pair] == s[index - innerIndex];
                    innerIndex++)
                {
                    dp[index + innerIndex + 1 + pair] = min(dp[index + innerIndex + 1 + pair], 1 + dp[index - innerIndex]);
                }
            }
            return dp[stringLength];
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Palindrome_Partitioning_II_Model GetTestData001(void)
        {
            Palindrome_Partitioning_II_Model result;
            result.s = "aab";
            return result;//expect: 1
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Palindrome_Partitioning_II_Model GetTestData002(void)
        {
            Palindrome_Partitioning_II_Model result;
            result.s = "a";
            return result;//expect: 0
        };
        
        /// <summary>
        /// test 3
        /// </summary>   
        Palindrome_Partitioning_II_Model GetTestData003(void)
        {
            Palindrome_Partitioning_II_Model result;
            result.s = "ab";
            return result;//expect: 1
        };
#pragma endregion TestData
    };
}