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
    /// 從排序列表中刪除重複項 II
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
        ///         思路 ：利用4個節點進行，1個節點紀錄起始，1個節點紀錄上個位置，2個節點為圈出刪除範圍用        
        ///      Runtime :    7 ms Beats 92.22 %
        /// Memory Usage : 11.2 MB Beats 61.54 %
        /// </summary>
        /// <returns></returns>
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            //1. 準備初始資料
            ListNode* resultNode = new ListNode(0);
            resultNode->next = head;   
            ListNode* preNode = resultNode;
			ListNode* currentNode = resultNode -> next;
            //2. 準備資料中，若節點有Null的情況可以提前結束
            if(currentNode == nullptr || currentNode ->next == nullptr)
                return resultNode->next;
            ListNode* nextNode = resultNode->next->next;

            //3. 遍歷每個節點
			while (currentNode != nullptr && nextNode != nullptr)
            {
                //4-1. 當前節點與下一節點值不相同表示不用刪除，往前移動
				if (currentNode->val != nextNode->val)
                {
                    preNode = currentNode;
                    currentNode = currentNode->next;
                    nextNode = currentNode->next;
                }
                else//4-2. 若當前節點與下一節點有重複則進行刪除
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