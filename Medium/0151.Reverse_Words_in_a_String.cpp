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
        ///         思路： 
        ///      Runtime： 
        /// Memory Usage： 
        /// </summary>
        /// <returns></returns>
    public:
        string reverseWords(string s) {
            return {};
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