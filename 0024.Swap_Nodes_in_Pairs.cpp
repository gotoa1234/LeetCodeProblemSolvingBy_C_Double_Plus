#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution24
{
#pragma region Paste to execute 
	/*
	#include "0024.Swap_Nodes_in_Pairs.cpp"
	using namespace Solution24;
	using namespace std;

	int main()
	{
		Solution24::Swap_Nodes_in_Pairs useClass;
		Solution24::Swap_Nodes_in_Pairs::Swap_Nodes_in_Pairs_Model getTestModel = useClass.GetTestData001();
	    Solution24::Swap_Nodes_in_Pairs::ListNode* result = useClass.swapPairs(getTestModel.head);

		getTestModel = useClass.GetTestData002();
		result = useClass.swapPairs(getTestModel.head);

		getTestModel = useClass.GetTestData003();
		result = useClass.swapPairs(getTestModel.head);
		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 成對交換節點
	/// </summary>
	class Swap_Nodes_in_Pairs
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
		class Swap_Nodes_in_Pairs_Model
		{
		public:
			ListNode* head;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路：依照規律，兩兩一對，可以利用遞迴/迴圈的方式，將本次配對的指向節點決定是下一對的哪一個
		///      Runtime:   3 ms, faster than 75.62% of C++ online submissions for Swap Nodes in Pairs.
		///Memory Usage : 7.4 MB,   less than 99.68% of C++ online submissions for Swap Nodes in Pairs.
		/// </summary>
		/*
		input: 1 -> 2 -> 3 -> 4 
		  out: 2 -> 1 -> 4 -> 3
		*/
		ListNode* swapPairs(ListNode* head) {

			//1. 排除沒有元素、1個元素的狀況
			if (head == nullptr || head->next == nullptr)
			{
				return head;
			}
			ListNode* result = new ListNode(-1);
			//2. 進入遞迴取結果
			result->next = swapPairsSubMethod(head);
			return result->next;
		}
		
		ListNode* swapPairsSubMethod(ListNode* currentHeadNode)
		{
			//3. 如果當前的頭節點為null，可直接回傳
			if (currentHeadNode == nullptr)
				return nullptr;

			//4. 紀錄本次配對的節點 A、B
			ListNode* tmpNextHead = nullptr;
			ListNode* nodeA = currentHeadNode;
			ListNode* nodeB = currentHeadNode->next;
			//5. B節點為null 必定回傳A節點(前節點)
			if (nodeB == nullptr)
				return nodeA;	

			//6. 替換
		    tmpNextHead = nodeB->next;
			nodeB->next = nodeA;
			nodeA->next = swapPairsSubMethod(tmpNextHead);
			//7. 如果配對完整必定是回傳B節點(後節點)
			return nodeB;
		}


		/// <summary>
		/// 最佳解-精簡的遞迴
		/// </summary>
		ListNode* swapPairs(ListNode* head)
		{
			if (head == NULL || head->next == NULL) {
				return head;
			}
			ListNode* moveNode = head->next;
			head->next = swapPairs(head->next->next);
			moveNode->next = head;
			return moveNode;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Swap_Nodes_in_Pairs_Model GetTestData001(void)
		{
			Swap_Nodes_in_Pairs_Model result;
			vector<int> input = { 1,2,3,4 };
			result.head = ConstructNodes(input);
			return result;//except: [2,1,4,3]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Swap_Nodes_in_Pairs_Model GetTestData002(void)
		{
			Swap_Nodes_in_Pairs_Model result;
			vector<int> input = {};
			result.head = nullptr;
			return result;//expect:[]
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Swap_Nodes_in_Pairs_Model GetTestData003(void)
		{
			Swap_Nodes_in_Pairs_Model result;
			vector<int> input = { 1 };
			result.head = ConstructNodes(input);
			return result;//[1]
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