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
	/// ���|�[�`
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
		///          ����G�Q�λ��j�]��Left�PRight�`�I�����Ůɶi�����A�Y�w�g���F�A�h�i�H�j��_���j
		///       Runtime :    3 ms Beats 99.24 %
		///  Memory Usage : 21.3 MB Beats 45.26 %
		/// </summary>
		bool _isHas = false;
		bool hasPathSum(TreeNode* root, int targetSum) 
		{
			//1. �ť��w��false
			if (root == nullptr)
				return false;
			//2. ���j��X���G
			return CaculateFind(root, targetSum, 0);
		}

		int CaculateFind(TreeNode* root, int& targetSum, int total)
		{
			//3-1. �w�g���N�i�H�������_�A��^True
			if (_isHas)
				return _isHas;
			//4. �u����Left�PRight �����Ůɤ��
			if (root->left == nullptr && root->right == nullptr)
			{
				if (total + root->val == targetSum)
					_isHas = true;				
				return _isHas;
			}
			//3-2. ���`�I�i�H���U�~��p��
			if(root->left)
				CaculateFind(root->left, targetSum, root->val + total);
			//3-3. �k�`�I�i�H���U�~��p��
			if(root->right)
			    CaculateFind(root->right, targetSum, root->val + total);
			//3-4. �W�z���]��������^��e�p�⵲�G�Y�i
			return _isHas;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
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
		/// ���ո��2
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
		/// ���ո��3
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
