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
    /// 最長重複字符替換
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
        ///            思路：此題目只有大寫英文字母，因此可以建立一個字母表紀錄數量
        ///                 我們知道可替換數量k，可建立移動索引，若範圍之間出現
        ///                 重複的字母+數量k 即可知道最長長度。
        ///        Runtime : 12 ms, faster than 72.63% of C++ online submissions for Longest Repeating Character Replacement.
        ///   Memory Usage :  7 MB,   less than 85.10% of C++ online submissions for Longest Repeating Character Replacement.
        ///Time complexity :
        /// <returns></returns>
        int characterReplacement(string s, int k) {
            //1. 建立字母數量表
            vector<int> table(26, 0);
            //2. 建立位移索引，若重複時該索引與 當前索引的距離會拉長
            int moveIndex = 0;            
            int result = 0;
            //3. 紀錄索引間最大重複字母數量  ABCDBEBG
            int maxCount = 0;
            for (int index = 0; index < s.size(); index++)
            {
                table[s[index] - 'A']++;
				maxCount = max(table[s[index] - 'A'], maxCount);
                //4-1. (當前索引 - 位移索引 - 當前重複字母數) > (大於)可替換數 
                //"進入While"表示沒有拉長距離
                while (index - moveIndex + 1 - maxCount > k)
                {
                    //4-2. 往右逐漸位移
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
        /// 測試資料2
        /// </summary>        
        Longest_Repeating_Character_Replacement_Model GetTestData001(void)
        {
            Longest_Repeating_Character_Replacement_Model result;
            result.s = "ABCDBEBG";
            result.k = 2;
            return result;//expect:4
        };

        /// <summary>
        /// 測試資料2
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