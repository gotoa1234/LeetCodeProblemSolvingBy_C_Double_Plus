#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution213
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0213.House_Robber_II.cpp"
    using namespace Solution213;

    int main()
    {
        Solution213::House_Robber_II useClass;
        Solution213::House_Robber_II::House_Robber_II_Model getTestModel = useClass.GetTestData2();
        auto result1 = useClass.rob(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.rob(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 房子搶劫者 2
    /// </summary>
    class House_Robber_II
    {
#pragma region Model
    public:
        class House_Robber_II_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 : 參考第198題，進行變化
        ///                利用兩個變數odd與even 找出最佳值，並且利用一個函式限制最後一個與第一個索引不會碰到
        ///      Runtime :   0 ms Beats 100.0 %
        /// Memory Usage : 7.7 MB Beats 95.91 %
        int rob(vector<int>& nums) {
            if (nums.size() == 1)
                return nums[0];
            return max(FindBest(0, nums.size()-1, nums),
                       FindBest(1, nums.size(), nums));
        }

        int FindBest(int startIndex, int maxLength, vector<int>& nums)
        {
            int oddValue = 0;
            int evenValue = 0;
            for (int index = startIndex; index < maxLength; index++)
            {
                if (index % 2 == 0)                
                    evenValue = max(evenValue + nums[index], oddValue);                
                else
                    oddValue = max(oddValue + nums[index], evenValue);
            }
            return max(oddValue, evenValue);
        }
    private:
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// test 1
        /// </summary>        
        House_Robber_II_Model GetTestData001(void)
        {
            House_Robber_II_Model result;
            result.nums = { 1,2,3,1 };
            return result;//Expect: 4
        };

        /// <summary>
        /// test 2
        /// </summary>   
        House_Robber_II_Model GetTestData002(void)
        {
            House_Robber_II_Model result;
            result.nums = { 2, 3, 2 };
            return result;
            //Expect:3
        };

        /// <summary>
        /// test 3
        /// </summary>   
        House_Robber_II_Model GetTestData003(void)
        {
            House_Robber_II_Model result;
            result.nums = { 1, 2, 3 };
            return result;
            //Expect:3
        };
#pragma endregion TestData
    };
}