#include <iostream>
#include <vector>
using namespace std;

namespace Solution226
{
#pragma region Paste to execute 
    /*
    #include "0226.Reverse_Linked_List.cpp"
    using namespace Solution226;
    using namespace std;

    Solution226::Reverse_Linked_List useClass;
    Solution226::Reverse_Linked_List::Reverse_Linked_List_Model getTestModel = useClass.GetTestData001();
    auto result = useClass.invertTree(getTestModel.root);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// ����G�e��
    /// </summary>
    class Reverse_Linked_List
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
        class Reverse_Linked_List_Model
        {
        public:
            TreeNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�C���N��e���`�I���U����ӥ��k�`�I�����A���쨫�쩳�A�Y��������G����      
        ///               STEP 1:  �@�}�l��4�}�l�A�N���U����ӥ��k�`�I�洫
        ///                    [4]        
        ///                 2       7
        ///               1   3   6   9
        /// 
        ///               STEP 2: ���S�����쩳�A�ҥH�N7 ���U����ӥ��k�`�I�洫
        ///                     4        
        ///                 2      [7]
        ///               1   3   6   9
        /// 
        ///               STEP 3: �o��9���U��null �ҥH�P�`�I6���洫
        ///                      4        
        ///                 2         7
        ///               1   3   [6]   [9]
        /// 
        ///               STEP 4: �^��7�A�]�����U�w�洫�����A�Ѧۤv��2�洫
        ///                      4        
        ///                [2]        [7]
        ///               1   3     9     6
        /// 
        ///               STEP 5: 7�P2�洫�����A�}�l�q�`�I2 ���U�]
        ///                       4        
        ///                  7        [2]
        ///                9   6    1     3
        ///  
        ///              STEP 6: 3�P1�I���A�^��2�ɵo�{�w�����A�ҥH�A�^��4 �A����4�O�ڸ`�I�ҥH����
        ///                       4        
        ///                  7          2
        ///                9   6     3     1
        ///      Runtime : 0 ms Beats 100 %
        /// Memory Usage : 9.8 MB Beats 5.14 %
        TreeNode* invertTree(TreeNode* root) 
        {
            if (root == nullptr)
                return nullptr;
            auto tempNode = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(tempNode);
            return root
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Reverse_Linked_List_Model GetTestData001(void)
        {
            Reverse_Linked_List_Model result;
			vector<int> l1Vectors = { 2,1,3 };
            result.head = ConstructNodes(l1Vectors);
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Reverse_Linked_List_Model GetTestData002(void)
        {
            Reverse_Linked_List_Model result;
            vector<int> l1Vectors = {};
            result.head = ConstructNodes(l1Vectors);
            return result;
        };

      
    private:
        TreeNode* ConstructNodes(vector<int>& inputDatas)
        {
            TreeNode* nodeHeads = NULL;
            TreeNode* moveNode = NULL;
            for (auto& myItem : inputDatas)
            {
                TreeNode* newItem = new TreeNode(myItem);
                if (nodeHeads == NULL)
                {
                    nodeHeads = newItem;
                    moveNode = nodeHeads;
                    continue;
                }
                moveNode->next = newItem;
                moveNode = newItem;
            }
            return nodeHeads;
        };
#pragma endregion TestData
    };
}