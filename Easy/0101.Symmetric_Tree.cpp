#include <iostream>
#include <vector>
using namespace std;

namespace Solution101
{
#pragma region Paste to execute 
	/*
	#include "Easy\0101.Symmetric_Tree.cpp"
	using namespace Solution101;
	using namespace std;


	int main()
	{
		Solution101::Symmetric_Tree useClass;
		Solution101::Symmetric_Tree::Symmetric_Tree_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.isSymmetric(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.isSymmetric(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 同一棵樹
	/// </summary>
	class Symmetric_Tree
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
		class Symmetric_Tree_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：利用遞迴與對稱的特性，將左節點+右節點 與 右節點+左節點 交替遞迴重複驗證是否相同
		///               皆相同的情況下到最後(nullptr)
		///       Runtime :   3 ms Beats 90.51 %
		///  Memory Usage :16.5 MB Beats 56.6 %
		/// </summary>
		bool isSymmetric(TreeNode* root) {
			return CheckSymmetric(root->left, root->right);
		}

		bool CheckSymmetric(TreeNode* nodeA, TreeNode* nodeB)
		{
			if (nodeA == nullptr && nodeB == nullptr)
				return true;
		
			if (nodeA == nullptr || nodeB == nullptr || nodeA->val != nodeB->val)
				return false;
			else
				return CheckSymmetric(nodeA->left, nodeB->right) &&
				       CheckSymmetric(nodeA->right, nodeB->left);
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Symmetric_Tree_Model GetTestData001(void)
		{
			Symmetric_Tree_Model result;
			TreeNode* root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->right = new TreeNode(2);

			root->left->left = new TreeNode(3);
			root->left->right = new TreeNode(4);

			root->right->left = new TreeNode(4);
			root->right->right = new TreeNode(4);
			return result;//expect: true
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Symmetric_Tree_Model GetTestData002(void)
		{
			Symmetric_Tree_Model result;
			TreeNode* root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->right = new TreeNode(2);

			root->left->right = new TreeNode(3);

			root->right->right = new TreeNode(3);
			return result;//expect: false
		};
	private:
#pragma endregion TestData
	};
}
