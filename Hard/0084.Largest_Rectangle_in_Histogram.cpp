#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

namespace Solution84
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0084.Largest_Rectangle_in_Histogram.cpp"
    using namespace Solution84;

    int main()
    {
        Solution84::Largest_Rectangle_in_Histogram useClass;
        Solution84::Largest_Rectangle_in_Histogram::Largest_Rectangle_in_Histogram_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.largestRectangleArea(getTestModel.heights);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.largestRectangleArea(getTestModel.heights);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 直方圖中最大的矩形
    /// </summary>
    class Largest_Rectangle_in_Histogram
    {
#pragma region Model
    public:
        class Largest_Rectangle_in_Histogram_Model
        {
        public:
            vector<int> heights;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：找出峰值(當前的高度低於前一個高度時，上一個高度為峰值)
        ///                並且再出現峰值前建立一個Stack將每次的非峰值的數值放入
        ///                當觸發峰值時進行以下流程:
        ///                1. 從堆疊依序取出值，若比當前值高則跳出
        ///                2. 取出的堆疊值 * 距離 => 記錄下最大值，若比前一次大表示出現最大的矩形       
        ///      Runtime :  233 ms Beats 68.19 %
        /// Memory Usage : 75.3 MB Beats 91.84 %
        /// </summary>
        /// <returns></returns>
        int largestRectangleArea(vector<int>& heights) {
            int result = 0;
            int useDistance = 0;
            int current = 0;
            stack<int> stackContainer{};
            heights.push_back(0);
            for (int index = 0; index < heights.size(); index++)
            {
                while (!stackContainer.empty() &&
                    heights[stackContainer.top()] >= heights[index])
                {
                    current = stackContainer.top();
                    stackContainer.pop();
                    useDistance = stackContainer.empty() ? index 
                                                         : index - stackContainer.top() - 1;
                    result = max(result, heights[current] * useDistance);
                }
                stackContainer.push(index);
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
        Largest_Rectangle_in_Histogram_Model GetTestData001(void)
        {
            Largest_Rectangle_in_Histogram_Model result;
            result.heights = { 2, 1, 5, 6, 2, 3 };
            return result;//expect: 10
        };
        /// <summary>
        /// test 2
        /// </summary>   
        Largest_Rectangle_in_Histogram_Model GetTestData002(void)
        {
            Largest_Rectangle_in_Histogram_Model result;
            result.heights = { 2, 4 };
            return result;//expect:4
        };
#pragma endregion TestData
    };
}