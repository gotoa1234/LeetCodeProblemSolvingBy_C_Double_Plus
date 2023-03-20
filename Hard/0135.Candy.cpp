#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution135
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0135.Candy.cpp"
    using namespace Solution135;

    int main()
    {
        Solution135::Candy useClass;
        Solution135::Candy::Candy_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.candy(getTestModel.ratings);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.candy(getTestModel.ratings);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 糖果
    /// </summary>
    class Candy
    {
#pragma region Model
    public:
        class Candy_Model
        {
        public:
            vector<int> ratings;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         題目：給定一個陣列分數，以下規則
        ///               1. 當前索引分數大於左邊，則當前索引多給1顆糖果，否則不變
        ///               2. 當前索引分數大於右邊，則當前索引再多給1顆糖果，否則不變
        ///               3. 每個人都至少有1顆糖果
        ///               4. 當觸發1.、2. 條件時，除了多給1顆糖果外，還比需比比較對象多1顆糖果
        ///         思路：先給所有1顆糖果，然後執行O(2N) 由左至右比較，然後再由右往左比較，        
        ///      Runtime：   18 ms Beats 91.33 %
        /// Memory Usage： 17.7 MB Beats 60.87 %
        /// </summary>
        /// <returns></returns>        
        int candy(vector<int>& ratings) {
            int ratingLength = ratings.size();
            //1. 排除不用計算的狀況
            if (ratingLength == 1)
                return 1;

            vector<int> candies(ratingLength, 1);
            //2-1. 處理當前索引與前個索引的計算
            for (int index = 1; index < ratingLength; index++) 
            {
                //2-2. 符合條件當前位置的糖果數量要比前個索引多1個
                if (ratings[index] > ratings[index - 1] && 
                    candies[index] <= candies[index - 1])
                    candies[index] = candies[index - 1] + 1;
            }

            //3-1.  處理當前索引與下個索引的計算
            for (int index = ratingLength - 2; index >= 0; index--) 
            {
                //3-2. 符合條件當前位置的糖果數量要比下個索引多1個
                if (ratings[index] > ratings[index + 1] && 
                    candies[index] <= candies[index + 1])
                    candies[index] = candies[index + 1] + 1;
            }

            //4. 總計所有糖果的數量
            int totalCandies = 0;
            for (int index = 0; index < ratingLength; index++) {
                totalCandies += candies[index];
            }
            return totalCandies;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Candy_Model GetTestData001(void)
        {
            Candy_Model result;
            result.ratings = { 1, 0, 2 };
            return result;//expect: 5
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Candy_Model GetTestData002(void)
        {
            Candy_Model result;
            result.ratings = { 1, 2, 2 };
            return result;//expect: 4
        };

        
#pragma endregion TestData
    };
}