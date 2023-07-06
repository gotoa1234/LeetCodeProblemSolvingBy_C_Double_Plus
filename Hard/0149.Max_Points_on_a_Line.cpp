#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution149
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0149.Max_Points_on_a_Line.cpp"
    using namespace Solution149;

    int main()
    {
        Solution149::Max_Points_on_a_Line useClass;
        Solution149::Max_Points_on_a_Line::Max_Points_on_a_Line_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.maxPoints(getTestModel.points);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.maxPoints(getTestModel.points);
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 最大的點成一線
    /// </summary>
    class Max_Points_on_a_Line
    {
#pragma region Model
    public:
        class Max_Points_on_a_Line_Model
        {
        public:
            vector<vector<int>> points;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：利用斜率計算，並且考慮到直、橫。
        ///      Runtime :   24 ms Beats 96.90 %
        /// Memory Usage : 10.2 MB Beats 82.22 %
        /// </summary>
        /// <returns></returns>        
        int maxPoints(vector<vector<int>>& points) {
            if (points.size() <= 2)
                return points.size();
            //1. 基本就是2點成立 
            int basePoints = 2;
            int maxCount = points.size();

            //2. 建立Hash Map 紀錄某個斜率算出的值是否相同，相同要進行累加
            unordered_map<float, int> hashMap = {};

            //3-1. 每次從一個座標點對其他座標點計算斜率是否一致
            for (int index = 0; index < maxCount; index++) 
            {
                hashMap.clear();
                //3-2. 斜率公式，要考慮到橫線與直線的狀況
                for (int innerIndex = 0; innerIndex < index; innerIndex++) 
                {
                    if (index == innerIndex) 
                        continue;
                    float key = (float)(points[innerIndex][1] - points[index][1]) / (points[innerIndex][0] - points[index][0]);
                    if (isnan(key))//檢查是否非數值 (處理橫線 —)
                        key = NAN;
                    if (isinf(key))//檢查是否無限大 (處理直線 | )
                        key = INFINITY;
                    basePoints = max(basePoints, hashMap[key] + 2);
                    hashMap[key]++;
                }
            }
            //4. 將所有的斜率比對的結果返回(最大值)
            return basePoints;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Max_Points_on_a_Line_Model GetTestData001(void)
        {
            Max_Points_on_a_Line_Model result;
			result.points = { {1,1}, {2,2}, {3,3} };
            return result;//expect:3
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Max_Points_on_a_Line_Model GetTestData002(void)
        {
            Max_Points_on_a_Line_Model result;
			result.points = { {1,1}, {3,2}, {5,3},{4,1},{2,3},{1,4} };
            return result;//expect:4
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Max_Points_on_a_Line_Model GetTestData003(void)
        {
            Max_Points_on_a_Line_Model result;
			result.points = { {4, 5 },{4, -1 },{4, 0} };
            return result;//expect:3 ※如果未檢查無限大 或 非數值 會得到錯誤的答案2
        };
#pragma endregion TestData
    };
}