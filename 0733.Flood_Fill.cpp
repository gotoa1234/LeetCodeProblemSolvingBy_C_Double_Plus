#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution733
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0733.Flood_Fill.cpp"
    using namespace Solution733;
    
    int main()
    {
    	Solution733::Flood_Fill useClass;
    	Solution733::Flood_Fill::Flood_Fill_Model getTestModel = useClass.GetTestData001();
    	vector<vector<int>> result = useClass.floodFill(getTestModel.image, getTestModel.sr, getTestModel.sc, getTestModel.color);
    
    	getTestModel = useClass.GetTestData002();
    	result = useClass.floodFill(getTestModel.image, getTestModel.sr, getTestModel.sc, getTestModel.color);
    	return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 洪水填充
    /// </summary>
    class Flood_Fill
    {
#pragma region Model
    public:
        class Flood_Fill_Model
        {
        public:
            vector<vector<int>> image;
            int sr;
            int sc;
            int color;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 :
        ///      Runtime : 
        /// Memory Usage : 
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            vector<vector<int>> result;
            return result;
        }
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Flood_Fill_Model GetTestData001(void)
        {
            Flood_Fill_Model result;
			vector<vector<int>> input = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
            result.image = input;
            result.sc = 1;
            result.sc = 1;
            result.sc = 2;
            return result;
            //Expect: [[2,2,2],[2,2,0],[2,0,1]]
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Flood_Fill_Model GetTestData002(void)
        {
            Flood_Fill_Model result;
            vector<vector<int>> input = {{0, 0, 0}, {0, 0, 0}};
            result.image = input;
            result.sc = 0;
            result.sc = 0;
            result.sc = 0;
            return result;
            //Expect:  [[0,0,0],[0,0,0]]
        };
#pragma endregion TestData
    };
}