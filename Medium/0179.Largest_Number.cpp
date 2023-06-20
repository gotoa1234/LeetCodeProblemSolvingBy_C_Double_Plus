#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

namespace Solution179
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0179.Largest_Number.cpp"
    using namespace Solution179;

    int main()
    {
        Solution179::Largest_Number useClass;
        Solution179::Largest_Number::Largest_Number_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.largestNumber(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.largestNumber(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 
    /// </summary>
    class Largest_Number
    {
#pragma region Model
    public:
        class Largest_Number_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路：要自定義排序，一個數組的數值轉成字串後拼接，大的放前方
        ///      Runtime：   4 ms Beats 89.92 %
        /// Memory Usage：11.6 MB Beats 19.71 %
        /// </summary>
        /// <returns></returns>
    public:
        string largestNumber(vector<int>& nums) {
            vector<string> tempStr;
            string result = "";
            //1. 將所有數值放入字串陣列中
            for (auto number : nums)            
                tempStr.push_back(to_string(number));
            
            //2. 自定義排序，將每個字串拼接比較
            sort(tempStr.begin(), tempStr.end(), [](string& s1, string& s2) {
                //2. 字串拼接，決定前後順序後大的放前
                //EX: {30, 34}  => 3034 > 3430 實際上3430比較大-所以回傳34, 30
                return s1 + s2 > s2 + s1; 
            });

            //3. 將結果全部組成輸出
            for (auto item : tempStr)
                result += item;            
            return result[0] == '0' ? "0" : result;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Largest_Number_Model GetTestData001(void)
        {
            Largest_Number_Model result;
            result.nums = { 10,2 };
            return result;//expect: 210
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Largest_Number_Model GetTestData002(void)
        {
            Largest_Number_Model result;
            result.nums = { 3,30,34,5,9 };
            return result;//expect: 9534330
        };

#pragma endregion TestData
    };
}