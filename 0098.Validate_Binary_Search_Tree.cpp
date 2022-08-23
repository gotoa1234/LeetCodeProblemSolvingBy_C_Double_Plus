#include <iostream>
#include <vector>
using namespace std;

namespace Solution98
{
#pragma region Paste to execute 
	/*
	#include "098.Validate_Binary_Search_Tree.cpp"
	using namespace Solution98;
	using namespace std;

	Solution98::Validate_Binary_Search_Tree useClass;
	Solution98::Validate_Binary_Search_Tree::Validate_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	useClass._badVersion = getTestModel.bad;
	bool result = useClass.isValidBST(getTestModel.root);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 
	/// </summary>
	class Validate_Binary_Search_Tree
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
		class Validate_Binary_Search_Tree_Model
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
		bool isValidBST(TreeNode* root) {

		}
	public:
		int _badVersion = 0;
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Validate_Binary_Search_Tree_Model GetTestData001(void)
		{
			Validate_Binary_Search_Tree_Model result;
			result.root = new TreeNode(2);
			result.root->left = new TreeNode(1);
			result.root->right = new TreeNode(3);
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Validate_Binary_Search_Tree_Model GetTestData002(void)
		{
			Validate_Binary_Search_Tree_Model result;
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