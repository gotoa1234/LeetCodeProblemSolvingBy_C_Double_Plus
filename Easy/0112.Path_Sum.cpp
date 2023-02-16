#include <iostream>
#include <vector>
using namespace std;

namespace Solution112
{
#pragma region Paste to execute 
	/*
	#include "Easy\0112.Path_Sum.cpp"
	using namespace Solution112;
	using namespace std;

	int main()
	{
		Solution112::Path_Sum useClass;
		Solution112::Path_Sum::Path_Sum_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.hasPathSum(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.hasPathSum(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 路徑加總
	/// </summary>
	class Path_Sum
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
		class Path_Sum_Model
		{
		public:
			TreeNode* root;
			int targetSum;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：利用遞迴跑到Left與Right節點都為空時進行比較，若已經找到了，則可以強制中斷遞迴
		///       Runtime :    3 ms Beats 99.24 %
		///  Memory Usage : 21.3 MB Beats 45.26 %
		/// </summary>
		bool _isHas = false;
		bool hasPathSum(TreeNode* root, int targetSum) 
		{
			//1. 空必定為false
			if (root == nullptr)
				return false;
			//2. 遞迴找出結果
			return CaculateFind(root, targetSum, 0);
		}

		int CaculateFind(TreeNode* root, int& targetSum, int total)
		{
			//3-1. 已經找到就可以全部中斷，返回True
			if (_isHas)
				return _isHas;
			//4. 只有當Left與Right 都為空時比較
			if (root->left == nullptr && root->right == nullptr)
			{
				if (total + root->val == targetSum)
					_isHas = true;				
				return _isHas;
			}
			//3-2. 左節點可以往下繼續計算
			if(root->left)
				CaculateFind(root->left, targetSum, root->val + total);
			//3-3. 右節點可以往下繼續計算
			if(root->right)
			    CaculateFind(root->right, targetSum, root->val + total);
			//3-4. 上述都跑完直接返回當前計算結果即可
			return _isHas;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Path_Sum_Model GetTestData001(void)
		{
			Path_Sum_Model result;
			result.targetSum = 22;
			result.root = new TreeNode(5);
			result.root->left = new TreeNode(4);
			result.root->right = new TreeNode(8);

			result.root->left->left = new TreeNode(11);
			//result.root->left->right = new TreeNode();
			result.root->left->left->left = new TreeNode(7);
			result.root->left->left->right = new TreeNode(2);

			result.root->right->left = new TreeNode(13);
			result.root->right->right = new TreeNode(4);

			result.root->right->left->left = new TreeNode(1);
			return result;//expect:  true			
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Path_Sum_Model GetTestData002(void)
		{
			Path_Sum_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(3);
			result.targetSum = 5;
			return result;//expect: false
		};


		/// <summary>
		/// 測試資料3
		/// </summary>   
		Path_Sum_Model GetTestData003(void)
		{
			Path_Sum_Model result;
			result.targetSum = 0;
			return result;//expect: false		
		};

#pragma endregion TestData
	};
}
