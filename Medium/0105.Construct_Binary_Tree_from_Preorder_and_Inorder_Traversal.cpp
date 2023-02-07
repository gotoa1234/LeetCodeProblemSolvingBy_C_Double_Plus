#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution105
{
#pragma region Paste to execute 
	/*
	#include "Medium\0105.Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp"
	using namespace Solution105;
	using namespace std;

	int main()
	{
		Solution105::Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal useClass;
		Solution105::Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal::Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.buildTree(getTestModel.preorder, getTestModel.inorder);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.buildTree(getTestModel.preorder, getTestModel.inorder);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 從先序和中序遍歷構造二叉樹
	/// </summary>
	class Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal
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
		class Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model
		{
		public:
			vector<int> preorder;
			vector<int> inorder;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：
		///       Runtime :  16 ms Beats 86.57 %
		///  Memory Usage :26.3 MB Beats 50.14 %
		/// </summary>
		unordered_map<int, int> _hashTable;
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			
			//1. 初始化資料
			for (int index = 0; index < inorder.size(); index++)
				_hashTable[inorder[index]] = index;
			
			return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
		}

		TreeNode* buildTreeHelper(
			vector<int>& preorder, int preorderStartIndex, int preorderEndIndex, 
			vector<int>& inorder, int inorderStartIndex, int inorderEndIndex)
		{
			if (preorderStartIndex == preorderEndIndex)
				return NULL;
			int root_val = preorder[preorderStartIndex];
			TreeNode* root = new TreeNode(root_val);
			int i_root_index = _hashTable[root_val];
			int leftNum = i_root_index - inorderStartIndex;
			root->left = buildTreeHelper(preorder, preorderStartIndex + 1, preorderStartIndex + leftNum + 1, 
				                          inorder,      inorderStartIndex,                     i_root_index);
			root->right = buildTreeHelper(preorder, preorderStartIndex + leftNum + 1, preorderEndIndex, 
				                           inorder,                 i_root_index + 1,  inorderEndIndex);
			return root;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model GetTestData001(void)
		{
			Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model result;			
			result.preorder = { 3, 9, 20, 15, 7 };
			result.inorder = { 9, 3, 15, 20, 7 };
			return result;//expect: [3, 9, 20, null, null, 15, 7]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model GetTestData002(void)
		{
			Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model result;
			result.preorder = {-1};
			result.inorder = {-1};
			return result;//expect: [-1]
		};
#pragma endregion TestData
	};
}
