#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

namespace Solution113
{
#pragma region Paste to execute 
	/*
    #include "Medium\0113.Path_Sum_II.cpp"
    using namespace Solution113;
    using namespace std;
    
    int main()
    {
    	Solution113::Path_Sum useClass;
    	Solution113::Path_Sum::Path_Sum_II_Model getTestModel = useClass.GetTestData001();
    	auto result1 = useClass.pathSum(getTestModel.root, getTestModel.targetSum);
    
    	getTestModel = useClass.GetTestData002();
    	auto result2 = useClass.pathSum(getTestModel.root, getTestModel.targetSum);
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ���|�[�`2
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
		class Path_Sum_II_Model
		{
		public:
			TreeNode* root;
			int targetSum;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G�P112�A�]���j�A�C�����P�_�l�`�I�O�_�s�b��
		///               �Y�L�h��ܥi�H�i���e���|���ȬO�_�P�ؼФ@�P�C
		///       Runtime :  3 ms Beats 99.7 %
		///  Memory Usage : 20 MB Beats 47.6 %
		/// </summary>
		vector<vector<int>> _result{};
		int _targetSum;
		vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
		{
			//����Ū��`�I�i�J
			if (root == nullptr)
				return {};

			_result = vector<vector<int>>();
			_targetSum = targetSum;
			//1. �Q�Τ@�Ӱ}�C����������e���`�I�ƭȲզX
			vector<int> tempCompose{};
			FindCompose(root, tempCompose);
			return _result;
		}

		void FindCompose(TreeNode* root, vector<int>& tempCompose)
		{
			//2-1. �����ɥ��N������Root->val �ȩ�J�զ�tempCompose��
			tempCompose.push_back(root->val);
			if (root->left == nullptr && root->right == nullptr)
			{
				//3. �Y�l�`�I���L�ȡA�h�N��e���զ��[�`����A�ۦP�h�[�J���G��
				auto sumResult = accumulate(tempCompose.begin(), tempCompose.end(), 0);
				if (sumResult == _targetSum)
					_result.push_back(tempCompose);
			}
			else if (root->left == nullptr && root->right)//2-2. �u���k�l�`�I���Ȫ����p
				FindCompose(root->right, tempCompose);
			else if (root->left && root->right == nullptr)//2-3. �u�����l�`�I���Ȫ����p
				FindCompose(root->left, tempCompose);
			else//2-5. �l�`�I�����Ȫ����p
			{
				FindCompose(root->right, tempCompose);
				FindCompose(root->left, tempCompose);
			}
			//2.6. �p�G���ɡA�h�N����root->val����Rollback
			tempCompose.pop_back();
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Path_Sum_II_Model GetTestData001(void)
		{
			Path_Sum_II_Model result;
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

			result.root->right->right->left = new TreeNode(5);
			result.root->right->right->right = new TreeNode(1);
			return result;//expect:  [[5,4,11,2],[5,8,4,5]]			
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Path_Sum_II_Model GetTestData002(void)
		{
			Path_Sum_II_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(3);
			result.targetSum = 5;
			return result;//expect: []
		};


		/// <summary>
		/// ���ո��3
		/// </summary>   
		Path_Sum_II_Model GetTestData003(void)
		{
			Path_Sum_II_Model result;
			result.targetSum = 0;
			return result;//expect: []
		};

#pragma endregion TestData
	};
}
