#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

namespace Solution151
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0151.Reverse_Words_in_a_String.cpp"
    using namespace Solution151;

    int main()
    {
        Solution151::Reverse_Words_in_a_String useClass;
        Solution151::Reverse_Words_in_a_String::Reverse_Words_in_a_String_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.reverseWords(getTestModel.s);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.reverseWords(getTestModel.s);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.reverseWords(getTestModel.s);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 反轉字符串中的單詞
    /// </summary>
    class Reverse_Words_in_a_String
    {
#pragma region Model
    public:
        class Reverse_Words_in_a_String_Model
        {
        public:
			string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路： 先反轉該字串，然後將每個字串的字詞做反轉       
        ///         挑戰： 空間複雜度必須O(1) ，因此不可以使用Stack<string> 容器
        ///      Runtime：   0 ms Beats 100 %
        /// Memory Usage： 7.1 MB Beats 85.47 %
        /// </summary>
        /// <returns></returns>
    public:
        string reverseWords(string s) 
        {
            reverse(s.begin(), s.end());
            int wordStartIndex = 0;
            int wordEndIndex = 0; 
            int currentIndex = 0;
            int maxLength = s.size();

            //1. 未走到底重複進行
            while (currentIndex < maxLength) 
            {
                //2-1. 排除空白字元
                while (currentIndex < maxLength && s[currentIndex] == ' ')
                {
                    currentIndex++;
                }

                //2-2. 找出一段Word
                while (currentIndex < maxLength && s[currentIndex] != ' ')
                {
					s[wordEndIndex] = s[currentIndex];
					wordEndIndex++; currentIndex++;
                }
                
                //2-3. 有找出Word時此段成立
                if (wordStartIndex < wordEndIndex) {
                    
                    //3-1. 反轉該Word，
                    reverse(s.begin() + wordStartIndex, s.begin() + wordEndIndex);

                    //3-2. 補上一個空白字元 ※最後結束時會刪除
                    s[wordEndIndex++] = ' ';

                    //3-3. 前進wordStartIndex 找出下一個Word
                    wordStartIndex = wordEndIndex;
                }
                currentIndex++;
            }

            //4. 排除最後一個位元
            if (wordEndIndex > 0)
                s.resize(wordEndIndex - 1);

            //5. 達成space O(1)
            return s;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Reverse_Words_in_a_String_Model GetTestData001(void)
        {
            Reverse_Words_in_a_String_Model result;
            result.s = "the sky is blue";
            return result;//expect: "blue is sky the"
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Reverse_Words_in_a_String_Model GetTestData002(void)
        {
            Reverse_Words_in_a_String_Model result;
            result.s = "  hello world  ";
            return result;//expect: world hello
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Reverse_Words_in_a_String_Model GetTestData003(void)
        {
            Reverse_Words_in_a_String_Model result;
            result.s = "a good   example";
            return result;//expect: "example good a"
        };
#pragma endregion TestData
    };
}