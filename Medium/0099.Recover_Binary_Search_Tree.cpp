#include <iostream>
#include <vector>
using namespace std;

namespace Solution99
{
#pragma region Paste to execute 
	/*
	#include "099.Recover_Binary_Search_Tree.cpp"
	using namespace Solution99;
	using namespace std;

	Solution99::Recover_Binary_Search_Tree useClass;
	Solution99::Recover_Binary_Search_Tree::Recover_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	useClass.recoverTree(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	useClass.recoverTree(getTestModel.root);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 恢復二叉搜索樹
	/// </summary>
	class Recover_Binary_Search_Tree
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
		class Recover_Binary_Search_Tree_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路： 
		///       Runtime: 
		///  Memory Usage :
		/// </summary>
		void recoverTree(TreeNode* root) {
		 
		}
	
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Recover_Binary_Search_Tree_Model GetTestData001(void)
		{
			Recover_Binary_Search_Tree_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(3);
			result.root->left->right = new TreeNode(2);
			return result;
            return result;//expect:  [3,1,null,null,2]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Recover_Binary_Search_Tree_Model GetTestData002(void)
		{
			Recover_Binary_Search_Tree_Model result;
			result.root = new TreeNode(3);
			result.root->left = new TreeNode(1);
			result.root->right = new TreeNode(4);
			result.root->right->left= new TreeNode(2);
            return result;//expect:  [2,1,4,null,null,3]
		};
	 private:
#pragma endregion TestData
	};
}