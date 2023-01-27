#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution99
{
#pragma region Paste to execute 
	/*
    #include "Medium\0099.Recover_Binary_Search_Tree.cpp"
    using namespace Solution99;
    using namespace std;
    int main()
    {
    	Solution99::Recover_Binary_Search_Tree useClass;
    	Solution99::Recover_Binary_Search_Tree::Recover_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
    	useClass.recoverTree(getTestModel.root);
    
    	getTestModel = useClass.GetTestData002();
    	useClass.recoverTree(getTestModel.root);
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ��_�G�e�j����
	/// </summary>
	class Recover_Binary_Search_Tree
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
		class Recover_Binary_Search_Tree_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G �̷ӤG���j�M��S�� - �`���I�����`�I����ڸ`�I�p / �ڸ`�I���k�`�I����ڸ`�I�j
		///                 ���i��
		///       Runtime: 
		///  Memory Usage :
		/// </summary>
		void recoverTree(TreeNode* root) {
			TreeNode* FindNeedReplaceNode = nullptr; 
			TreeNode* replaceNode = nullptr; 
			for(TreeNode* currentNode = root, *lastNode = nullptr, *moveNode = nullptr;
				currentNode!=nullptr;	
			    )
			{
				//2-1. �ˬd���`�I�Y���`�I��
				if (currentNode->left) 
				{
					//2-2. �q�ӥ��`�I�}�l�ˬd
					moveNode = currentNode->left;
					//2-3. �ӥ��`�I���k��`�I�s�b�ɹM��
					while (moveNode->right && moveNode->right != currentNode) 
						moveNode = moveNode->right;
					//2-4. ��k�`�I��Null�ɡA�N��e�ˬd����H�אּ���`�I
					if (moveNode->right == nullptr) 
					{
						moveNode->right = currentNode;
						currentNode = currentNode->left;
						continue;
					}
					else 
						moveNode->right = NULL;
				}

				if (lastNode && currentNode->val < lastNode->val) 
				{
					//3-1. �����~���`�I�ȡA�n�i�����
					if (FindNeedReplaceNode == nullptr) 
						FindNeedReplaceNode = lastNode;
					//3-2. �Yfirst�w�g���ȡA��ܧ���s�ݧ󴫪��`�I
					replaceNode = currentNode;
				}
				lastNode = currentNode;
				currentNode = currentNode->right;
			}
			//4. ��쪺��ӭȴ���
			swap(FindNeedReplaceNode->val, replaceNode->val);
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Recover_Binary_Search_Tree_Model GetTestData001(void)
		{
			Recover_Binary_Search_Tree_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(3);
			result.root->left->right = new TreeNode(2);
			return result;
            return result;//expect:  [3,1,null,null,2]
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Recover_Binary_Search_Tree_Model GetTestData002(void)
		{
			Recover_Binary_Search_Tree_Model result;
			result.root = new TreeNode(3);
			result.root->left = new TreeNode(1);
			result.root->right = new TreeNode(4);
			result.root->right->left= new TreeNode(2);
            return result;//expect:  [2,1,4,null,null,3]
		};
	 private:
#pragma endregion TestData
	};
}