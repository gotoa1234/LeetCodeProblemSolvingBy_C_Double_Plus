#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

namespace Solution128
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0128.Longest_Consecutive_Sequence.cpp"
    using namespace Solution128;

    int main()
    {
        Solution128::Longest_Consecutive_Sequence useClass;
        Solution128::Longest_Consecutive_Sequence::Longest_Consecutive_Sequence_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.longestConsecutive(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.longestConsecutive(getTestModel.nums);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 最長連續序列
    /// </summary>
    class Longest_Consecutive_Sequence
    {
#pragma region Model
    public:
        class Longest_Consecutive_Sequence_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：利用雜湊表紀錄輸入陣列，然後遍歷雜湊表元素，判斷雜湊表該元素是否有連續值，若是則累計
        ///                輸出最大累計值
        ///      Runtime :  129 ms Beats 80.9 %
        /// Memory Usage : 45.7 MB Beats 77.80 %
        /// </summary>
        /// <returns></returns>
        int longestConsecutive(vector<int>& nums) {
            //1. 耗費O(n)，將nums放進HashSet中 (存放時不重複元素)，存放順序是不確定的(元素Hash值決定)
            unordered_set<int> hashSetMap(nums.begin(), nums.end());
            int result = 0;
            int currentValue = 0;
            int currentLength = 0;
            //2. 遍歷unordered_set表
            for (int item : hashSetMap) 
            {
                //3.每個hashSetMap.Count() 耗費O(1)
                if (hashSetMap.count(item - 1) == 0) 
                {
                    currentValue = item;
                    currentLength = 1;
                    while (hashSetMap.count(currentValue + 1) != 0)
                    {
                        currentValue++;
                        currentLength++;
                    }
                    //4. 發現更長的連續性元素則更新
                    result = max(result, currentLength);
                }
            }
            return result;
        }


    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Longest_Consecutive_Sequence_Model GetTestData001(void)
        {
            Longest_Consecutive_Sequence_Model result;
            result.nums = { 100, 200, 300, 400, 1,2,3,4, 50 };//{ 100, 4, 200, 1, 3, 2 };
            return result;//expect: 4
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Longest_Consecutive_Sequence_Model GetTestData002(void)
        {
            Longest_Consecutive_Sequence_Model result;
            result.nums = { 0,3,7,2,5,8,4,6,0,1 };
            return result;//expect: 9
        };

#pragma endregion TestData
    };
}