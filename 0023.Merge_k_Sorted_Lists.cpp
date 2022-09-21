#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

namespace Solution23
{
#pragma region Paste to execute 
	/*
	#include "0023.Merge_k_Sorted_Lists.cpp"
	using namespace Solution23;
	using namespace std;

	int main()
	{
		Solution23::Merge_k_Sorted_Lists useClass;
		Solution23::Merge_k_Sorted_Lists::Merge_k_Sorted_Lists_Model getTestModel = useClass.GetTestData001();
		Solution23::Merge_k_Sorted_Lists::ListNode* result = useClass.mergeKLists(getTestModel.head);

		getTestModel = useClass.GetTestData002();
		result = useClass.mergeKLists(getTestModel.head);

		getTestModel = useClass.GetTestData003();
		result = useClass.mergeKLists(getTestModel.head);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 成對交換節點
	/// </summary>
	class Merge_k_Sorted_Lists
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
		class Merge_k_Sorted_Lists_Model
		{
		public:
			vector<ListNode*> head;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路：利用heap-min 最小堆積的 priority_queue 排序所有項目的鍊 -> 接著遍歷priority_queue 每次取出最小的鍊的節點 ->
		///               然後再依序取出組成一維節點  -> 輸出
		///      Runtime :   24 ms, faster than 92.87% of C++ online submissions for Merge k Sorted Lists.
		/// Memory Usage : 13.2 MB,   less than 83.50% of C++ online submissions for Merge k Sorted Lists.
		/// </summary>
		ListNode* mergeKLists(vector<ListNode*>& lists)
		{
			//1. 自定義比較
			auto cmp = [](ListNode*& nodeA, ListNode*& nodeB)
			{
				//節點A 大於B 時為
				return nodeA->val > nodeB->val;
			};

			//2. 使用優先權 queue 做
			priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeapQueue(cmp);
			for (auto node : lists)
			{
				if (node) //鍊不可為Null，需要帶有值的Node
				{
					//每次都會將 node 與 現在的節點做排序，將第一個最小值的鍊放在最前面
					minHeapQueue.push(node);
				}
			}

			//3. 把 min heap 的結果依序取出，組成新的一維節點
			ListNode* headNode = new ListNode(-1);
			ListNode* moveNode = headNode;
			while (!minHeapQueue.empty())
			{
				auto getTopNode = minHeapQueue.top();
				minHeapQueue.pop();
				//每次取出1個最小的val節點
				moveNode->next = getTopNode;
				moveNode = moveNode->next;
				if (moveNode->next)
				{
					//push時會將最小val的鍊放在[0]位置
					minHeapQueue.push(moveNode->next);
				}
			}
			return headNode->next;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Merge_k_Sorted_Lists_Model GetTestData001(void)
		{
			Merge_k_Sorted_Lists_Model result;
			//[[1, 4, 5], [1, 3, 4], [2, 6]]
			vector<ListNode*> input;
			vector<int> temp = { 1, 4, 5 };
			input.push_back(ConstructNodes(temp));
			temp = { 1, 3, 4 };
			input.push_back(ConstructNodes(temp));
			temp = { 2,6 };
			input.push_back(ConstructNodes(temp));
			result.head = input;
			return result;//except: [1,1,2,3,4,4,5,6]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Merge_k_Sorted_Lists_Model GetTestData002(void)
		{
			Merge_k_Sorted_Lists_Model result;
			vector<ListNode*> input;
			result.head = input;
			return result;//expect:[]
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Merge_k_Sorted_Lists_Model GetTestData003(void)
		{
			Merge_k_Sorted_Lists_Model result;
			vector<ListNode*> input;
			vector<int> temp = {};
			input.push_back(ConstructNodes(temp));
			result.head = input;
			return result;//[]
		};
#pragma endregion TestData
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
	};
}