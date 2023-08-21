#include <iostream>
#include <vector>
using namespace std;

namespace Solution404
{
#pragma region Paste to execute 
	/*
	#include "Easy/0404.Binary_Tree_Inorder_Traversal.cpp"
	using namespace Solution404;
	using namespace std;

	int main()
	{
	Solution404::Sum_of_Left_Leaves useClass;
	Solution404::Sum_of_Left_Leaves::Sum_of_Left_Leaves_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.sumOfLeftLeaves(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.sumOfLeftLeaves(getTestModel.root);

	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 左節點加總
	/// </summary>
	class Sum_of_Left_Leaves
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
		class Sum_of_Left_Leaves_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：善用遞迴，左節點且沒有子節點的節點加總
		///       Runtime :    0 ms Beats 100 %
		///  Memory Usage : 13.4 MB Beats 25.42 %
		/// </summary>
		int _result = 0;
		int sumOfLeftLeaves(TreeNode* root) {
			_result = 0;
			FindLeftNode(root, false);
			return _result;
		}

		void FindLeftNode(TreeNode* root, bool isLeftNode)
		{
			if (root->left == nullptr &&
				root->right == nullptr &&
				isLeftNode) {
				_result += root->val;
			}
			if (root->left)
				FindLeftNode(root->left, true);
			if (root->right)
				FindLeftNode(root->right, false);
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Sum_of_Left_Leaves_Model GetTestData001(void)
		{
			Sum_of_Left_Leaves_Model result;
			result.root = new TreeNode(3);
			result.root->left = new TreeNode(9);
			result.root->right = new TreeNode(20);
			result.root->right->left = new TreeNode(15);
			result.root->right->right = new TreeNode(7);
			return result;//expect: 24  因為 9 + 15
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Sum_of_Left_Leaves_Model GetTestData002(void)
		{
			Sum_of_Left_Leaves_Model result{};
			result.root = new TreeNode(1);
			return result;//expect:0
		};

	private:

#pragma endregion TestData
	};
}