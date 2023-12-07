#include <iostream>
#include <stack>
using namespace std;

namespace Solution844
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "Easy\0844.Backspace_String_Compare.cpp"
    using namespace Solution844;

    int main()
    {
        Solution844::Backspace_String_Compare useClass;
        Solution844::Backspace_String_Compare::Backspace_String_Compare_Model getTestModel = useClass.GetTestData001();
            int result = useClass.backspaceCompare(getTestModel.s, getTestModel.t);

        getTestModel = useClass.GetTestData002();
        result = useClass.backspaceCompare(getTestModel.s, getTestModel.t);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 退格字符串比較
    /// </summary>
    class Backspace_String_Compare
    {
#pragma region Model
    public:
        class Backspace_String_Compare_Model
        {
        public:
            string s;
            string t;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///            思路：利用Stack先進後出，遇到#的時候把stack中最後一個字元移除，最後就是我們要的字串
        ///        Runtime :   0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
        ///   Memory Usage : 6.5 MB,   less than  28.80% of C++ online submissions for Backspace String Compare.
        ///Time complexity : O(n+m)
        /// <returns></returns>
        bool backspaceCompare(string s, string t) {
            stack<int> sStack, tStack;
            //1. 取得進行清除#後的字串
            ExcuteBackspaceAfter(sStack, s);
            ExcuteBackspaceAfter(tStack, t);

            //2. 兩個字串長度必須相等
            if (tStack.size() != sStack.size())
                return false;
            
            //3. 進行比較是否每個字元相同
            while (!tStack.empty())
            {
                if (tStack.top() != sStack.top())
                    return false;
                tStack.pop();
                sStack.pop();
            }
            return true;
        }

    private :
        void ExcuteBackspaceAfter(stack<int>& inStack, string inputStr)
        {
            //利用Stack先進後出，遇到#的時候把stack中最後一個字元移除，最後就是我們要的字串
            for (int i = 0; i < inputStr.size(); i++)
            {
                if (inputStr[i] == '#')
                {
                    if (!inStack.empty())
                        inStack.pop();
                }
                else
                    inStack.push(inputStr[i]);
            }
        }
            
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料2
        /// </summary>        
        Backspace_String_Compare_Model GetTestData001(void)
        {
            Backspace_String_Compare_Model result;
            result.s = "ab#c";
            result.t = "ab#c";
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Backspace_String_Compare_Model GetTestData002(void)
        {
            Backspace_String_Compare_Model result;
			result.s = "ab##";
			result.t = "c#d#";
            return result;
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Backspace_String_Compare_Model GetTestData003(void)
        {
            Backspace_String_Compare_Model result;
            result.s = "a#c";
            result.t = "b";
            return result;
        };

#pragma endregion TestData
    };
}