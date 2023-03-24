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
    /// 排序列表
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
        ///     題目要求： Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
        ///         思路： 不可用147 題上的作法，無法達到 Space : O(1) ，這題需要利用合併排序法，利用快慢指針切割出中間
        ///                讓節點切割至單個節點，然後不斷Merge出排序的結果
        ///         舉例： 假定[4,2,1,3]
        ///                STEP 1：       [4, 2, 1, 3]            (切割)
        ///                STEP 2：    [4, 2]  +  [1,3]           (切割)
        ///                STEP 3： [4] + [2]  與  [1] + [3]      (切割)
        ///                STEP 4：    [2, 4]  +  [1,3]           (合併)
        ///                STEP 5：    [1] [2, 4, 4]              (合併)
        ///                STEP 6：    [1] [2, 4, 3]              (合併)
        ///                STEP 7：    [1, 2] [4, 3]              (合併)
        ///                STEP 8：    [1, 2, 3] [4]              (合併)
        ///                STEP 9：    [1, 2, 3, 4]               (完成)
        ///      Runtime：  196 ms Beats 77.77
        /// Memory Usage： 53.2 MB Beats 77.60
        /// </summary>
        /// <returns></returns>
    public:
        ListNode* sortList(ListNode* head) 
        {
            //1. 跳出條件
            if (!head || !head->next) 
                return head;
            //2-1. 利用三個Node 做出快慢指針
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
            //2-2. 這將會把將整個串鍊切成 1/2 
            moveNode->next = NULL;
            //3. 將左半邊的節點們與右半版的節點門持續分割，最後合併
            return merge(sortList(head), sortList(slowNode));
        }

        ListNode* merge(ListNode* leftEdgeNode, ListNode* rightEdgeNode) 
        {
            //4-1. 跳出條件
            if (leftEdgeNode == nullptr) 
                return rightEdgeNode;
            if (rightEdgeNode == nullptr) 
                return leftEdgeNode;

            //4-2. 將節點間進行合併排序
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