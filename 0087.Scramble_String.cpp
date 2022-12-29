#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution87
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0087.Scramble_String.cpp"
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
    /// ª§¹Ü¦r¦ê
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
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        bool isScramble(string s1, string s2) {
            return { };
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