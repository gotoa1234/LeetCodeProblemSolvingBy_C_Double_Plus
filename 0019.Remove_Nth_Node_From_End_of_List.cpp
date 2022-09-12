#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution19
{
#pragma region Paste to execute 
	/*
	#include "0019.Remove_Nth_Node_From_End_of_List.cpp"
	using namespace Solution19;
	using namespace std;

	int main()
	{
		Solution19::Remove_Nth_Node_From_End_of_List useClass;
		Solution19::Remove_Nth_Node_From_End_of_List::Remove_Nth_Node_From_End_of_List_Model getTestModel = useClass.GetTestData001();
	    Remove_Nth_Node_From_End_of_List::ListNode* result = useClass.removeNthFromEnd(getTestModel.head, getTestModel.n);

		getTestModel = useClass.GetTestData002();
		result = useClass.removeNthFromEnd(getTestModel.head, getTestModel.n);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 最長共用前綴
	/// </summary>
	class Remove_Nth_Node_From_End_of_List
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
		class Remove_Nth_Node_From_End_of_List_Model
		{
		public:
			ListNode* head;
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：
		///      Runtime : 
		/// Memory Usage : 
		/// </summary>
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			
			ListNode* firstPtr = head;
			ListNode* secondPtr = head;
			int counter = 0;
			while (firstPtr != NULL)
			{
				for (int index = 0; index < n && firstPtr != nullptr; index++)
				{
					firstPtr = firstPtr->next;
					if (firstPtr == nullptr)
					{
						if (counter == 0)
							head = NULL;
						else
						{
							if (counter == n - 1)
								head = head->next;
							else
							    secondPtr->next = secondPtr->next->next;
						}
						break;
					}
					if (counter - n >= 0)
					{
						secondPtr = secondPtr->next;
					}
					counter++;
				}
			}
			
			return head;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Remove_Nth_Node_From_End_of_List_Model GetTestData001(void)
		{
			Remove_Nth_Node_From_End_of_List_Model result;
			vector<int> input = { 1,2,3,4,5 };
			result.head = ConstructNodes(input);
			result.n = 2;
			return result;//except: [1,2,3,5]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Remove_Nth_Node_From_End_of_List_Model GetTestData002(void)
		{
			Remove_Nth_Node_From_End_of_List_Model result;
			vector<int> input = { 1 };
			result.head = ConstructNodes(input);
			result.n = 1;
			return result;//except: []
		};
		/// <summary>
		/// 測試資料3
		/// </summary>   
		Remove_Nth_Node_From_End_of_List_Model GetTestData003(void)
		{
			Remove_Nth_Node_From_End_of_List_Model result;
			vector<int> input = { 1,2 };
			result.head = ConstructNodes(input);
			result.n = 1;
			return result;//except: [1]
		};

		/// <summary>
		/// 測試資料4
		/// </summary>   
		Remove_Nth_Node_From_End_of_List_Model GetTestData004(void)
		{
			Remove_Nth_Node_From_End_of_List_Model result;
			vector<int> input = { 1,2 };
			result.head = ConstructNodes(input);
			result.n = 2;
			return result;//except: [2]
		};

#pragma endregion TestData
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