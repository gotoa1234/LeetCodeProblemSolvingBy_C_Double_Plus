#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution129
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0129.Sum_Root_to_Leaf_Numbers.cpp"
    using namespace Solution129;

    int main()
    {
        Solution129::Sum_Root_to_Leaf_Numbers useClass;
        Solution129::Sum_Root_to_Leaf_Numbers::Sum_Root_to_Leaf_Numbers_Model getTestModel = useClass.GetTestData001();
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
    /// 將根與葉數相加
    /// </summary>
    class Sum_Root_to_Leaf_Numbers
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
        class Sum_Root_to_Leaf_Numbers_Model
        {
        public:
            vector<int> nums;
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
        int sumNumbers(TreeNode* root) {
            return{};
        }


    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Sum_Root_to_Leaf_Numbers_Model GetTestData001(void)
        {
            Sum_Root_to_Leaf_Numbers_Model result;
            result.nums = { 1, 2, 3 };
            return result;//expect: 25
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Sum_Root_to_Leaf_Numbers_Model GetTestData002(void)
        {
            Sum_Root_to_Leaf_Numbers_Model result;
            result.nums = { 4,9,0,5,1 };
            return result;//expect: 1026
        };

#pragma endregion TestData
    };
}