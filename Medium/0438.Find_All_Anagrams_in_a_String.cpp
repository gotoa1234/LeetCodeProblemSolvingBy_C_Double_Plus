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
    /// 查找字符串中的所有字謎
    /// </summary>
    class Find_All_Anagrams_in_a_String
    {
#pragma region Model
    public:
        class Find_All_Anagrams_in_a_String_Model
        {
        public:
            string s;//給定字串
            string p;//字謎
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///            思路：用2張表紀錄比較，1張紀錄應該出現的頻率，另1張記錄當前所有的頻率
        ///                 只有當2張表裡面的字母頻率相同時才會是字謎的索引目標
        ///         Runtime: 15 ms, faster than 86.14% of C++ online submissions for Find All Anagrams in a String.
        //    Memory Usage : 8.7 MB,  less than 39.67% of C++ online submissions for Find All Anagrams in a String.
        ///Time complexity :
        /// <returns></returns>
        vector<int> findAnagrams(string s, string p) {
           
            if (s.size() < p.size())
                return vector<int>();

            //1. 紀錄頻率與當前頻率
			vector<int> frequence(26, 0);
            vector<int> currentFrequence(26, 0);

            //2. 目標、當前頻率表先做第一次紀錄
			for (int index = 0; index < p.size(); index++)
            {
                frequence[p[index] - 'a']++;
                currentFrequence[s[index] - 'a']++;
            }

            //3. 相同表示索引0 為字謎之一
            vector<int> result;
            if (frequence == currentFrequence)
                result.push_back(0);

            //4-1. 持續往前更新頻率
            for (int index = p.size(); index < s.size(); index++)
            {
                currentFrequence[s[index] - 'a']++;
                currentFrequence[s[index - p.size()] - 'a']--;

                //4-2. 頻率相同表示找到目標
                if (frequence == currentFrequence)
                    result.push_back(index - (p.size()-1));
            }
            return result;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料2
        /// </summary>        
        Find_All_Anagrams_in_a_String_Model GetTestData001(void)
        {
            Find_All_Anagrams_in_a_String_Model result;
            result.s = "cbaebabacd";
            result.p = "abc";
            return result;
        };

        /// <summary>
        /// 測試資料2
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