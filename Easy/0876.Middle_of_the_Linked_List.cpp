#include <iostream>
#include <vector>
using namespace std;

namespace Solution876
{
#pragma region Paste to execute 
	/*
	#include "0876.Middle_of_the_Linked_List.cpp"
	using namespace Solution876;
	using namespace std;

	Solution876::Middle_of_the_Linked_List useClass;
	Solution876::Middle_of_the_Linked_List::Middle_of_the_Linked_List_Model getTestModel = useClass.GetTestData001();
	Solution876::Middle_of_the_Linked_List::ListNode* result = useClass.middleNode(getTestModel.head);

	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 找出鏈結串鍊中的中位數
	/// </summary>
	class Middle_of_the_Linked_List
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
		class Middle_of_the_Linked_List_Model
		{
		public:
			ListNode* head;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路 ： 2個節點，一個走1步 ，另一個走2步，走2步的節點到終點時，走1的節點必定是中位節點
		///      Runtime : 0 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
		/// Memory Usage : 7.1 MB, less than 72.34 % of C++ online submissions for Middle of the Linked List.

		ListNode* middleNode(ListNode* head) {
			if (head == NULL)
				return head;

			ListNode* oneStepNode = head;
			ListNode* twoStepNode = head;
			while (twoStepNode->next != NULL)
			{
				oneStepNode = oneStepNode->next;
				twoStepNode = twoStepNode->next->next != NULL ? twoStepNode->next->next : twoStepNode->next;
			}
			return oneStepNode;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Middle_of_the_Linked_List_Model GetTestData001(void)
		{
			Middle_of_the_Linked_List_Model result;
			vector<int> l1Vectors = { 1,2,3,4,5 };
			result.head = ConstructNodes(l1Vectors);
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Middle_of_the_Linked_List_Model GetTestData002(void)
		{
			Middle_of_the_Linked_List_Model result;
			vector<int> l1Vectors = { 1,2,3,4,5,6 };
			result.head = ConstructNodes(l1Vectors);
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