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
    /// ·j´M2ºû¯x°}
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
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            return {};
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