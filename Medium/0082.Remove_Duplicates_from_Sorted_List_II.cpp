#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution82
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "medium/0082.Remove_Duplicates_from_Sorted_List_II.cpp"
    using namespace Solution82;

    int main()
    {
        Solution82::Remove_Duplicates_from_Sorted_List_II useClass;
        Solution82::Remove_Duplicates_from_Sorted_List_II::Remove_Duplicates_from_Sorted_List_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.deleteDuplicates(getTestModel.head);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.deleteDuplicates(getTestModel.head);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �q�ƧǦC���R�����ƶ� II
    /// </summary>
    class Remove_Duplicates_from_Sorted_List_II
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
        class Remove_Duplicates_from_Sorted_List_II_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Q��4�Ӹ`�I�i��A1�Ӹ`�I�����_�l�A1�Ӹ`�I�����W�Ӧ�m�A2�Ӹ`�I����X�R���d���        
        ///      Runtime :    7 ms Beats 92.22 %
        /// Memory Usage : 11.2 MB Beats 61.54 %
        /// </summary>
        /// <returns></returns>
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            //1. �ǳƪ�l���
            ListNode* resultNode = new ListNode(0);
            resultNode->next = head;   
            ListNode* preNode = resultNode;
			ListNode* currentNode = resultNode -> next;
            //2. �ǳƸ�Ƥ��A�Y�`�I��Null�����p�i�H���e����
            if(currentNode == nullptr || currentNode ->next == nullptr)
                return resultNode->next;
            ListNode* nextNode = resultNode->next->next;

            //3. �M���C�Ӹ`�I
			while (currentNode != nullptr && nextNode != nullptr)
            {
                //4-1. ��e�`�I�P�U�@�`�I�Ȥ��ۦP��ܤ��ΧR���A���e����
				if (currentNode->val != nextNode->val)
                {
                    preNode = currentNode;
                    currentNode = currentNode->next;
                    nextNode = currentNode->next;
                }
                else//4-2. �Y��e�`�I�P�U�@�`�I�����ƫh�i��R��
                {
                    while (nextNode != nullptr &&
                        currentNode->val == nextNode->val)
                    {
                        nextNode = nextNode->next;
                    }
                    preNode->next = nextNode == nullptr ? nullptr : nextNode;
                    currentNode = nextNode == nullptr ? nullptr : nextNode;
                    nextNode = nextNode == nullptr ? nullptr : 
                       nextNode -> next == nullptr ? nullptr : nextNode->next;
                }
            }
            return resultNode->next;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Remove_Duplicates_from_Sorted_List_II_Model GetTestData001(void)
        {
            Remove_Duplicates_from_Sorted_List_II_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 1,2,3,3,4,4,5 };
            result.head = ConstructNodes(l1Vectors);
            return result;//expect: [1,2,5]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Remove_Duplicates_from_Sorted_List_II_Model GetTestData002(void)
        {
            Remove_Duplicates_from_Sorted_List_II_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 1,1,1,2,3 };
            result.head = ConstructNodes(l1Vectors);
            return result;//expect:[2,3]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Remove_Duplicates_from_Sorted_List_II_Model GetTestData003(void)
        {
            Remove_Duplicates_from_Sorted_List_II_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 1,1};
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