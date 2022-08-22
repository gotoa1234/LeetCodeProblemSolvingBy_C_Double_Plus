#include <iostream>
#include <vector>
using namespace std;

namespace Solution102
{
#pragma region Paste to execute 
    /*
    #include "0102.Binary_Tree_Level_Order_Traversal.cpp"
    using namespace Solution102;
    using namespace std;

    Solution102::Binary_Tree_Level_Order_Traversal useClass;
    Solution102::Binary_Tree_Level_Order_Traversal::Binary_Tree_Level_Order_Traversal_Model getTestModel = useClass.GetTestData001();
    bool result = useClass.hasCycle(getTestModel.head);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 二叉樹級順序遍歷
    /// </summary>
    class Binary_Tree_Level_Order_Traversal
    {
#pragma region Model
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
    public:
        class Binary_Tree_Level_Order_Traversal_Model
        {
        public:
            TreeNode* root;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：
        ///      Runtime :
        /// Memory Usage :

        vector<vector<int>> levelOrder(TreeNode* root) {

        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Binary_Tree_Level_Order_Traversal_Model GetTestData001(void)
        {
            Binary_Tree_Level_Order_Traversal_Model result;
			vector<int> l1Vectors = { 1,NULL,3,2,4,NULL,5,6 };
            result.root = ConstructNodes(l1Vectors);
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Binary_Tree_Level_Order_Traversal_Model GetTestData002(void)
        {
            Binary_Tree_Level_Order_Traversal_Model result;
            vector<int> l1Vectors = { 1, 2 };
            result.root = ConstructNodes(l1Vectors);
            return result;
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Binary_Tree_Level_Order_Traversal_Model GetTestData003(void)
        {
            Binary_Tree_Level_Order_Traversal_Model result;
            vector<int> l1Vectors{ 1 };
            result.root = ConstructNodes(l1Vectors);
            return result;
        };
    private:
        TreeNode* ConstructNodes(vector<int>& inputDatas)
        {
         /*   *int val;
            *TreeNode* left;
            *TreeNode* right;
            *TreeNode() : val(0), left(nullptr), right(nullptr) {}
            *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            *TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}*/
            TreeNode* nodeHeads = NULL;
            TreeNode* treeLevelHeads = NULL;
            bool switchLevel = true;
            for (auto& myItem : inputDatas)
            {
                if (nodeHeads == NULL)
                {
                    nodeHeads = new TreeNode(myItem);
                    treeLevelHeads = new TreeNode(myItem);
                    continue;
                }

                if (myItem == NULL && switchLevel)
                {
                
                }


                if (myItem == NULL)
                {
                    continue;
                }
                else
                {
                    TreeNode* newItem = new TreeNode(myItem);
                }
            }
            return nodeHeads;
        };
#pragma endregion TestData
    };
}