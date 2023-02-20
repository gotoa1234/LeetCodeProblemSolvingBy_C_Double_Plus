#include <iostream>
#include <vector>
using namespace std;

namespace Solution114
{
#pragma region Paste to execute 
	/*
	#include "Medium\0114.Flatten_Binary_Tree_to_Linked_List.cpp"
	using namespace Solution114;
	using namespace std;

	int main()
	{
		Solution114::Flatten_Binary_Tree_to_Linked_List useClass;
		Solution114::Flatten_Binary_Tree_to_Linked_List::Flatten_Binary_Tree_to_Linked_List_Model getTestModel = useClass.GetTestData001();
		useClass.flatten(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		useClass.flatten(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 將二叉樹展平為鍊錶
	/// </summary>
	class Flatten_Binary_Tree_to_Linked_List
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
		class Flatten_Binary_Tree_to_Linked_List_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：題目要求用輸入的root 展開成一條右子樹鏈結串鍊
		///       Runtime :   3 ms Beats 93.58 %
		///  Memory Usage :12.8 MB Beats 49.77 %
		/// </summary>
		void flatten(TreeNode* root) 
		{
			//1. 若根結點為null的狀況下 - 直接中止
			if (root == nullptr)
				return;
			
			//2. 有存在子節點進行遞迴
			if (root->left) 
				flatten(root->left);
			if (root->right) 
				flatten(root->right);

			//3-1. 將root->left 接到當前節點的 right 
			TreeNode* newNode = root->right;
			root->right = root->left;
			root->left = nullptr;
			//3-2. 然後將root->right(原本的root->left) 最後一個位置(nullptr)，將原本的root->right 接上去
			while (root->right) 			
				root = root->right;		
			root->right = newNode;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Flatten_Binary_Tree_to_Linked_List_Model GetTestData001(void)
		{
			Flatten_Binary_Tree_to_Linked_List_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(5);

			result.root->left->left = new TreeNode(3);
			result.root->left->right = new TreeNode(4);
			/*result.root->left->left->left = new TreeNode(7);*/
			result.root->right->right = new TreeNode(6);

			return result;//expect:[1, null, 2, null, 3, null, 4, null, 5, null, 6]
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Flatten_Binary_Tree_to_Linked_List_Model GetTestData002(void)
		{
			Flatten_Binary_Tree_to_Linked_List_Model result;
			result.root = nullptr;
			return result;//expect: []
		};


		/// <summary>
		/// test 3
		/// </summary>   
		Flatten_Binary_Tree_to_Linked_List_Model GetTestData003(void)
		{
			Flatten_Binary_Tree_to_Linked_List_Model result;
			result.root = new TreeNode(0);
			return result;//expect: [0]
		};

#pragma endregion TestData
	};
}
