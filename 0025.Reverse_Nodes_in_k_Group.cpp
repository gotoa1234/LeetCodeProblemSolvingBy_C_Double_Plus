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
		///         思路：利用遞迴，每次判斷是否可取出K個，若是則進行該串列逆向排列，否則就不排序。
		///      Runtime:     4 ms, faster than 99.96% of C++ online submissions for Reverse Nodes in k-Group.
		/// Memory Usage : 11.4 MB,   less than 71.97% of C++ online submissions for Reverse Nodes in k - Group.
		/// </summary>
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {

			//1. 如果到終點
			if (head == nullptr)
				return head;

			//2. 每次檢核是否足夠組成k個串列，如果不夠則視為到終點
			ListNode* check = head;
			for (int index = 0; index < k; index++)
			{
				if (check == NULL)
					return head;
				check = check->next;
			}

			//3. 遞迴處理，將該組(k個)節點做倒序，並且記錄該串列的 Head的next 設為下個組的返還結果
			ListNode* combindNodes = NULL;//組成的結果
			ListNode* nextHeadNode = NULL;//下一個預期的Head
			ListNode* moveNode = head;//位移用
			for (int index = 0; index < k && moveNode; index++)
			{
				nextHeadNode = moveNode->next;
				moveNode->next = combindNodes;
				combindNodes = moveNode;
				moveNode = nextHeadNode;
			}
			head->next = reverseKGroup(nextHeadNode, k);
			return combindNodes;
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
			vector<int> input = { 1,2,3,4,5,6,7 };
			result.head = ConstructNodes(input);
			result.k = 3;
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