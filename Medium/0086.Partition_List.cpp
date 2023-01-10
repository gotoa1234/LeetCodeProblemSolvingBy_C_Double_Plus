#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution86
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0086.Partition_List.cpp"
    using namespace Solution86;

    int main()
    {
        Solution86::Partition_List useClass;
        Solution86::Partition_List::Partition_List_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.partition(getTestModel.head, getTestModel.x);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.partition(getTestModel.head, getTestModel.x);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �q�ƧǦC���R�����ƶ�
    /// </summary>
    class Partition_List
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
        class Partition_List_Model
        {
        public:
            ListNode* head;
            int x;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Q�Ψ�Ӹ`�I�A�@�Ӭ����p��X���A�t�@�Ӭ����j��x���A�̫�N�p���`�I�P�j���`�I��_��
        ///      Runtime :    3 ms Beats 96.56 %
        /// Memory Usage : 10.2 MB Beats 74.99 %
        /// </summary>
        /// <returns></returns>
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode* minList = new ListNode(0);
            ListNode* bigList = new ListNode(0);
            ListNode* minMoveNode = minList;
            ListNode* bigMoveNode = bigList;
            //1. �M���Ƕi��head�`�I
            while (head)
            {
                //1-1. �p��x��i minList��
                if (head->val < x)
                {
                    minMoveNode->next = head;
                    minMoveNode = minMoveNode->next;
                }
                else//1-2. �j�󵥩�x��i bigList��
                {
                    bigMoveNode->next = head;
                    bigMoveNode = bigMoveNode->next;
                }
                head = head->next;
            }
            //�N�p + �j �쵲����X��
            minMoveNode->next = bigList->next;
            bigMoveNode->next = nullptr;
            return minList->next;//�^��
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Partition_List_Model GetTestData001(void)
        {
            Partition_List_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 1, 4, 3, 2, 5, 2 };
            result.head = ConstructNodes(l1Vectors);
            result.x = 3;
            return result;//expect:  [1, 2, 2, 4, 3, 5]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Partition_List_Model GetTestData002(void)
        {
            Partition_List_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 2,1 };
            result.head = ConstructNodes(l1Vectors);
            result.x = 2;
            return result;//expect:[1,2]
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