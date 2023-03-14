#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

namespace Solution143
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0143.Reorder_List.cpp"
    using namespace Solution143;
    using namespace std;
    
    int main()
    {
        Solution143::Reorder_List useClass;
        Solution143::Reorder_List::Reorder_List_Model getTestModel = useClass.GetTestData001();
        useClass.reorderList(getTestModel.head);
    
        getTestModel = useClass.GetTestData002();
        useClass.reorderList(getTestModel.head);
    
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// ���Ƹ`�I
    /// </summary>
    class Reorder_List
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
        class Reorder_List_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ����G ��X��`�����I����m�A�e�b�q�Y + ��b�q���v�@�걵�_��
        ///                �Ĥ@�Ѫk�G�����СA1�Ө�1�B�A�t1�Ө�2�B�A�i�H��X�����I�A�P���`�I�A�M��զ�
        ///                �ĤG�Ѫk�G�Q�Υt�@��O(n)���Ŷ��A�s���ơA�M���������(���ɤ]�i���쥽�`�I)�A�M��զ�
        ///      Runtime�G   30 ms Beats 99.50 %
        /// Memory Usage�G 18.4 MB Beats 33.92 %

        ///�ĤG�Ѫk�A�����I�O�Ŷ��]���ܮt�A���N�X²�����
        void reorderList(ListNode* head) {
            //1. �i���X����
            if (head->next == nullptr || 
                head->next->next == nullptr)
                return;            
            stack<ListNode*> stackTemp;
            ListNode* moveNode = head;
            //2. �N�Ҧ�Node ��JStack��
            while (moveNode) 
            {
                stackTemp.push(moveNode);
                moveNode = moveNode->next;
            }
            moveNode = head;
            //3. �o�줤���ȡA�u�ݶi�椤���Ȧ��ƪ���->next���V�`�I
            //ex: 1->2->3->4->5  middleCount = 2 
            //    1->5->2  �O1�� 
            //    1->5->2->4->3 �O2��
            for (int middleCount = ((int)stackTemp.size() - 1) / 2; middleCount > 0; middleCount--)
            {
                //4-1. ���o�̫�@�Ӹ`�I
                ListNode* getNode = stackTemp.top(); 
                stackTemp.pop();
                //4-2. �U�@�`�I���O��
                ListNode* next = moveNode->next;
                //4-3. �ഫ���V
                moveNode->next = getNode;
                getNode->next = next;
                moveNode = next;
            }
            //5. �̫�N�`�I�]��null�_�h���j
            stackTemp.top()->next = nullptr;
        }

#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Reorder_List_Model GetTestData001(void)
        {
            Reorder_List_Model result;
            vector<int> l1Vectors = { 1, 2, 3, 4};
            result.head = ConstructNodes(l1Vectors);
            return result;//expect:: [1, 4, 2, 3]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Reorder_List_Model GetTestData002(void)
        {
            Reorder_List_Model result;
			vector<int> l1Vectors = { 1, 2 ,3,4,5 };
            result.head = ConstructNodes(l1Vectors);            
            return result;//expect: [1, 5, 2, 4, 3]
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