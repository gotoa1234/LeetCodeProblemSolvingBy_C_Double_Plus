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
	bool result = useClass.isValidBST(getTestModel.root);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ���ҤG���j����
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
		///          ����G �Ƭd�Ҧ����`�I -> �Q�η�e���`�I�����j�A�аO�X�W�U���A�v�@���C
		///       Runtime:    16 ms, faster than 70.17% of C++ online submissions for Validate Binary Search Tree.
		///  Memory Usage : 21.6 MB,   less than 88.99% of C++ online submissions for Validate Binary Search Tree.
		/// </summary>
		bool isValidBST(TreeNode* root) {
			return isValid(root, LONG_MIN, LONG_MAX);
		}
	private:
		bool isValid(TreeNode* currentNode, long min, long max)
		{
			if (currentNode == nullptr)
				return true;
			if (currentNode->val <= min || currentNode->val >= max)
				return false;

			return isValid(currentNode->left, min, currentNode->val) &&
				isValid(currentNode->right, currentNode->val, max);
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
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
		/// ���ո��2
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