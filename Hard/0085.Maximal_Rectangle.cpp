#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

namespace Solution85
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0085.Maximal_Rectangle.cpp"
    using namespace Solution85;

    int main()
    {
        Solution85::Maximal_Rectangle useClass;
        Solution85::Maximal_Rectangle::Maximal_Rectangle_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.maximalRectangle(getTestModel.matrix);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.maximalRectangle(getTestModel.matrix);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 直方圖中最大的矩形
    /// </summary>
    class Maximal_Rectangle
    {
#pragma region Model
    public:
        class Maximal_Rectangle_Model
        {
        public:
            vector<vector<char>> matrix;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：參考 0084的計算方式，但每一層Y軸視為1個面積的容積，往下層時需再累計前一層的值
        ///                若本層的值為0則歸0
        ///      Runtime :   51 ms Beats 79.23 %
        /// Memory Usage : 13.1 MB Beats 77.83 %
        /// </summary>
        /// <returns></returns>
        int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix[0].empty() || matrix.empty())
                return 0;
            int yAxisMax = matrix.size();
            int xAxisMax = matrix[0].size();
            int currentIndex = 0;
            int distance = 0;
            int result = 0;
            vector<int> volumn(xAxisMax + 1);
            for (int yAxis = 0; yAxis < yAxisMax; yAxis++)
            {
                stack<int> container{};
                for (int xAxis = 0; xAxis < xAxisMax + 1; xAxis++)
                {
                    if (xAxis < xAxisMax)
                    {
                        if (matrix[yAxis][xAxis] == '1')
                            volumn[xAxis]++;
                        else
                            volumn[xAxis] = 0;
                    }
                    while (!container.empty() &&
                        volumn[container.top()] >= volumn[xAxis])
                    {
                        currentIndex = container.top();
                        container.pop();
                        distance = volumn.empty() ? xAxis
                            : xAxis - container.top() - 1;
                        result = max(result, distance * volumn[xAxis]);
                    }
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
        Maximal_Rectangle_Model GetTestData001(void)
        {
            Maximal_Rectangle_Model result;
            result.matrix = { {'1', '0', '1', '0', '0'}, 
                              {'1', '0', '1', '1', '1'}, 
                              {'1', '1', '1', '1', '1'}, 
                              {'1', '0', '0', '1', '0'} };
            return result;//expect: 6
        };
        /// <summary>
        /// test 2
        /// </summary>   
        Maximal_Rectangle_Model GetTestData002(void)
        {
            Maximal_Rectangle_Model result;
			result.matrix = { { '0' } };
            return result;//expect:0
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Maximal_Rectangle_Model GetTestData003(void)
        {
            Maximal_Rectangle_Model result;
            result.matrix = {{ '1' }};
            return result;//expect:1
        };
#pragma endregion TestData
    };
}