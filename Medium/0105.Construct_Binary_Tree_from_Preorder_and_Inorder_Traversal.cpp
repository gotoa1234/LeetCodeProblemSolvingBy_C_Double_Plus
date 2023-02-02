#include <iostream>
#include <vector>
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
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			return {};
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
