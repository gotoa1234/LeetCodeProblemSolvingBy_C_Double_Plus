#include <iostream>
#include <vector>
using namespace std;

namespace Solution70
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "Easy\0070.Climbing_Stairs.cpp"
    using namespace Solution70;

    int main()
    {
        Solution70::Climbing_Stairs useClass;
        Solution70::Climbing_Stairs::Climbing_Stairs_Model getTestModel = useClass.GetTestData2();
        int result = useClass.numIslands(getTestModel.grid);

        getTestModel = useClass.GetTestData002();
        result = useClass.climbStairs(getTestModel.n);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 爬樓梯
    /// </summary>
    class Climbing_Stairs
    {
#pragma region Model
    public:
        class Climbing_Stairs_Model
        {
        public:
            int n;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 : 遞迴在n >= 42 以上時會超時計算的問題，可以用對應表、動態規劃的方式處理
        ///                動態規劃:每次將這次的結果紀錄，並且用於下次計算叫用
        ///                
        ///      Runtime :   0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
        /// Memory Usage : 5.8 MB,   less than  97.34% of C++ online submissions for Climbing Stairs.
        int climbStairs(int n) {
            //solve 1：省去動態規劃紀錄用的vector<int>
            int currentValue = 1;
            int lastValue = 1;
            for (int i = 1; i < n; i++)
            {
                currentValue = lastValue + currentValue;
                lastValue = currentValue - lastValue;
            }
			return currentValue;
        }
    public:
        int climbStairs2(int n)
        {
            //solve 2：動態規劃基本的運用方式 Dynamic Programming
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            dp[1] = 1;
            for (int index = 2; index <= n; index++)
            {
                dp[index] = dp[index - 2] + dp[index - 1];
            }
            return dp[n];
        }
        int climbStairs3(int n)
        {
            //solve 3：假定有資料庫來源，這裡的fibAll 視為資料表，讀表查結果
            vector<long long> fibAll = { 0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976 };
            return fibAll[n + 1];
        };
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Climbing_Stairs_Model GetTestData001(void)
        {
            Climbing_Stairs_Model result;
            result.n = 2;
            return result;
            //Expect: 2
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Climbing_Stairs_Model GetTestData002(void)
        {
            Climbing_Stairs_Model result;
            result.n = 3;
            return result;
            //Expect:3
        };
#pragma endregion TestData
    };
}