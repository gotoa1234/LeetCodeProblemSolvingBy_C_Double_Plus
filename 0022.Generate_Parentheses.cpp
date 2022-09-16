#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution23
{
#pragma region Paste to execute 
	/*
	#include "0023.Merge_k_Sorted_Lists"
	using namespace Solution23;
	using namespace std;

	int main()
	{
		Solution23::Merge_k_Sorted_Lists useClass;
		Solution23::Merge_k_Sorted_Lists::Merge_k_Sorted_Lists_Model getTestModel = useClass.GetTestData001();
		Solution23::Merge_k_Sorted_Lists::ListNode* result = useClass.swapPairs(getTestModel.head);

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
		///         思路：
		///      Runtime:  
		/// Memory Usage : 
		/// </summary>
		ListNode* swapPairs(ListNode* head) {
			return nullptr;
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