#include <iostream>
#include <vector>
using namespace std;

namespace Solution124
{
#pragma region Paste to execute 
	/*
	#include "Hard\0124.Binary_Tree_Maximum_Path_Sum.cpp"
	using namespace Solution124;
	using namespace std;

	int main()
	{
		Solution124::Binary_Tree_Maximum_Path_Sum useClass;
		Solution124::Binary_Tree_Maximum_Path_Sum::Binary_Tree_Maximum_Path_Sum_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.maxPathSum(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.maxPathSum(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 二叉樹最大路徑和
	/// </summary>
	class Binary_Tree_Maximum_Path_Sum
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
		class Binary_Tree_Maximum_Path_Sum_Model
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
		int maxPathSum(TreeNode* root) {
			return {};
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Binary_Tree_Maximum_Path_Sum_Model GetTestData001(void)
		{
			Binary_Tree_Maximum_Path_Sum_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(3);

			return result;//expect:6
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Binary_Tree_Maximum_Path_Sum_Model GetTestData002(void)
		{
			Binary_Tree_Maximum_Path_Sum_Model result;
			result.root = new TreeNode(-10);
			result.root->left = new TreeNode(9);
			result.root->right = new TreeNode(20);

			result.root->right->left = new TreeNode(15);
			result.root->right->right = new TreeNode(7);

			return result;//expect: 42
		};

#pragma endregion TestData
	};
}
