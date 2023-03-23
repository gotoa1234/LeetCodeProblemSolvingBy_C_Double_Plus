#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution147
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0147.Insertion_Sort_List.cpp"
    using namespace Solution147;

    int main()
    {
        Solution147::Insertion_Sort_List useClass;
        Solution147::Insertion_Sort_List::Insertion_Sort_List_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.insertionSortList(getTestModel.head);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.insertionSortList(getTestModel.head);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 插入排序列表
    /// </summary>
    class Insertion_Sort_List
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
        class Insertion_Sort_List_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>        
        ///         思路： 空間換時間的做法，把所有東西取出用sort()函式 O(nlogn) ，然後一個個節點建立 
        ///      Runtime：   12 ms Beats 93.47 %
        /// Memory Usage： 10.3 MB Beats 9.40 %
        /// </summary>
        /// <returns></returns>
    public:
        ListNode* insertionSortList(ListNode* head) 
        {   
            vector<int> list{};
            while (head != nullptr)
            {
                list.push_back(head->val);
                head = head->next;
            }
            sort(list.begin(), list.end());
            ListNode* dummy = new ListNode(0);
            ListNode* moveNode = dummy;
            for (auto value : list)
            {
                ListNode* newNode = new ListNode(value);
                moveNode->next = newNode;
                moveNode = moveNode->next;
            }
            return dummy->next;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Insertion_Sort_List_Model GetTestData001(void)
        {
            Insertion_Sort_List_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 4, 2, 1, 3 };
            result.head = ConstructNodes(l1Vectors);
            return result;//expect:  [1,2,3,4]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Insertion_Sort_List_Model GetTestData002(void)
        {
            Insertion_Sort_List_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { -1, 5, 3, 4 , 0 };
            result.head = ConstructNodes(l1Vectors);
            return result;//expect:[-1, 0, 3, 4, 5]
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