#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution87
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0087.Scramble_String.cpp"
    using namespace Solution87;

    int main()
    {
        Solution87::Scramble_String useClass;
        Solution87::Scramble_String::Scramble_String_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.isScramble(getTestModel.s1, getTestModel.s2);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.isScramble(getTestModel.s1, getTestModel.s2);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.isScramble(getTestModel.s1, getTestModel.s2);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 爭奪字串
    /// </summary>
    class Scramble_String
    {
#pragma region Model
    public:
        class Scramble_String_Model
        {
        public:
            string s1;
            string s2;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路：利用遞迴，每次切割兩組字串，並分成 1. 切割的兩組字串比對 2. 下一次切割的兩組字串比對
        ///               並且用一個HashTable 紀錄兩組字串是否為爭奪規則，無論是否，都記錄，避免重複運算
        ///               若最後有發現其中一個為true表示題目給的s1與s2為一個合法的爭奪。
        ///     題目意思：給定兩個字串: s1 ="great"; s2= "rgeat"; 兩個長度必定相同，且字串必定小寫字母，且只有一個差異
        ///                great         rgeat 
        ///                ↙ ↘         ↙ ↘
        ///              gre   at      rge   at
        ///             ↙ ↘ ↙↘    ↙ ↘ ↙↘
        ///            gr   e a  t   rg   e a  t 
        ///           ↙↘          ↙↘
        ///          g   r         r   g
        ///      此時s1的r與g 互換重組 = rgeat  等於 s2的rgeat 
        ///      s1只更換"1"次左子樹與右子樹就可以達到等於s2 所以返回True，這是一個爭奪字串
        ///      Runtime：   8 ms Beats 95.8 %
        /// Memory Usage：15.3 MB Beats 79.72 %
        /// </summary>
        /// <returns></returns>
        unordered_map<string, bool> hashMap;
        bool isScramble(string s1, string s2) 
        {
            //1-1. 如果切割後的s1 與 s2 有相同字串亦可以視為存在
            if (s1 == s2) {
                return true;
            }
            //1-2. 如果hash表已經存在，表示其他樹有重疊的字串組成，可以返還記錄結果，不用重複遞迴
            else if (hashMap.count(s1 + s2))
                return hashMap[s1 + s2];
            //2. 建立3個小寫字母表(26個英文字母)
            vector<int> s1AlphabetTable(26, 0);
            vector<int> s2AlphabetTable(26, 0);
            vector<int> diffAlphabetTable(26, 0);
            int splitIndex{};
            //3-1. 遍歷s1字串
            for (int index = 1; index <= s1.size() - 1; index++)
            {
                //3-2. 紀錄字母出現次數，其中diffAlphabetTable為切割位置的字母
                splitIndex = s1.size() - index;
                s1AlphabetTable[s1[index - 1] - 'a']++;
                s2AlphabetTable[s2[index - 1] - 'a']++;
                diffAlphabetTable[s2[splitIndex] - 'a']++;

                //3-3. 字串s1與s2的可能，並且判斷是否為爭奪
                if (s1AlphabetTable == s2AlphabetTable && 
                    isScramble(s1.substr(0, index), s2.substr(0, index)) && 
                    isScramble(s1.substr(index), s2.substr(index))) 
                {
                    hashMap[s1 + s2] = true;
                    return true;
                }
                //3-4. 字串s1與s2切割字串位置的可能，並且判斷是否為爭奪
                if (s1AlphabetTable == diffAlphabetTable && 
                    isScramble(s1.substr(0, index), s2.substr(splitIndex)) && 
                    isScramble(s1.substr(index), s2.substr(0, splitIndex))) 
                {
                    hashMap[s1 + s2] = true;
                    return true;
                }
            }
            //4. 如果都沒有找到爭奪，則這組s1 + s2 不是一個爭奪字詞組成
            hashMap[s1 + s2] = false;
            return false;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Scramble_String_Model GetTestData001(void)
        {
            Scramble_String_Model result;
            result.s1 = "great";
            result.s2 = "rgeat";
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Scramble_String_Model GetTestData002(void)
        {
            Scramble_String_Model result;
            result.s1 = "abcde";
            result.s2 = "caebd";
            return result;//expect: false
        };

        /// <summary>
        /// test 2
        /// </summary>
        Scramble_String_Model GetTestData003(void)
        {
            Scramble_String_Model result;
            result.s1 = "a";
            result.s2 = "a";
            return result;//expect: true
        };
#pragma endregion TestData
    };
}