#include <iostream>
#include <vector>
using namespace std;

namespace Solution144
{
#pragma region Paste to execute 
	/*
	#include "Easy\0144.Binary_Tree_Preorder_Traversal.cpp"
	using namespace Solution144;
	using namespace std;


	int main()
	{
		Solution144::Binary_Tree_Preorder_Traversal useClass;
		Solution144::Binary_Tree_Preorder_Traversal::Binary_Tree_Preorder_Traversal_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.preorderTraversal(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.preorderTraversal(getTestModel.root);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.preorderTraversal(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 二叉樹前序遍歷
	/// </summary>
	class Binary_Tree_Preorder_Traversal
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
		class Binary_Tree_Preorder_Traversal_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：前序的關鍵是先碰到的就紀錄，左節點優先，然後才是右節點
		///       Runtime :  0 ms Beats   100 %
		///  Memory Usage :8.3 MB Beats 95.96 %
		/// </summary>
		vector<int> preorderTraversal(TreeNode* root) 
		{
			vector<int> result{};
			PreVisit(root, result);
			return result;
		}
		void PreVisit(TreeNode* currentNode, vector<int>& result)
		{
			if (currentNode == nullptr)
				return;
			result.push_back(currentNode->val);
			if (currentNode->left)
				PreVisit(currentNode->left, result);
			if (currentNode->right)
				PreVisit(currentNode->right, result);
			return;
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Binary_Tree_Preorder_Traversal_Model GetTestData001(void)
		{
			Binary_Tree_Preorder_Traversal_Model result;
			TreeNode* root = new TreeNode(1);
			root->left = nullptr;
			root->right = new TreeNode(2);
			root->right->left = new TreeNode(3);
			result.root = root;
			return result;//expect: [1,2,3]
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Binary_Tree_Preorder_Traversal_Model GetTestData002(void)
		{
			Binary_Tree_Preorder_Traversal_Model result;
			TreeNode* root = nullptr;
			result.root = root;
			return result;//expect: []
		};

		/// <summary>
        /// test 2
        /// </summary>   
		Binary_Tree_Preorder_Traversal_Model GetTestData003(void)
		{
			Binary_Tree_Preorder_Traversal_Model result;
			TreeNode* root = new TreeNode(1);
			result.root = root;
			return result;//expect: [1]
		};
	private:
#pragma endregion TestData
	};
}
