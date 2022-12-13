#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution73
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0073.Set_Matrix_Zeroes.cpp"
    using namespace Solution73;

    int main()
    {
        Solution73::Set_Matrix_Zeroes useClass;
        Solution73::Set_Matrix_Zeroes::Set_Matrix_Zeroes_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.setZeroes(getTestModel.matrix);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.setZeroes(getTestModel.matrix);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ³]¸m¯x°}¹sÂI
    /// </summary>
    class Set_Matrix_Zeroes
    {
#pragma region Model
    public:
        class Set_Matrix_Zeroes_Model
        {
        public:
            vector<vector<int>> matrix;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// <returns></returns>
        void setZeroes(vector<vector<int>>& matrix) {
            vector<tuple<int, int>> points;
            for (int yAxis = 0; yAxis < matrix.size(); yAxis++)
            {
                for (int xAxis = 0; xAxis < matrix[yAxis].size(); xAxis++)
                {
                    if (matrix[yAxis][xAxis] == 0)
                    {
                        tuple<int, int> point = make_tuple(yAxis, xAxis);
                        points.push_back(point);
                        points.insert(points.begin(), point);
                    }
                }
            }

            for (auto point : points)
            {              
                int yAxisAnchor = get<0>(point);
                int xAxisAnchor = get<1>(point);
                for (int xAxis = 0; xAxis < matrix[yAxisAnchor].size(); xAxis++)
                {
                    matrix[yAxisAnchor][xAxis] = 0;
                }

                for (int yAxis = 0; yAxis < matrix.size(); yAxis++)
                {
                    matrix[yAxis][xAxisAnchor] = 0;
                }
            }
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Set_Matrix_Zeroes_Model GetTestData001(void)
        {
            Set_Matrix_Zeroes_Model result;
			result.matrix = { {1,1,1},
                              {1,0,1},
                              {1,1,1} };
            return result;//expect: [[1, 0, 1], [0, 0, 0], [1, 0, 1]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Set_Matrix_Zeroes_Model GetTestData002(void)
        {
            Set_Matrix_Zeroes_Model result;
            result.matrix = { {0, 1, 2, 0},
                              {3, 4, 5, 2},
                              {1, 3, 1, 5} 
            };
            return result;//expect: [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]
        };
#pragma endregion TestData
    };
}