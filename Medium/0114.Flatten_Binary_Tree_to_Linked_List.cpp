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
		///          思路：
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		void flatten(TreeNode* root) {

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
			result.root->left->left->right = new TreeNode(6);

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
