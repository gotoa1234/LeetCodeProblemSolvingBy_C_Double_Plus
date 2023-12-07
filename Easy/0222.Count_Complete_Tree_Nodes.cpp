#include <iostream>
#include <vector>
using namespace std;

namespace Solution222
{
#pragma region Paste to execute 
    /*
    #include "Easy\0222.Count_Complete_Tree_Nodes.cpp"
    using namespace Solution222;
    using namespace std;

    Solution222::Count_Complete_Tree_Nodes useClass;
    Solution222::Count_Complete_Tree_Nodes::Count_Complete_Tree_Nodes_Model getTestModel = useClass.GetTestData001();
    auto result = useClass.countNodes(getTestModel.root);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 反轉二叉樹
    /// </summary>
    class Count_Complete_Tree_Nodes
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
        class Count_Complete_Tree_Nodes_Model
        {
        public:
            TreeNode* root;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：每次從當前節點開始，往左DFS到底與往右DFS到底，若為相同長度為完整二元樹，此時可以得知 2 ^ (高度) -1 
        ///                若無，則將當前左右節點重複上述動作。
         ///      Runtime : 19 ms Beats 98.84 %
        /// Memory Usage :30.8 MB Beats 32.56 %
		int countNodes(TreeNode* root) {
			if (root == nullptr)
				return 0;
			auto leftHeight = FindDFS(root);
			auto rightHeight = FindDFS(root, false);
			if (leftHeight == rightHeight)
				return pow(2, rightHeight) - 1;
			return 1 + countNodes(root->left) + countNodes(root->right);
        }

        //左右樹到底返回高度
        int FindDFS(TreeNode* root, bool isLeft = true)
        {
            if (root == nullptr)
                return 0;
            return 1 + (isLeft ? FindDFS(root->left, isLeft)
                               : FindDFS(root->right, isLeft));
        }

#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Count_Complete_Tree_Nodes_Model GetTestData001(void)
		{
			Count_Complete_Tree_Nodes_Model result;
			vector<int> l1Vectors = { 1,2,3,4,5,6 };
			result.root = ConstructNodes(l1Vectors);
			return result;//Expect : 6
		};

        /// <summary>
        /// test 2
        /// </summary>   
        Count_Complete_Tree_Nodes_Model GetTestData002(void)
        {
            Count_Complete_Tree_Nodes_Model result;
            vector<int> l1Vectors = { 1};
            result.root = ConstructNodes(l1Vectors);
            return result;//Expect : 1
        };


    private:
        TreeNode* ConstructNodes(vector<int>& inputDatas)
        {
            TreeNode* nodeHeads = NULL;
            TreeNode* moveNode = NULL;
            for (auto& myItem : inputDatas)
            {
                TreeNode* newItem = new TreeNode(myItem);
                if (nodeHeads == NULL)
                {
                    nodeHeads = newItem;
                    moveNode = nodeHeads;
                    continue;
                }
                moveNode->right = newItem;
                moveNode = newItem;
            }
            return nodeHeads;
        };
#pragma endregion TestData
    };
}