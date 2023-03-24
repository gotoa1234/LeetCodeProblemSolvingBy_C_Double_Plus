#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution148
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0148.Sort_List.cpp"
    using namespace Solution148;

    int main()
    {
        Solution148::Sort_List useClass;
        Solution148::Sort_List::Sort_List_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.sortList(getTestModel.head);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.sortList(getTestModel.head);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.sortList(getTestModel.head);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �ƧǦC��
    /// </summary>
    class Sort_List
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
        class Sort_List_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///     �D�حn�D�G Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
        ///         ����G ���i��147 �D�W���@�k�A�L�k�F�� Space : O(1) �A�o�D�ݭn�Q�ΦX�ֱƧǪk�A�Q�ΧֺC���w���ΥX����
        ///                ���`�I���Φܳ�Ӹ`�I�A�M�ᤣ�_Merge�X�ƧǪ����G
        ///         �|�ҡG ���w[4,2,1,3]
        ///                STEP 1�G       [4, 2, 1, 3]            (����)
        ///                STEP 2�G    [4, 2]  +  [1,3]           (����)
        ///                STEP 3�G [4] + [2]  �P  [1] + [3]      (����)
        ///                STEP 4�G    [2, 4]  +  [1,3]           (�X��)
        ///                STEP 5�G    [1] [2, 4, 4]              (�X��)
        ///                STEP 6�G    [1] [2, 4, 3]              (�X��)
        ///                STEP 7�G    [1, 2] [4, 3]              (�X��)
        ///                STEP 8�G    [1, 2, 3] [4]              (�X��)
        ///                STEP 9�G    [1, 2, 3, 4]               (����)
        ///      Runtime�G  196 ms Beats 77.77
        /// Memory Usage�G 53.2 MB Beats 77.60
        /// </summary>
        /// <returns></returns>
    public:
        ListNode* sortList(ListNode* head) 
        {
            //1. ���X����
            if (!head || !head->next) 
                return head;
            //2-1. �Q�ΤT��Node ���X�ֺC���w
            ListNode* slowNode = head;
            ListNode* fastNode = head;
            ListNode* moveNode = head;
            while (      fastNode != nullptr && 
                   fastNode->next != nullptr) 
            {
                moveNode = slowNode;
                slowNode = slowNode->next;
                fastNode = fastNode->next->next;
            }
            //2-2. �o�N�|��N��Ӧ������ 1/2 
            moveNode->next = NULL;
            //3. �N���b�䪺�`�I�̻P�k�b�����`�I��������ΡA�̫�X��
            return merge(sortList(head), sortList(slowNode));
        }

        ListNode* merge(ListNode* leftEdgeNode, ListNode* rightEdgeNode) 
        {
            //4-1. ���X����
            if (leftEdgeNode == nullptr) 
                return rightEdgeNode;
            if (rightEdgeNode == nullptr) 
                return leftEdgeNode;

            //4-2. �N�`�I���i��X�ֱƧ�
            if ( leftEdgeNode->val < rightEdgeNode->val) 
            {
                leftEdgeNode->next = merge(leftEdgeNode->next, rightEdgeNode);
                return leftEdgeNode;
            }
            else 
            {
                rightEdgeNode->next = merge(leftEdgeNode, rightEdgeNode->next);
                return rightEdgeNode;
            }
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Sort_List_Model GetTestData001(void)
        {
            Sort_List_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 4, 2, 1, 3 };
            result.head = ConstructNodes(l1Vectors);
            return result;//expect:  [1,2,3,4]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Sort_List_Model GetTestData002(void)
        {
            Sort_List_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { -1, 5, 3, 4 , 0 };
            result.head = ConstructNodes(l1Vectors);
            return result;//expect:[-1, 0, 3, 4, 5]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Sort_List_Model GetTestData003(void)
        {
            Sort_List_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { };
            result.head = ConstructNodes(l1Vectors);
            return result;//expect:[]
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