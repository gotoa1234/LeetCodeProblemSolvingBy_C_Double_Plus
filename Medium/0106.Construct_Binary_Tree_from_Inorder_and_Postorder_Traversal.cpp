#include <iostream>
#include <vector>
using namespace std;

namespace Solution106
{
#pragma region Paste to execute 
	/*
	#include "Medium\0106.Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp"
	using namespace Solution106;
	using namespace std;

	int main()
	{
		Solution106::Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal useClass;
		Solution106::Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal::Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.buildTree(getTestModel.inorder, getTestModel.postorder);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.buildTree(getTestModel.inorder, getTestModel.postorder);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 從中序和後序遍歷構建二叉樹
	/// </summary>
	class Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal
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
		class Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model
		{
		public:
			vector<int> inorder;
			vector<int> postorder;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
			return {};
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model GetTestData001(void)
		{
			Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model result;
			result.inorder = { 3, 9, 20, 15, 7 };
			result.postorder = { 9, 3, 15, 20, 7 };
			return result;//expect: [3, 9, 20, null, null, 15, 7]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model GetTestData002(void)
		{
			Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model result;
			result.inorder = { -1 };
			result.postorder = { -1 };
			return result;//expect: [-1]
		};
#pragma endregion TestData
	};
}
