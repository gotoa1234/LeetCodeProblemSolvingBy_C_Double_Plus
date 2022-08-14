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
    /// 最長回文子字串，給定一個字串，找出回文
    /// 回文：從頭到尾 與 尾到頭 字串都是相同的，就是回文 EX: aa、abcba、a
    /// <para>思路：</para>
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
            int stringMaxLength = s.length();
            if (stringMaxLength <= 1)
            {
                return s;
            }

            //Step 1 : 填充字元# - 解決奇偶處理
            string s2 = "#";
            for (int i = 0; i < stringMaxLength; i++)
            {
                s2.push_back(s[i]);
                s2.push_back('#');
            }

            //Step 2：
            int cx = 0, currentMax = 0;
            const int s2StringMaxLength = s2.size();
            vector<int> dynamicPrograming(s2StringMaxLength, 0);

            //s2[0] 是# 字元，故從index = 1 開始
            for (int index = 1; index < s2StringMaxLength; index++)
            {
                int moveableIndex = 0;//觀察右邊字元索引，往前看的數量
                if (index >= currentMax)
                {
                    moveableIndex = index + 1;
                }
                else
                {
                    int ii = 2 * cx - index;
                    dynamicPrograming[index] = min(currentMax - index, dynamicPrograming[ii]);
                    if (ii - dynamicPrograming[ii] <= cx - dynamicPrograming[cx])
                        moveableIndex = currentMax + 1;
                }

                for (int leftIndex = 2 * index - moveableIndex, rightIndex = moveableIndex;
                    moveableIndex && moveableIndex < s2StringMaxLength && leftIndex >= 0;
                    leftIndex = 2 * index - moveableIndex, rightIndex = moveableIndex)
                {
                    if (s2[leftIndex] == s2[rightIndex])
                    {
                        dynamicPrograming[index]++;
                        moveableIndex++;
                    }
                    else
                    {
                        break;
                    }
                }

                while (
                    moveableIndex &&
                    (moveableIndex < s2StringMaxLength) &&
                    (2 * index - moveableIndex >= 0) &&
                    (s2[moveableIndex] == s2[2 * index - moveableIndex])
                    )
                {
                    dynamicPrograming[index]++;
                    moveableIndex++;
                }

                if (index + dynamicPrograming[index] > currentMax)
                {
                    currentMax = index + dynamicPrograming[index];
                    cx = index;
                }
            }
            
            //檢索出DP裡面最長的回文 與 該字元起始索引位置
            int targeId = 0;
			for (int index = 1, maxlength = 0; index < s2StringMaxLength; index++)
			{
				if (dynamicPrograming[index] > maxlength)
				{
					maxlength = dynamicPrograming[index];
					targeId = index;
				}
			}

            //跳過 # 字元，組成回原本的回文子字串
			string result;
            for (int Index = targeId - dynamicPrograming[targeId] + 1; 
                Index <= targeId + dynamicPrograming[targeId]; 
                Index += 2
                )
            {
                result.push_back(s2[Index]);
            }
            return result;
		};

    /// <summary>
    /// 思路：回文解法一般人通解: 每個字元遍歷，每次遍歷時將字元 自己 + 下一個，丟進函式中，該字元往左往右不斷跑直到找到最長回文
    /// 效能： O(n^2)
    ///      Runtime :13 ms, faster than 94.30 % of C++ online submissions for Longest Palindromic Substring.
    /// Memory Usage : 6.9 MB, less than 97.46 % of C++ online submissions for Longest Palindromic Substring.
    /// </summary>
    public:
        string longestPalindrome_Solution2(string s) {
            int maxSize = s.length();
            int resultIndex{};
            int resultCount{};

            for (int index{}; index < maxSize; index++) 
            {
                //關鍵1: 往左右檢索 => 奇(自己為中心點) ; 偶(自己+下一個位置)
                GetPalindromeString_Solution2(s, resultIndex, resultCount, index, index);
                GetPalindromeString_Solution2(s, resultIndex, resultCount, index, index + 1);

                //關鍵2: 檢索過程中找到很長的資料，可以將索引基準點往最後的索引前一個位置，因為此段已經在長度範圍中
                //       避免無謂的檢索浪費
                if ((resultIndex - 1) > index)
                {
                    //基準點可往後
                    index = resultIndex - 1;
                }
            }
            return s.substr(resultIndex, resultCount);
        }
    private:
        void GetPalindromeString_Solution2(string& sourceString,
            int& resultIndex,
            int& resultCount,
            int startIndex, 
            int lastIndex)
        {
			for (; 0 <= startIndex && lastIndex < sourceString.size(); startIndex--, lastIndex++)
            {
                if (sourceString[startIndex] != sourceString[lastIndex])
                {
                    break;
                }
                if ((lastIndex - startIndex + 1) > resultCount)
                {
                    resultIndex = startIndex;
                    resultCount = (lastIndex - startIndex + 1);
                }
            }
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Longest_Palindromic_Substring_Model GetTestData001(void)
        {
            Longest_Palindromic_Substring_Model result;
            result.s = "sadxaabacxcabaaxcabaax";// "babad";
            return result;
        };

        /// <summary>
        /// 測試資料2
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