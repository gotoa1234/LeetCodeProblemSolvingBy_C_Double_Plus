#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution746
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0746.Min_Cost_Climbing_Stairs.cpp"
    using namespace Solution746;
    
    int main()
    {
        Solution746::Min_Cost_Climbing_Stairs useClass;
        Solution746::Min_Cost_Climbing_Stairs::Min_Cost_Climbing_Stairs_Model getTestModel = useClass.GetTestData001();
        int result = useClass.minCostClimbingStairs(getTestModel.cost);
    
        getTestModel = useClass.GetTestData002();
        result = useClass.minCostClimbingStairs(getTestModel.cost);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    ///  最小成本的爬樓梯
    /// 規則：每次只能爬1步或2步，但每個階梯有費用了，找出到終點前最低成本費用
    /// </summary>
    class Min_Cost_Climbing_Stairs
    {
#pragma region Model
    public:
        class Min_Cost_Climbing_Stairs_Model
        {
        public:
            vector<int> cost;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///            思路：動態規劃，從第3步開始，選擇出前面2步中的最小費用階梯，然後加入自己(第3步)，再給下一步(第4步)挑選
        ///        Runtime :    7 ms, faster than 82.47% of C++ online submissions for Min Cost Climbing Stairs.
        ///   Memory Usage : 13.6 MB,   less than 96.12% of C++ online submissions for Min Cost Climbing Stairs.
        ///Time complexity : O(n)
        /// <returns></returns>
        int minCostClimbingStairs(vector<int>& cost) {
            //動態規劃優化 - 優點省去空間記憶 
            if (cost.size() == 1)
                return cost[0];
            if (cost.size() == 2)
                return min(cost[0], cost[1]);

            int current = cost[1];
            int last = cost[0];
            int temp;
			for (int i = 2; i < cost.size(); i++)
            {
                temp = current;
                current = cost[i] + min(current, last);
                last = temp;
            }
			return min(current, last);
        }

        //動態規劃經典解法 - 缺點，記憶體浪費
        int minCostClimbingStairs2(vector<int>& cost) {
            if (cost.size() == 1)
                return cost[0];
            if (cost.size() == 2)
                return min(cost[0], cost[1]);

            vector<int> dp(cost.size(), 0);
            dp[0] = cost[0];
            dp[1] = cost[1];
            for (int i = 2; i < cost.size(); i++)
            {
                dp[i] += cost[i] + min(dp[i - 2], dp[i - 1]);
            }
            return min(dp[cost.size() - 1], dp[cost.size() - 2]);
        }

#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料2
        /// </summary>        
        Min_Cost_Climbing_Stairs_Model GetTestData001(void)
        {
            Min_Cost_Climbing_Stairs_Model result;
            vector<int> input{ 10,15,20 };
            result.cost = input;
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Min_Cost_Climbing_Stairs_Model GetTestData002(void)
        {
            Min_Cost_Climbing_Stairs_Model result;
			vector<int> input{ 1,100,1,1,1,100,1,1,100,1 };
            result.cost = input;
            return result;
        };

#pragma endregion TestData
    };
}