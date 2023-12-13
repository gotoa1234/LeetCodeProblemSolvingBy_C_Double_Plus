#include <iostream>
#include <vector>
using namespace std;

namespace Solution111
{
#pragma region Paste to execute 
	/*
	#include "Easy\0111.Minimum_Depth_of_Binary_Tree.cpp"
	using namespace Solution111;
	using namespace std;

	int main()
	{
		Solution111::Minimum_Depth_of_Binary_Tree useClass;
		Solution111::Minimum_Depth_of_Binary_Tree::Minimum_Depth_of_Binary_Tree_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.minDepth(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.minDepth(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 二叉樹的最小深度
	/// </summary>
	class Minimum_Depth_of_Binary_Tree
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
		class Minimum_Depth_of_Binary_Tree_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：本題是找最小深度，所以為null的節點必須跳過。
		///                利用遞迴，不斷往有Value 的節點DFS搜尋
		///       Runtime :  267 ms Beats 88.84 %
		///  Memory Usage :144.7 MB Beats 80.97 %
		/// </summary>
		int minDepth(TreeNode* root) {
			if (root == nullptr)
				return 0;
			else if (root->left && root->right == nullptr)
				return minDepth(root->left) + 1;
			else if (root->right && root->left == nullptr)
				return minDepth(root->right) + 1;
			else
				return min(minDepth(root->left) , minDepth(root->right)) + 1;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Minimum_Depth_of_Binary_Tree_Model GetTestData001(void)
		{
			Minimum_Depth_of_Binary_Tree_Model result;
			result.root = new TreeNode(3);
			result.root->left = new TreeNode(9);
			result.root->right = new TreeNode(20);

			result.root->right->left = new TreeNode(15);
			result.root->right->right = new TreeNode(7);
			return result;//expect:  2
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Minimum_Depth_of_Binary_Tree_Model GetTestData002(void)
		{
			Minimum_Depth_of_Binary_Tree_Model result;
			result.root = new TreeNode(2);
			result.root->right = new TreeNode(3);

			result.root->right->right = new TreeNode(4);

			result.root->right->right->right = new TreeNode(5);

			result.root->right->right->right->right = new TreeNode(6);
			return result;//expect: 5
	
		};

		/// <summary>
        /// test 3
        /// </summary>   
		Minimum_Depth_of_Binary_Tree_Model GetTestData003(void)
		{
			Minimum_Depth_of_Binary_Tree_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(3);

			result.root->left->left = new TreeNode(4);
			result.root->left->right = new TreeNode(5);
			return result;//expect: 2

		};

#pragma endregion TestData
	};
}
