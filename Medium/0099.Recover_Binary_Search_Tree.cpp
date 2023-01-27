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
	/// 恢復二叉搜索樹
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
		///          思路： 依照二分搜尋樹特性 - 節結點的左節點都比根節點小 / 根節點的右節點都比根節點大
		///                 提姆給
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
				//2-1. 檢查左節點若有節點時
				if (currentNode->left) 
				{
					//2-2. 從該左節點開始檢查
					moveNode = currentNode->left;
					//2-3. 該左節點的右邊節點存在時遍歷
					while (moveNode->right && moveNode->right != currentNode) 
						moveNode = moveNode->right;
					//2-4. 當右節點為Null時，將當前檢查的對象改為此節點
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
					//3-1. 找到錯誤的節點值，要進行紀錄
					if (FindNeedReplaceNode == nullptr) 
						FindNeedReplaceNode = lastNode;
					//3-2. 若first已經有值，表示找到更新需更換的節點
					replaceNode = currentNode;
				}
				lastNode = currentNode;
				currentNode = currentNode->right;
			}
			//4. 找到的兩個值替換
			swap(FindNeedReplaceNode->val, replaceNode->val);
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
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
		/// 測試資料2
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