#include <iostream>
#include <vector>
using namespace std;

namespace Solution109
{
#pragma region Paste to execute 
    /*
    #include "Medium\0109.Convert_Sorted_List_to_Binary_Search_Tree.cpp"
    using namespace Solution109;
    using namespace std;
    
    int main()
    {
        Solution109::Convert_Sorted_List_to_Binary_Search_Tree useClass;
        Solution109::Convert_Sorted_List_to_Binary_Search_Tree::Convert_Sorted_List_to_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
        Convert_Sorted_List_to_Binary_Search_Tree::TreeNode* result = useClass.sortedListToBST(getTestModel.head);
    
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �N�ƧǦC���ഫ���G�e�j����
    /// </summary>
    class Convert_Sorted_List_to_Binary_Search_Tree
    {
#pragma region Model
    public:
        //Definition for singly-linked list.
        struct ListNode {
            int val;
            ListNode* next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode* next) : val(x), next(next) {}
        };
        struct TreeNode {
            int val;
            TreeNode* left;
            TreeNode* right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
        };
    public:
        class Convert_Sorted_List_to_Binary_Search_Tree_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� :�P108�D�A���D�ت���J�Ѽ��ܬ��쵲����A�ҥH�n�Q�������Ъ��覡�A��X�G���j�M�k��������
        ///      Runtime :   23 ms Beats 90.28 %
        /// Memory Usage : 28.4 MB Beats 69.49 %

        TreeNode* sortedListToBST(ListNode* head) {
            //1-1. �ˮַ�e�`�I�O�_��nullptr
            if (head == nullptr)
                return nullptr;
            //1-2. �ˮַ�e�`�I�U�@�I�O�_��nullptr�A��null���`�I���Ȼݭn�����^��
            if (head->next == nullptr)
                return new TreeNode(head->val);
            //2-1. �i��G���j�M�k 
            ListNode* midPointer = head;//�C����1�B
            ListNode* endPointer = head;//�C����2�B�A���쩳�ɡA����midPointer��������
            ListNode* lastPointer = midPointer;//��endPointer���쩳�ɡA����lastPointer�|��midPointer�e�@��
            while (endPointer->next && endPointer->next->next)
            {
                lastPointer = midPointer;
                midPointer = midPointer->next;
                endPointer = endPointer->next->next;
            }
            //2-2. endPointer���F��k�𪺰_�I
            endPointer = midPointer->next;
            //2-3. lastPointer�����]��null�A�����l�𨫨�midPointer�e�@�B(�@�����l����I)
            lastPointer->next = NULL;
            //3-1. ������ + ���� + �k�� �إ�
            TreeNode* cur = new TreeNode(midPointer->val);
            if (head != midPointer)
                cur->left = sortedListToBST(head);
            cur->right = sortedListToBST(endPointer);
            return cur;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Convert_Sorted_List_to_Binary_Search_Tree_Model GetTestData001(void)
        {
            Convert_Sorted_List_to_Binary_Search_Tree_Model result;
            result.head = new ListNode(-10);
            result.head->next = new ListNode(-3);
            result.head->next->next = new ListNode(0);
            result.head->next->next->next = new ListNode(5);
            result.head->next->next->next->next = new ListNode(9);
            return result;//Expect : [0, -3, 9, -10, null, 5]
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Convert_Sorted_List_to_Binary_Search_Tree_Model GetTestData002(void)
        {
            Convert_Sorted_List_to_Binary_Search_Tree_Model result;
            return result;//Expect : [ ]
        };
    private:
        TreeNode* ConstructNodes(vector<int>& inputDatas)
        {
            /*   *int val;
               *TreeNode* left;
               *TreeNode* right;
               *TreeNode() : val(0), left(nullptr), right(nullptr) {}
               *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
               *TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}*/
            TreeNode* nodeHeads = NULL;
            TreeNode* treeLevelHeads = NULL;
            bool switchLevel = true;
            for (auto& myItem : inputDatas)
            {
                if (nodeHeads == NULL)
                {
                    nodeHeads = new TreeNode(myItem);
                    treeLevelHeads = new TreeNode(myItem);
                    continue;
                }

                if (myItem == NULL && switchLevel)
                {

                }


                if (myItem == NULL)
                {
                    continue;
                }
                else
                {
                    TreeNode* newItem = new TreeNode(myItem);
                }
            }
            return nodeHeads;
        };
#pragma endregion TestData
    };
}