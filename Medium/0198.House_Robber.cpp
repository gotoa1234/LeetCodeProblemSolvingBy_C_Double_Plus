#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution198
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0198.House_Robber.cpp"
    using namespace Solution198;

    int main()
    {
        Solution198::House_Robber useClass;
        Solution198::House_Robber::House_Robber_Model getTestModel = useClass.GetTestData2();
        auto result1 = useClass.rob(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.rob(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 房子搶劫者
    /// </summary>
    class House_Robber
    {
#pragma region Model
    public:
        class House_Robber_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 : 維護兩個變數一個是紀錄偶數，另一個是紀錄奇數，每次比較保留大的，最後就是結果
        ///      Runtime:    0 ms Beats 100 %
        /// Memory Usage : 7.6 MB Beats 95.92 %
        int rob(vector<int>& nums) {
            int robEven{};
            int robOdds{};
            for (int index = 0; index < nums.size(); index++)
            {
                if (index % 2 == 0)
                    robEven = max(robEven + nums[index], robOdds);
                else 
                    robOdds = max(robEven , robOdds + nums[index]);                
            }
            return max(robEven, robOdds);
        }
    private:        
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// 測試資料1
        /// </summary>        
        House_Robber_Model GetTestData001(void)
        {
            House_Robber_Model result;
			result.nums = { 1,2,3,1 };
            return result;//Expect: 4
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        House_Robber_Model GetTestData002(void)
        {
            House_Robber_Model result;
            result.nums = { 2,7,9,3,1 };
            return result;
            //Expect:12
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        House_Robber_Model GetTestData003(void)
        {
            House_Robber_Model result;
            result.nums = { 8, 5, 3, 1, 10, 30 };
            return result;
            //Expect:41
        };        
#pragma endregion TestData
    };
}