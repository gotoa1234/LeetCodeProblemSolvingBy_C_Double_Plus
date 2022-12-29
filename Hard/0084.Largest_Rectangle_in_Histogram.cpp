#include <iostream>
#include <unordered_map>
#include <string>
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
        ///         思路 ：
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        int largestRectangleArea(vector<int>& heights) {
            return{};
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