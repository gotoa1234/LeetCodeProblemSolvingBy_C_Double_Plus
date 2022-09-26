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
	/// ����洫�`�I
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
		///         ����G�̷ӳW�ߡA���@��A�i�H�Q�λ��j/�j�骺�覡�A�N�����t�諸���V�`�I�M�w�O�U�@�諸���@��
		///      Runtime:   3 ms, faster than 75.62% of C++ online submissions for Swap Nodes in Pairs.
		///Memory Usage : 7.4 MB,   less than 99.68% of C++ online submissions for Swap Nodes in Pairs.
		/// </summary>
		/*
		input: 1 -> 2 -> 3 -> 4 
		  out: 2 -> 1 -> 4 -> 3
		*/
		ListNode* swapPairs(ListNode* head) {

			//1. �ư��S�������B1�Ӥ��������p
			if (head == nullptr || head->next == nullptr)
			{
				return head;
			}
			ListNode* result = new ListNode(-1);
			//2. �i�J���j�����G
			result->next = swapPairsSubMethod(head);
			return result->next;
		}
		
		ListNode* swapPairsSubMethod(ListNode* currentHeadNode)
		{
			//3. �p�G��e���Y�`�I��null�A�i�����^��
			if (currentHeadNode == nullptr)
				return nullptr;

			//4. ���������t�諸�`�I A�BB
			ListNode* tmpNextHead = nullptr;
			ListNode* nodeA = currentHeadNode;
			ListNode* nodeB = currentHeadNode->next;
			//5. B�`�I��null ���w�^��A�`�I(�e�`�I)
			if (nodeB == nullptr)
				return nodeA;	

			//6. ����
		    tmpNextHead = nodeB->next;
			nodeB->next = nodeA;
			nodeA->next = swapPairsSubMethod(tmpNextHead);
			//7. �p�G�t�粒�㥲�w�O�^��B�`�I(��`�I)
			return nodeB;
		}


		/// <summary>
		/// �̨θ�-��²�����j
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
		/// ���ո��1
		/// </summary>        
		Swap_Nodes_in_Pairs_Model GetTestData001(void)
		{
			Swap_Nodes_in_Pairs_Model result;
			vector<int> input = { 1,2,3,4 };
			result.head = ConstructNodes(input);
			return result;//except: [2,1,4,3]
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Swap_Nodes_in_Pairs_Model GetTestData002(void)
		{
			Swap_Nodes_in_Pairs_Model result;
			vector<int> input = {};
			result.head = nullptr;
			return result;//expect:[]
		};

		/// <summary>
		/// ���ո��3
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