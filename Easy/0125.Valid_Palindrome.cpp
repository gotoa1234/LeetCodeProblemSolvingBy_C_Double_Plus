#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

namespace Solution125
{
#pragma region Paste to execute 
    /*
    #include "Easy\0125.Valid_Palindrome.cpp"
    using namespace Solution125;
    using namespace std;


    int main()
    {
        Solution125::Valid_Palindrome useClass;
        Solution125::Valid_Palindrome::Valid_Palindrome_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.isPalindrome(getTestModel.s);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.isPalindrome(getTestModel.s);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.isPalindrome(getTestModel.s);
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 有效回文0 ms

        
    /// </summary>
    class Valid_Palindrome
    {
#pragma region Model
    public:
        class Valid_Palindrome_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///          思路： 檢查回文，排除非字母的資料然後判斷是否為回文
        ///       Runtime :   0 ms Beats   100 %
        ///  Memory Usage : 7.4 MB Beats 84.51 %
        /// </summary>
        bool isPalindrome(string s) {
            int leftIndex = 0;
            int rightIndex = s.size() - 1;
            while (leftIndex < rightIndex) 
            {
                if (false == isalnum(s[leftIndex])) 
                {
                    leftIndex++;
                    continue;
                }
                if (false == isalnum(s[rightIndex])) {
                    rightIndex--;
                    continue;
                }
                if (tolower(s[leftIndex]) != tolower(s[rightIndex])) 
                {
                    return false;
                }
                leftIndex++;
                rightIndex--;
            }
            return true;
        }
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// test 1
        /// </summary>        
        Valid_Palindrome_Model GetTestData001(void)
        {
            Valid_Palindrome_Model result;
            result.s = "A man, a plan, a canal: Panama";
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Valid_Palindrome_Model GetTestData002(void)
        {
            Valid_Palindrome_Model result;
            result.s = "race a car";
            return result;//expect: false
        };

        /// <summary>
        /// test 3
        /// </summary> 
        Valid_Palindrome_Model GetTestData003(void)
        {
            Valid_Palindrome_Model result;
            result.s = ",.";
            return result;//expect: true
        };

        /// <summary>
        /// test 4
        /// </summary> 
        Valid_Palindrome_Model GetTestData004(void)
        {
            Valid_Palindrome_Model result;
            result.s = "0P";
            return result;//expect: true
        };
#pragma endregion TestData
    };
}