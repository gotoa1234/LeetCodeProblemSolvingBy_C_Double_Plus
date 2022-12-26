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
        ///         思路 ：需要利用一個ascii的表紀錄所有字元出現的次數，並且利用滑動的方式更新leftIndex與rightIndex找出值
        ///               此題有些複雜，可直接看代碼中的步驟重現
        ///      Runtime :   7 ms Beats 97.85 %
        /// Memory Usage : 7.8 MB Beats 93.94 %
        /// </summary>
        /// <returns></returns>
        string minWindow(string s, string t) 
        {
            //※A=65 z=122 so 122 - 65 = 57+1 需要58的空間放字母
            int asciiRecordTable[58] = { 0 };
            //1. Ascii 紀錄
            int useCount = 0;
            for (int index = 0; index < t.size(); index++) 
            {
                if (asciiRecordTable[t[index] - 65] == 0)
                    useCount++;
                asciiRecordTable[t[index] - 65]++;
            }
            
            //2. 滑框 - 一定是先找出符合t字串的所有字元
            int targetEbdIndex = INT_MAX;
            int targetStartIndex = 0;
            for(int leftIndex = 0, rightIndex = 0; rightIndex < s.size(); rightIndex++)
            {
                //2-1. 直到useCount = 0 表示所有的t字元都出現了
                asciiRecordTable[s[rightIndex] - 65]--;
                if (asciiRecordTable[s[rightIndex] - 65] == 0) {
                    useCount--;//每找到1個減1
                }
                //2-2. 當找到完畢後，進行滑框
				while (useCount == 0)
				{
					if (targetEbdIndex > rightIndex - leftIndex + 1)
					{
                        //3. 當有更小的範圍字串，則更新結果值
						targetEbdIndex = min(targetEbdIndex, rightIndex - leftIndex + 1);
						targetStartIndex = leftIndex;
					}
					asciiRecordTable[s[leftIndex] - 65]++;
					if (asciiRecordTable[s[leftIndex] - 65] > 0)
						useCount++;//useCount大於0時表示出現新的t字元，要跳出2-2進行滑動
					leftIndex++;
				}
            }
            return targetEbdIndex == INT_MAX ? "" : s.substr(targetStartIndex, targetEbdIndex);
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