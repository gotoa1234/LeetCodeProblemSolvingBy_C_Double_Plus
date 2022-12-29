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
    ///  �̤p���������ӱ�
    /// �W�h�G�C���u�દ1�B��2�B�A���C�Ӷ��観�O�ΤF�A��X����I�e�̧C�����O��
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
        ///            ����G�ʺA�W���A�q��3�B�}�l�A��ܥX�e��2�B�����̤p�O�ζ���A�M��[�J�ۤv(��3�B)�A�A���U�@�B(��4�B)�D��
        ///        Runtime :    7 ms, faster than 82.47% of C++ online submissions for Min Cost Climbing Stairs.
        ///   Memory Usage : 13.6 MB,   less than 96.12% of C++ online submissions for Min Cost Climbing Stairs.
        ///Time complexity : O(n)
        /// <returns></returns>
        int minCostClimbingStairs(vector<int>& cost) {
            //�ʺA�W���u�� - �u�I�٥h�Ŷ��O�� 
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

        //�ʺA�W���g��Ѫk - ���I�A�O������O
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
        /// ���ո��2
        /// </summary>        
        Min_Cost_Climbing_Stairs_Model GetTestData001(void)
        {
            Min_Cost_Climbing_Stairs_Model result;
            vector<int> input{ 10,15,20 };
            result.cost = input;
            return result;
        };

        /// <summary>
        /// ���ո��2
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