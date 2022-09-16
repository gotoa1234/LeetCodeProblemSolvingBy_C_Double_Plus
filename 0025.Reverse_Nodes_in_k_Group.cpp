#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution25
{
#pragma region Paste to execute 
	/*
	#include "0025.Reverse_Nodes_in_k_Group.cpp"
	using namespace Solution25;
	using namespace std;

	int main()
	{
		Solution25::Reverse_Nodes_in_k_Group useClass;
		Solution25::Reverse_Nodes_in_k_Group::Reverse_Nodes_in_k_Group_Model getTestModel = useClass.GetTestData001();
		Solution25::Reverse_Nodes_in_k_Group::ListNode* result = useClass.reverseKGroup(getTestModel.head, getTestModel.k);

		getTestModel = useClass.GetTestData002();
		result = useClass.reverseKGroup(getTestModel.head, getTestModel.k);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// k-Group 中的反向節點
	/// </summary>
	class Reverse_Nodes_in_k_Group
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
		class Reverse_Nodes_in_k_Group_Model
		{
		public:
			ListNode* head;
			int k;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///         思路：
		///      Runtime:  
		/// Memory Usage : 
		/// </summary>
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			return nullptr;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Reverse_Nodes_in_k_Group_Model GetTestData001(void)
		{
			Reverse_Nodes_in_k_Group_Model result;
			vector<int> input = { 1,1,2 };
			result.head = ConstructNodes(input);
			result.k = 2;
			return result;//except: [2, 1, 4, 3, 5]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Reverse_Nodes_in_k_Group_Model GetTestData002(void)
		{
			Reverse_Nodes_in_k_Group_Model result;
			vector<int> input = { 1, 2, 3, 4, 5 };
			result.head = ConstructNodes(input);
			result.k = 3;
			return result;//expect:[3, 2, 1, 4, 5]
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