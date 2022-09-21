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
    /// 最常子字串且沒有重複字元: 找出子字串且裡面沒有相同的字元
    /// 思路：走一遍字串，紀錄每個字元(Hash紀錄)，每往前一次判斷是否存在，如果存在計算當前字元與上次遇到該字元的距離是否有刷新最大距離
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
            int finalMax = 0;//最終長度
            int exploreLength = 0;//探索長度
            unordered_map<char, int> hashMap;//紀錄字元表

            for (int index = 0; index < s.size(); index++)
            {
                if (hashMap.find(s[index]) == hashMap.end() ||
                    index - hashMap[s[index]] > exploreLength
                    )
                {
                    //沒有遇過的字元可以直接增加長度
                    exploreLength++;
                }
                else//如果沒在Hash表，則要記錄
                {
                    //紀錄當前最長距離
                    finalMax = max(finalMax, exploreLength);
                    //計算出遭遇相同的字元間的長度
                    exploreLength = index - hashMap[s[index]];
                }
                //永遠刷新字元Hash表
                hashMap[s[index]] = index;
            }

            //最後再取一次哪個長
            //※情境：exploreLength 有可能比finalMax，最後的子字串是最長的
            return max(finalMax, exploreLength);
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Longest_Substring_Without_Repeating_Characters_Model GetTestData001(void)
        {
            Longest_Substring_Without_Repeating_Characters_Model result;
            result.s = "abcabcbb";
            return result;//expcet: 3
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Longest_Substring_Without_Repeating_Characters_Model GetTestData002(void)
        {
            Longest_Substring_Without_Repeating_Characters_Model result;
            result.s = "bbbbb";
            return result;//expect: 1
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Longest_Substring_Without_Repeating_Characters_Model GetTestData003(void)
        {
            Longest_Substring_Without_Repeating_Characters_Model result;
            result.s = "pwwkew";
            return result;//except: 3
        };

        /// <summary>
        /// 測試資料4 - 非官方
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