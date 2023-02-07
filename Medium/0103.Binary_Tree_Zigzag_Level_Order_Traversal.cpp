#include <iostream>
#include <vector>
using namespace std;

namespace Solution103
{
#pragma region Paste to execute 
	/*
	#include "Medium\0103.Binary_Tree_Zigzag_Level_Order_Traversal.cpp"
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
		///          思路：利用遞迴 + 層級，逐層添加陣列元素
		///       Runtime : 0 ms Beats  100 %
		///  Memory Usage :13 MB Beats 5.37 %
		/// </summary>
		vector<vector<int>> _reulst;
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			//1. 從根結點開始
			ComposeLevelNode(root, 0);
			return _reulst;
		}

		void ComposeLevelNode(TreeNode* node, int level) 
		{
			//2. 若傳遞來節點為Null表示不用往下-可中止
			if (node == nullptr) 
				return;
			//3. 若該階層尚未有資料，則建立
			if (_reulst.size() == level) 
				_reulst.push_back({});
			//4-1. 奇數塞入方式:左->右
			if (level % 2 == 0) 
				_reulst[level].push_back(node->val);
			else//4-2. 偶數塞入方式:右->左
				_reulst[level].insert(_reulst[level].begin(), node->val);
			//5. 重複將當前節點的下兩個節點遞迴處理，且深度+1
			ComposeLevelNode(node->left, level + 1);
			ComposeLevelNode(node->right, level + 1);
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
			result.root = nullptr;
			return result;//expect: [[]]
		};
#pragma endregion TestData
	};
}
