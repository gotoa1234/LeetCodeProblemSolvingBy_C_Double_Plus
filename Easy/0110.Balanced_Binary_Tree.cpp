#include <iostream>
#include <vector>
using namespace std;

namespace Solution110
{
#pragma region Paste to execute 
	/*
	#include "Easy\0110.Balanced_Binary_Tree.cpp"
	using namespace Solution110;
	using namespace std;

	int main()
	{
		Solution110::Balanced_Binary_Tree useClass;
		Solution110::Balanced_Binary_Tree::Balanced_Binary_Tree_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.isBalanced(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.isBalanced(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �P�_���ŤG�e��
	/// </summary>
	class Balanced_Binary_Tree
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
		class Balanced_Binary_Tree_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G���ž�w�q:�@�ʾ𤤥��N�`�I�P��L�`�I�����׮t���W�L1
		///                �Q�λ��j�A��X���B�k�`�I�����סA�M�ᰪ�׮t�����b2�H��
		///       Runtime : 4 ms Beats 98.40 %
		///  Memory Usage :21 MB Beats 60.88 %
		/// </summary>
		bool isBalanced(TreeNode* root) {
			if (root == nullptr)
				return true;
			int leftDepth = FindDepth(root->left) + 1;
			int rightDepth = FindDepth(root->right) + 1;
			if (abs(leftDepth - rightDepth) > 1)
				return false;
			return isBalanced(root->left) && isBalanced(root->right);
		}

		int FindDepth(TreeNode* root)
		{
			if (root == nullptr)
				return true;
			int leftDepth = FindDepth(root->left) + 1;
			int rightDepth = FindDepth(root->right) + 1;
			return max(leftDepth, rightDepth);
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Balanced_Binary_Tree_Model GetTestData001(void)
		{
			Balanced_Binary_Tree_Model result;
			result.root = new TreeNode(3);
			result.root->left = new TreeNode(9);
			result.root->right = new TreeNode(20);
			
			result.root->right->left = new TreeNode(15);
			result.root->right->right = new TreeNode(7);
			return result;//expect:  true
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Balanced_Binary_Tree_Model GetTestData002(void)
		{
			Balanced_Binary_Tree_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(2);

			result.root->left->left = new TreeNode(3);
			result.root->left->right = new TreeNode(3);

			result.root->left->left->left = new TreeNode(4);
			result.root->left->left->right = new TreeNode(4);

			return result;//expect: false
		};

		/// <summary>
	    /// ���ո��2
	    /// </summary>   
		Balanced_Binary_Tree_Model GetTestData003(void)
		{
			Balanced_Binary_Tree_Model result;
			return result;//expect: true
		};
#pragma endregion TestData
	};
}