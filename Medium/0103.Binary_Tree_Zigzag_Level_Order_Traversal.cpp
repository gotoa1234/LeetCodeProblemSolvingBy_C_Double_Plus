#include <iostream>
#include <vector>
using namespace std;

namespace Solution103
{
#pragma region Paste to execute 
	/*
	#include "Medium\0103.Binary_Tree_Level_Order_Traversal.cpp"
	using namespace Solution103;
	using namespace std;


	int main()
	{
		Solution103::Binary_Tree_Level_Order_Traversal useClass;
		Solution103::Binary_Tree_Level_Order_Traversal::Binary_Tree_Level_Order_Traversal_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.zigzagLevelOrder(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.zigzagLevelOrder(getTestModel.root);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.zigzagLevelOrder(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 二元樹階層順序旅行
	/// </summary>
	class Binary_Tree_Level_Order_Traversal
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
		class Binary_Tree_Level_Order_Traversal_Model
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
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			return {};
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Binary_Tree_Level_Order_Traversal_Model GetTestData001(void)
		{
			Binary_Tree_Level_Order_Traversal_Model result;
			TreeNode* root = new TreeNode(3);
			root->left = new TreeNode(9);
			root->right = new TreeNode(20);

			/*root->left->left = new TreeNode();
			root->left->right = new TreeNode();*/

			root->right->left = new TreeNode(15);
			root->right->right = new TreeNode(7);
			result.root = root;
			return result;//expect: [[3],[20,9],[15,7]]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Binary_Tree_Level_Order_Traversal_Model GetTestData002(void)
		{
			Binary_Tree_Level_Order_Traversal_Model result;
			TreeNode* root = new TreeNode(1);
			result.root = root;
			return result;//expect: [[1]]
		};

		/// <summary>
        /// 測試資料3
        /// </summary>   
		Binary_Tree_Level_Order_Traversal_Model GetTestData003(void)
		{
			Binary_Tree_Level_Order_Traversal_Model result;
			return result;//expect: [[]]
		};
#pragma endregion TestData
	};
}
