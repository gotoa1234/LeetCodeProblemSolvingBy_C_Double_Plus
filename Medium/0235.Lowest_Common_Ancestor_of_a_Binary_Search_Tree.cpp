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
	bool result = useClass.isValidBST(getTestModel.root);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 二元搜索樹的最小的共同祖先
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
			TreeNode* p;
			TreeNode* q;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：利用二元樹的特性，左邊都是小於當前節點的值，右邊都是大於當前節點的值，因此給定的p 與 q的值可以透過比較找出
		///               真正根節點的位置
		///      Runtime :   34 ms, faster than 85.23% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
		/// Memory Usage : 23.1 MB,   less than 99.67% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
		/// </summary>
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			while (root)
			{
				if (root->val < p->val && root->val < q->val)
				{
					root = root->right;
				}
				else if(root->val > p->val && root->val > q->val)
				{
					root = root->left;
				}
				else
					break;
			}
			return root;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model GetTestData001(void)
		{
			Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model result;
			result.root = new TreeNode(6);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(8);

			result.root->left->left = new TreeNode(0);
			result.root->left->right = new TreeNode(4);
			result.root->left->right->left = new TreeNode(3);
			result.root->left->right->right = new TreeNode(5);

			result.root->right->left = new TreeNode(7);
			result.root->right->right = new TreeNode(9);
			result.p = new TreeNode(2);
			result.q = new TreeNode(8);//exp=6
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model GetTestData002(void)
		{
			Lowest_Common_Ancestor_of_a_Binary_Search_Tree_Model result;
			result.root = new TreeNode(6);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(8);

			result.root->left->left = new TreeNode(0);
			result.root->left->right = new TreeNode(4);
			result.root->left->right->left = new TreeNode(3);
			result.root->left->right->right = new TreeNode(5);

			result.root->right->left = new TreeNode(7);
			result.root->right->right = new TreeNode(9);
			result.p = new TreeNode(2);
			result.q = new TreeNode(4);//exp=2
			return result;
		};
#pragma endregion TestData
	};
}