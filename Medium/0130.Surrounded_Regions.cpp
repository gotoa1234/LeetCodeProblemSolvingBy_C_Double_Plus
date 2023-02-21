#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution130
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0130.Surrounded_Regions.cpp"
    using namespace Solution130;

    int main()
    {
        Solution130::Surrounded_Regions useClass;
        Solution130::Surrounded_Regions::Surrounded_Regions_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.sumNumbers(getTestModel.n);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.sumNumbers(getTestModel.n);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.sumNumbers(getTestModel.n);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 周邊地區
    /// </summary>
    class Surrounded_Regions
    {
    public:
        //Definition for singly-linked list.
        struct TreeNode {
            int val;
            TreeNode* left;
            TreeNode* right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
        };
#pragma region Model
    public:
        class Surrounded_Regions_Model
        {
        public:
            vector<vector<char>> board;
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
        void solve(vector<vector<char>>& board) {
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Surrounded_Regions_Model GetTestData001(void)
        {
            Surrounded_Regions_Model result;
            result.board = { {'X','X','X','X' } ,{'X','O','O','X' } ,{'X','X','O','X' } ,{'X','O','X','X' }};
            return result;//expect: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Surrounded_Regions_Model GetTestData002(void)
        {
            Surrounded_Regions_Model result;
            result.board = {{'X'}};
            return result;//expect: [["X"]]
        };

#pragma endregion TestData
    };
}