#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution5
{
#pragma region Paste to execute 
    /*

    */
#pragma endregion Paste to execute

    /// <summary>
    /// �̪��^��l�r��A���w�@�Ӧr��A��X�^��
    /// �^��G�q�Y��� �P �����Y �r�곣�O�ۦP���A�N�O�^�� EX: aa�Babcba�Ba
    /// <para>����G</para>
    /// </summary>
    class Longest_Palindromic_Substring
    {
#pragma region Model
    public:
        class Longest_Palindromic_Substring_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        string longestPalindrome(string s) {
            string result(1, s[0]);
            unordered_map<int, int> hashMap;
            int currentMax = 0;
            int stringLength = s.size();
            for (int index = 0; index < stringLength; index++)
            {
                if (hashMap.find(s[index]) == hashMap.end())
                {
                    currentMax++;
                }
                else
                {
                    currentMax = index - hashMap[s[index]];
					string sub = GetSubString(s, hashMap[s[index]], currentMax + 1);
                    if (sub.size() > result.size() && IsPalindrome(sub))
                    {
                        result = sub;
                    }
                }
                hashMap[s[index]] = index;
            }
            string sub = GetSubString(s, hashMap[s[stringLength]], (stringLength - hashMap[s[stringLength]] + 1));
            if (sub.size() > result.size() && IsPalindrome(sub))
            {
                result = sub;
            }
            return result;
        }
    private:
        string GetSubString(string& sourceString, int startIndex, int length)
        {
            return sourceString.substr(startIndex, length);
        };
        bool IsPalindrome(string subString)
        {
            int maxLength = subString.size();
            for (int headIndex = 0, lastIndex = maxLength-1; headIndex < lastIndex; headIndex++ , lastIndex--)
            {
                if (subString[headIndex] != subString[lastIndex])
                {
                    return false;
                }
            }
            return true;
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Longest_Palindromic_Substring_Model GetTestData001(void)
        {
            Longest_Palindromic_Substring_Model result;
            result.s = "xaabacxcabaaxcabaax";// "babad";
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Longest_Palindromic_Substring_Model GetTestData002(void)
        {
            Longest_Palindromic_Substring_Model result;
            result.s = "cbbd";
            return result;
        };
#pragma endregion TestData
    };
}