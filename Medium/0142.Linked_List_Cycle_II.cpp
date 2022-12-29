#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution142
{
#pragma region Paste to execute 
    /*
    #include "0142.Linked_List_Cycle_II.cpp"
    using namespace Solution142;
    using namespace std;

    Solution142::Linked_List_Cycle_II useClass;
    Solution142::Linked_List_Cycle_II::Linked_List_Cycle_II_Model getTestModel = useClass.GetTestData001();
    Solution142::Linked_List_Cycle_II::ListNode* result = useClass.detectCycle(getTestModel.head);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// �`���`�I�A��X�`���}�l���`�I
    /// </summary>
    class Linked_List_Cycle_II
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
    public:
        class Linked_List_Cycle_II_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G �Q��141. �D����k��X�O�_�^��A�M��Q�Ψ�1�B���`�I �P head �`�I�@�_���e�A�����I�쪺���w���_�l�I
        ///      Runtime :   6 ms, faster than 94.92% of C++ online submissions for Linked List Cycle II.
        /// Memory Usage : 7.4 MB,   less than 99.09% of C++ online submissions for Linked List Cycle II.

        ListNode* detectCycle(ListNode* head) {
            
            ListNode* oneStepNode = head;
            ListNode* twoStepNode = head;
            ListNode* entry = head;
            
            while (twoStepNode != NULL && twoStepNode->next != NULL)
            {
                oneStepNode = oneStepNode->next;
                if (twoStepNode->next == NULL)
                    break;
                else
                    twoStepNode = twoStepNode->next->next;

                if (oneStepNode == twoStepNode)
                {
                    //�Q��1�B�`�I + �Y�`�I �������e�����|�A�N�O�_�I
                    while (oneStepNode != entry) 
                    {
                        oneStepNode = oneStepNode->next; 
                        entry = entry->next;
                    }
                    return entry;
                }       
            }
            return NULL;
        }

#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Linked_List_Cycle_II_Model GetTestData001(void)
        {
            Linked_List_Cycle_II_Model result;
            vector<int> l1Vectors = {3, 2, 0, -4};
            result.head = ConstructNodes(l1Vectors);
            //�D�ز�[3] -> [1] �Ӹ`�I�@���`��
            result.head->next->next->next->next = result.head->next;
            return result;
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Linked_List_Cycle_II_Model GetTestData002(void)
        {
            Linked_List_Cycle_II_Model result;
            vector<int> l1Vectors = { 1, 2 };
            result.head = ConstructNodes(l1Vectors);
            //�D�ز�[1] -> [0] �Ӹ`�I�@���`��
            result.head->next->next = result.head;
            return result;
        };

        /// <summary>
        /// ���ո��3
        /// </summary>   
        Linked_List_Cycle_II_Model GetTestData003(void)
        {
            Linked_List_Cycle_II_Model result;
            vector<int> l1Vectors{1};
            result.head = ConstructNodes(l1Vectors);

            return result;
        };
    private:
        ListNode* ConstructNodes(vector<int>& inputDatas)
        {
            ListNode* nodeHeads = NULL;
            ListNode* moveNode = NULL;
            for (auto& myItem : inputDatas)
            {
                ListNode* newItem = new ListNode(myItem);
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