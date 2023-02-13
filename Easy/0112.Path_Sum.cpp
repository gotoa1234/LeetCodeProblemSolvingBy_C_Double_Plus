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
		///          思路：
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		bool hasPathSum(TreeNode* root, int targetSum) {
			return {};
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
