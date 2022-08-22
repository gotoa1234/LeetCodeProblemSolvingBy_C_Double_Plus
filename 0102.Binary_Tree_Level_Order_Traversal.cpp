#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> result = useClass.levelOrder(getTestModel.root);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// �G����Ŷ��ǹM��
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
        ///         ���  :�s���u���t��k(Breadth-First Search, BFS)
        ///                �Q��Queue��C���S�ʡA���i�J���X�A�N�C�h����ƹM���A�b���U�h
        ///      Runtime :    3 ms, faster than 88.72% of C++ online submissions for Binary Tree Level Order Traversal.
        /// Memory Usage : 12.4 MB,   less than 85.31% of C++ online submissions for Binary Tree Level Order Traversal.

        vector<vector<int>> levelOrder(TreeNode* root) {
            
			vector<vector<int>> result;
			if (root == nullptr)
				return result;

			queue<TreeNode*> queueContainer;
			queueContainer.push(root);

			while (!queueContainer.empty())
			{
                //��e�e������(��ܳo�@�h)
				int size = queueContainer.size();
				vector<int> child;
                //�o�@�h�v�B���X
				while (size--)
				{
					TreeNode* t = queueContainer.front();
					queueContainer.pop();
					child.push_back(t->val);

					if (t->left)
						queueContainer.push(t->left);
					if (t->right)
						queueContainer.push(t->right);
				}
				result.push_back(child);
			}
			return result;

        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Binary_Tree_Level_Order_Traversal_Model GetTestData001(void)
        {
            Binary_Tree_Level_Order_Traversal_Model result;
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
        Binary_Tree_Level_Order_Traversal_Model GetTestData002(void)
        {
            Binary_Tree_Level_Order_Traversal_Model result;
            vector<int> l1Vectors = { 1, 2 };
            result.root = ConstructNodes(l1Vectors);
            return result;
        };

        /// <summary>
        /// ���ո��3
        /// </summary>   
        Binary_Tree_Level_Order_Traversal_Model GetTestData003(void)
        {
            Binary_Tree_Level_Order_Traversal_Model result;
            vector<int> l1Vectors{ 1 };
            result.root = ConstructNodes(l1Vectors);
            return result;
        };
    private:
        //TODO: ������
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