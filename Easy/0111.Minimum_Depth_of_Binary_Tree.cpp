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
		///          思路：
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		int minDepth(TreeNode* root) {
			return {};
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
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
		/// 測試資料2
		/// </summary>   
		Minimum_Depth_of_Binary_Tree_Model GetTestData002(void)
		{
			Minimum_Depth_of_Binary_Tree_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(2);

			result.root->left->left = new TreeNode(3);

			result.root->left->left->left = new TreeNode(4);

			result.root->left->left->left->left = new TreeNode(5);

			result.root->left->left->left->left->left = new TreeNode(6);

			return result;//expect: 5
		};

#pragma endregion TestData
	};
}
