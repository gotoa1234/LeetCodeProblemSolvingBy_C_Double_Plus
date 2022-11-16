#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution61
{
#pragma region Paste to execute 
	/*
	#include "0061.Rotate_List.cpp"
	using namespace Solution61;
	using namespace std;

	int main()
	{
		Solution61::Rotate_List useClass;
		Solution61::Rotate_List::Rotate_List_Model getTestModel = useClass.GetTestData001();
		Solution61::Rotate_List::ListNode* result = useClass.reverseKGroup(getTestModel.head, getTestModel.k);

		getTestModel = useClass.GetTestData002();
		result = useClass.reverseKGroup(getTestModel.head, getTestModel.k);

		return 0;
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// k-Group 中的反向節點
	/// </summary>
	class Rotate_List
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
		class Rotate_List_Model
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
		ListNode* rotateRight(ListNode* head, int k) {
			return { };
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Rotate_List_Model GetTestData001(void)
		{
			Rotate_List_Model result;
			vector<int> input = { 1,2,3,4,5 };
			result.head = ConstructNodes(input);
			result.k = 2;
			return result;//except: [4,5,1,2,3]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Rotate_List_Model GetTestData002(void)
		{
			Rotate_List_Model result;
			vector<int> input = { 0,1,2 };
			result.head = ConstructNodes(input);
			result.k = 4;
			return result;//expect:[2,0,1] 
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