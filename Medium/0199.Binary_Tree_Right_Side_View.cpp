#include <iostream>
#include <vector>
using namespace std;

namespace Solution199
{
#pragma region Paste to execute 
	/*
	#include "0199.Binary_Tree_Right_Side_View.cpp"
	using namespace Solution199;
	using namespace std;

	Solution199::Binary_Tree_Right_Side_View useClass;
	Solution199::Binary_Tree_Right_Side_View::Binary_Tree_Right_Side_View_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.rightSideView(getTestModel.root);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �G����k�����
	/// </summary>
	class Binary_Tree_Right_Side_View
	{
#pragma region Model
	public:
		//Definition for singly-linked list.
		struct TreeNode {
			int val;
			TreeNode* left;
			TreeNode* right;
			TreeNode(int x) : val(x), left(NULL), right(NULL) {}
		};
	public:
		class Binary_Tree_Right_Side_View_Model
		{
		public:
			TreeNode* root;
			TreeNode* p;
			TreeNode* q;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G�i�H�ݦ��C�@�h�u���̥k�䪺�`�I�|�������A�]�����j�`�I��
		///                �N��ӼhLevel�@�����ޡA�p�G�w�O���N���L�A�_�h�O�U�����Ӽh�̥k��`�I
		///      Runtime :   0 ms Beats   100 %
		/// Memory Usage :11.9 MB Beats	62.95 %
		/// </summary>
		vector<int> _result{};
		vector<int> rightSideView(TreeNode* root) {
			if (root)		
				ViewsNode(root, 0);			
			return _result;
		}

		void ViewsNode(TreeNode* current, int level)
		{
			if (_result.size() <= level)
				_result.push_back(current->val);
			if (current->right)
				ViewsNode(current->right, level + 1);
			if (current->left)
				ViewsNode(current->left, level + 1);
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Binary_Tree_Right_Side_View_Model GetTestData001(void)
		{
			Binary_Tree_Right_Side_View_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(3);

			//result.root->left->left = new TreeNode(0);
			result.root->left->right = new TreeNode(5);

			/*result.root->right->left = new TreeNode(0);*/
			result.root->right->right = new TreeNode(4);			
			return result;//EXPECT: [1,3,4]
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Binary_Tree_Right_Side_View_Model GetTestData002(void)
		{
			Binary_Tree_Right_Side_View_Model result;
			result.root = new TreeNode(1);
			//result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(3);

			return result;//Expect :  [1,3]
		};
#pragma endregion TestData
	};
}