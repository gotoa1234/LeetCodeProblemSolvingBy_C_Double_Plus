#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution76
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0076.Minimum_Window_Substring.cpp"
    using namespace Solution76;

    int main()
    {
        Solution76::Minimum_Window_Substring useClass;
        Solution76::Minimum_Window_Substring::Minimum_Window_Substring_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.minWindow(getTestModel.s, getTestModel.t);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.minWindow(getTestModel.s, getTestModel.t);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.minWindow(getTestModel.s, getTestModel.t);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 最小視窗子字串
    /// </summary>
    class Minimum_Window_Substring
    {
#pragma region Model
    public:
        class Minimum_Window_Substring_Model
        {
        public:
            string s;
            string t;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        string minWindow(string s, string t) 
        {
            int asciiRecordTable[128] = { 0 };
            int start = 0;

            //1. Ascii 紀錄
            int useCount = 0;
            for (int index = 0; index < t.size(); index++) 
            {
                if (asciiRecordTable[t[index]] == 0) 
                    useCount++;
                asciiRecordTable[t[index]]++;
            }
            int finalIndex = INT_MAX;
            for(int startIndex = 0, endIndex = 0; endIndex < s.size(); endIndex++)
            {
                asciiRecordTable[s[endIndex]]--;
                if (asciiRecordTable[s[endIndex]] == 0) {
                    useCount--;
                }
                if (useCount == 0) 
                {
                    while (useCount == 0) 
                    {
                        if (finalIndex > endIndex - startIndex + 1) 
                        {
                            finalIndex = min(finalIndex, endIndex - startIndex + 1);
                            start = startIndex;
                        }
                        asciiRecordTable[s[startIndex]]++;
                        if (asciiRecordTable[s[startIndex]] > 0)
                            useCount++;
                        
                        startIndex++;
                    }
                }
            }

            return finalIndex == INT_MAX ? "" : s.substr(start, finalIndex);
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Minimum_Window_Substring_Model GetTestData001(void)
        {
            Minimum_Window_Substring_Model result;
            result.s = "ADOBECODEBANC";
            result.t = "ABC";
            return result;//expect: "BANC"
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Minimum_Window_Substring_Model GetTestData002(void)
        {
            Minimum_Window_Substring_Model result;
            result.s = "a";
            result.t = "a";
            return result;//expect:"a"
        };

        /// <summary>
       /// test 3
       /// </summary>  
        Minimum_Window_Substring_Model GetTestData003(void)
        {
            Minimum_Window_Substring_Model result;
            result.s = "a";
            result.t = "aa";
            return result;//expect:""
        };
#pragma endregion TestData
    };
}