#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution85
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0085.Maximal_Rectangle.cpp"
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
        ///         思路 ：
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        int maximalRectangle(vector<vector<char>>& matrix) {
            return {};
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
            return result;//expect: 0
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