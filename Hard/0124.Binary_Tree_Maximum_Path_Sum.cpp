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
	/// �G�e��̤j���|�M
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
		///          ����G�ݭn�Τ@���ܼƬ�����e�����`�I���̤j�ȡA���D���I�b��p�󨫸`�I
		///                1. �H��e�`�I�����k�l�`�I�A���i�滼�j�A�C�Ӹ`�I���ƶi��1.
		///                2. ���쩳�ɡA�|���٦ۤv��
		///                3. �ѩ������W���ٮɡA���٦ۤv+�U���l�`�I���|����
		///                �A����2,3 �B�J���L�{���A�w�T�O�C�Ӹ`�I���O�u���@���A�]���������̤j�ȴN�O���G
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
			//1. ���X����
			if (node == nullptr)
				return 0;
			//2. �`�J���B�k�l�`�I
			int left = max(FindMaxSum(node->left), 0);
			int right = max(FindMaxSum(node->right), 0);
			//3. ��s�̤j��
			_result = max(_result, left + right + node->val);
			//4. ���٤W
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
