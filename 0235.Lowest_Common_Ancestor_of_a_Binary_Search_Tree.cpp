#include <iostream>
#include <vector>
using namespace std;

namespace Solution235
{
#pragma region Paste to execute 
	/*
	#include "0235.Lowest_Common_Ancestor_of_a_Binary_Search_Tree.cpp"
	using namespace Solution235;
	using namespace std;

	Solution235::Lowest_Common_Ancestor_of_a_Binary_Search_Tree useClass;
	Solution235::Lowest_Common_Ancestor_of_a_Binary_Search_Tree::Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	useClass._badVersion = getTestModel.bad;
	bool result = useClass.isValidBST(getTestModel.root);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 
	/// </summary>
	class Lowest_Common_Ancestor_of_a_Binary_Search_Tree
	{
#pragma region Model
	public:
		//Definition for singly-linked list.
		struct TreeNode {
			int val;
			TreeNode* left;
			TreeNode* right;
			TreeNode(int x) : val(x), left(NULL), right(NULL) {}
		};
	public:
		class Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model
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
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		}
	public:
		int _badVersion = 0;
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model GetTestData001(void)
		{
			Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model result;
			result.root = new TreeNode(2);
			result.root->left = new TreeNode(1);
			result.root->right = new TreeNode(3);
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model GetTestData002(void)
		{
			Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model result;
			result.root = new TreeNode(5);
			result.root->left = new TreeNode(1);
			result.root->right = new TreeNode(4);

			result.root->right->left = new TreeNode(3);
			result.root->right->right = new TreeNode(6);
			return result;
		};
#pragma endregion TestData
	};
}