#include <iostream>
#include <vector>
using namespace std;

namespace Solution124
{
#pragma region Paste to execute 
	/*
	#include "Hard\0124.Binary_Tree_Maximum_Path_Sum.cpp"
	using namespace Solution124;
	using namespace std;

	int main()
	{
		Solution124::Binary_Tree_Maximum_Path_Sum useClass;
		Solution124::Binary_Tree_Maximum_Path_Sum::Binary_Tree_Maximum_Path_Sum_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.maxPathSum(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.maxPathSum(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 二叉樹最大路徑和
	/// </summary>
	class Binary_Tree_Maximum_Path_Sum
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
		class Binary_Tree_Maximum_Path_Sum_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：需要用一個變數紀錄當前走的節點的最大值，本題難點在於如何走節點
		///                1. 以當前節點的左右子節點，都進行遞迴，每個節點重複進行1.
		///                2. 當走到底時，會返還自己值
		///                3. 由底部往上返還時，返還自己+下面子節點路徑的值
		///                再重複2,3 步驟的過程中，已確保每個節點都是只走一次，因此紀錄的最大值就是結果
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		int _result = INT_MIN;
		int maxPathSum(TreeNode* root) 
		{
			FindMaxSum(root);
			return _result;
		}
		int FindMaxSum(TreeNode* node) 
		{
			//1. 跳出條件
			if (node == nullptr)
				return 0;
			//2. 深入左、右子節點
			int left = max(FindMaxSum(node->left), 0);
			int right = max(FindMaxSum(node->right), 0);
			//3. 刷新最大值
			_result = max(_result, left + right + node->val);
			//4. 返還上
			return max(left, right) + node->val;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Binary_Tree_Maximum_Path_Sum_Model GetTestData001(void)
		{
			Binary_Tree_Maximum_Path_Sum_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(3);

			return result;//expect:6
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Binary_Tree_Maximum_Path_Sum_Model GetTestData002(void)
		{
			Binary_Tree_Maximum_Path_Sum_Model result;
			result.root = new TreeNode(-10);
			result.root->left = new TreeNode(9);
			result.root->right = new TreeNode(20);

			result.root->right->left = new TreeNode(15);
			result.root->right->right = new TreeNode(7);

			return result;//expect: 42
		};

#pragma endregion TestData
	};
}
