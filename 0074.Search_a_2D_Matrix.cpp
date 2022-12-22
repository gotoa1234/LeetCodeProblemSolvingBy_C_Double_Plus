#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution74
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0074.Search_a_2D_Matrix.cpp"
    using namespace Solution74;

    int main()
    {
        Solution74::Search_a_2D_Matrix useClass;
        Solution74::Search_a_2D_Matrix::Search_a_2D_Matrix_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.searchMatrix(getTestModel.matrix, getTestModel.target);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.searchMatrix(getTestModel.matrix, getTestModel.target);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 搜尋2維矩陣
    /// </summary>
    class Search_a_2D_Matrix
    {
#pragma region Model
    public:
        class Search_a_2D_Matrix_Model
        {
        public:
            vector<vector<int>> matrix;
            int target;
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
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            
            int xAxisCount = matrix[0].size();
            int left = 0;
            int right = (matrix.size() * xAxisCount - 1);
            int middle = 0;
            //預處理排除不可能的目標
            if (matrix[left / xAxisCount][left % xAxisCount] > target ||
                matrix[right / xAxisCount][right % xAxisCount] < target)
            {
                return false;
            }

            while (left < right)
            {
                middle = (right + left) / 2;
                
                if (middle == right || middle == left)
                {
                    break;
                }

                if (matrix[middle / xAxisCount][middle % xAxisCount] == target)
                    return true;
                
                if (matrix[middle / xAxisCount][middle % xAxisCount] >= target &&
                    matrix[left / xAxisCount][left % xAxisCount] < target)
                {
                    right = middle;
                }
                else if (matrix[middle / xAxisCount][middle % xAxisCount] < target &&
                    matrix[right / xAxisCount][right % xAxisCount] > target)
                {
                    left = middle;
                }
                else
                {
                    return false;
                }
            }
            
            if (matrix[left / xAxisCount][left % xAxisCount] == target ||
                matrix[right / xAxisCount][right % xAxisCount] == target)
                return true;

            return false;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Search_a_2D_Matrix_Model GetTestData001(void)
        {
            Search_a_2D_Matrix_Model result;
            result.matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
            result.target = 3;
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Search_a_2D_Matrix_Model GetTestData002(void)
        {
            Search_a_2D_Matrix_Model result;
            result.matrix = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} };
            result.target = 13;
            return result;//expect:false
        };
#pragma endregion TestData
    };
}