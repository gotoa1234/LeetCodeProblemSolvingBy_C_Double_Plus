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
    /// 重排節點
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
        ///         思路： 找出鏈節中間點的位置，前半段頭 + 後半段尾逐一串接起來
        ///                第一解法：雙指標，1個走1步，另1個走2步，可以找出中間點，與末節點，然後組成
        ///                第二解法：利用另一個O(n)的空間，存放資料，然後取中間值(此時也可知到末節點)，然後組成
        ///      Runtime：   30 ms Beats 99.50 %
        /// Memory Usage： 18.4 MB Beats 33.92 %

        ///第二解法，但缺點是空間跑分很差，但代碼簡潔易懂
        void reorderList(ListNode* head) {
            //1. 可跳出條件
            if (head->next == nullptr || 
                head->next->next == nullptr)
                return;            
            stack<ListNode*> stackTemp;
            ListNode* moveNode = head;
            //2. 將所有Node 放入Stack中
            while (moveNode) 
            {
                stackTemp.push(moveNode);
                moveNode = moveNode->next;
            }
            moveNode = head;
            //3. 得到中間值，只需進行中間值次數的更換->next指向節點
            //ex: 1->2->3->4->5  middleCount = 2 
            //    1->5->2  是1次 
            //    1->5->2->4->3 是2次
            for (int middleCount = ((int)stackTemp.size() - 1) / 2; middleCount > 0; middleCount--)
            {
                //4-1. 取得最後一個節點
                ListNode* getNode = stackTemp.top(); 
                stackTemp.pop();
                //4-2. 下一節點先記錄
                ListNode* next = moveNode->next;
                //4-3. 轉換指向
                moveNode->next = getNode;
                getNode->next = next;
                moveNode = next;
            }
            //5. 最後將節點設為null否則遞迴
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