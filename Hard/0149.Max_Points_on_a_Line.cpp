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
    /// ¤Àµü2
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
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>        
        int maxPoints(vector<vector<int>>& points) {
            return {};
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

#pragma endregion TestData
    };
}