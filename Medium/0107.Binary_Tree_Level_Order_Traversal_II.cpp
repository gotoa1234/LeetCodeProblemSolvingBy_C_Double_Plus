#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace Solution107
{
#pragma region Paste to execute 
    /*
    #include "Medium\0107.Binary_Tree_Level_Order_Traversal_II.cpp"
    using namespace Solution107;
    using namespace std;

    Solution107::Binary_Tree_Level_Order_Traversal_II useClass;
    Solution107::Binary_Tree_Level_Order_Traversal_II::Binary_Tree_Level_Order_Traversal_II_Model getTestModel = useClass.GetTestData001();
    vector<vector<int>> result = useClass.levelOrderBottom(getTestModel.root);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// �G����Ŷ��ǹM��2
    /// </summary>
    class Binary_Tree_Level_Order_Traversal_II
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
        class Binary_Tree_Level_Order_Traversal_II_Model
        {
        public:
            TreeNode* root;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ���  :
        ///      Runtime : 
        /// Memory Usage : 

        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            return {};
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Binary_Tree_Level_Order_Traversal_II_Model GetTestData001(void)
        {
            Binary_Tree_Level_Order_Traversal_II_Model result;
            vector<int> l1Vectors = { 3,9,20,NULL,NULL,15,7 };
            //result.root = ConstructNodes(l1Vectors);
            result.root = new TreeNode(3);
            result.root->left = new TreeNode(9);
            result.root->right = new TreeNode(20);
            result.root->right->left = new TreeNode(15);
            result.root->right->right = new TreeNode(7);

            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Binary_Tree_Level_Order_Traversal_II_Model GetTestData002(void)
        {
            Binary_Tree_Level_Order_Traversal_II_Model result;
            vector<int> l1Vectors = { 1, 2 };
            result.root = ConstructNodes(l1Vectors);
            return result;
        };

        /// <summary>
        /// ���ո��3
        /// </summary>   
        Binary_Tree_Level_Order_Traversal_II_Model GetTestData003(void)
        {
            Binary_Tree_Level_Order_Traversal_II_Model result;
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