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
    /// 回文劃分2
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
        ///         思路 ：利用動態規劃，每次的dp都會取前面dp的計算結果，此dp計算的是是否回文有出現
        ///                若有出現的時候則會把之前dp[] 較小的值視為當下的值。
        ///                因為每個階段觀察單一字元時都會遞增1 (視為回文數)，若出現回文的狀況下則會跳過一次累加
        ///      Runtime :  11 ms Beats 96.57 %
        /// Memory Usage : 6.4 MB Beats 89.30 %
        ///   EX: cbdefc => 建立dp[6 + 1] 預設dp[0] = -1
        ///       初始化 : dp內容 => -1 , X , X , X , X , X, X
        ///       step 1 : -1, 0, X , X , X , X , X
        ///       step 2 : -1, 0, 1 , X , X , X , X
        ///       step 3 : -1, 0, 1 , 2 , X , X , X
        ///       step 4 : -1, 0, 1 , 2 , 3 , X , X
        ///       step 5 : -1, 0, 1 , 2 , 3 , 4 , X
        ///       step 6 : -1, 0, 1 , 2 , 3 , 4 , 5 
        ///       最後結果為5
        /// </summary>
        /// <returns></returns>        
        int minCut(string s) {
            int stringLength = s.size();
            //1. 建立使用DP
            vector<int> dp(stringLength + 1, INT_MAX);
            //2. 一開始為-1
            dp[0] = -1;    
            //3. 建立一個配對變數，用於分辨
            int pair = 1;
            //4-1. 遍歷字串s
            for (int index = 0; index < stringLength; index++) 
            {
                //4-2. 回文的奇字串處理 EX: "a" , "aba" , "abcde" 由中間開始往左右擴散
                for (int innerIndex = 0;
                    index - innerIndex >= 0 && index + innerIndex < stringLength && s[index + innerIndex] == s[index - innerIndex];
                    innerIndex++)
                {
                    dp[index + innerIndex + 1] = min(dp[index + innerIndex + 1], 1 + dp[index - innerIndex]);
                }
                //4-3. 回文的偶字串處理 EX: "aa" , "abab" , "abcdee" 左右擴散
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