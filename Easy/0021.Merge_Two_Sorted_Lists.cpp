#include <iostream>
#include <vector>
using namespace std;

namespace Solution21
{
#pragma region Paste to execute 
    /*
    #include "021.Merge_Two_Sorted_Lists.cpp"
    using namespace Solution21;
    using namespace std;

    Solution21::Merge_Two_Sorted_Lists useClass;
    Solution21::Merge_Two_Sorted_Lists::Merge_Two_Sorted_Lists_Model getTestModel = useClass.GetTestData001();
    Solution21::Merge_Two_Sorted_Lists::ListNode* result = useClass.mergeTwoLists(getTestModel.list1, getTestModel.list2);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 合併兩個已排序的鏈結串鍊，由小到大
    /// </summary>
    class Merge_Two_Sorted_Lists
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
        class Merge_Two_Sorted_Lists_Model
        {
        public:
            ListNode* list1;
            ListNode* list2;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ： 預處理(可省略) => 將2個NodeList組成1個
        ///      Runtime :    8 ms, faster than 80.99% of C++ online submissions for Merge Two Sorted Lists.
        /// Memory Usage : 14.7 MB,   less than 97.86% of C++ online submissions for Merge Two Sorted Lists.

        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            //預處理
            if (list1 == NULL)
            {
                return list2;
            }
            if (list2 == NULL)
            {
                return list1;
            }
            
            ListNode* resultHead;
            ListNode* moveNode = new ListNode;
            resultHead = moveNode;
            //將2個NodeList組成1個
            while (list1 && list2)
            {
                if (list1->val <= list2->val)
                {
					moveNode->next = list1;
                    moveNode = moveNode->next;
					list1 = list1->next;
                }
                else
                {
                    moveNode->next = list2;
                    moveNode = moveNode->next;
                    list2 = list2->next;
                }
            }

            moveNode->next = list1 == NULL ? list2 : list1;
            return resultHead->next;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Merge_Two_Sorted_Lists_Model GetTestData001(void)
        {
            Merge_Two_Sorted_Lists_Model result;
            vector<int> l1Vectors = { 1, 2, 4 };
            vector<int> l2Vectors = { 1, 3, 4 };
            result.list1 = ConstructNodes(l1Vectors);
            result.list2 = ConstructNodes(l2Vectors);
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Merge_Two_Sorted_Lists_Model GetTestData002(void)
        {
            Merge_Two_Sorted_Lists_Model result;
            vector<int> l1Vectors{};
            vector<int> l2Vectors = { 0 };
            result.list1 = ConstructNodes(l1Vectors);
            result.list2 = ConstructNodes(l2Vectors);
            return result;
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Merge_Two_Sorted_Lists_Model GetTestData003(void)
        {
            Merge_Two_Sorted_Lists_Model result;
            vector<int> l1Vectors{ };
            vector<int> l2Vectors{ };
            result.list1 = ConstructNodes(l1Vectors);
            result.list2 = ConstructNodes(l2Vectors);
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