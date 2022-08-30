#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution844
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0844.Backspace_String_Compare.cpp"
    using namespace Solution844;

    int main()
    {
        Solution844::Backspace_String_Compare useClass;
        Solution844::Backspace_String_Compare::Backspace_String_Compare_Model getTestModel = useClass.GetTestData001();
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
        ///            思路：
        ///                 
        ///                 
        ///        Runtime : 
        ///   Memory Usage : 
        ///Time complexity :
        /// <returns></returns>
        bool backspaceCompare(string s, string t) {
            return true;
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
            return result;//expect:4
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Backspace_String_Compare_Model GetTestData002(void)
        {
            Backspace_String_Compare_Model result;
            result.s = "AABABBA";
            result.k = 1;
            return result;//expect:4

        };

#pragma endregion TestData
    };
}