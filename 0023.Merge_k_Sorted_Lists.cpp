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
	/// ����洫�`�I
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
		///         ����G�Q��heap-min �̤p��n�� priority_queue �ƧǩҦ����ت��� -> ���۹M��priority_queue �C�����X�̤p���媺�`�I ->
		///               �M��A�̧Ǩ��X�զ��@���`�I  -> ��X
		///      Runtime :   24 ms, faster than 92.87% of C++ online submissions for Merge k Sorted Lists.
		/// Memory Usage : 13.2 MB,   less than 83.50% of C++ online submissions for Merge k Sorted Lists.
		/// </summary>
		ListNode* mergeKLists(vector<ListNode*>& lists)
		{
			//1. �۩w�q���
			auto cmp = [](ListNode*& nodeA, ListNode*& nodeB)
			{
				//�`�IA �j��B �ɬ�
				return nodeA->val > nodeB->val;
			};

			//2. �ϥ��u���v queue ��
			priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeapQueue(cmp);
			for (auto node : lists)
			{
				if (node) //�夣�i��Null�A�ݭn�a���Ȫ�Node
				{
					//�C�����|�N node �P �{�b���`�I���ƧǡA�N�Ĥ@�ӳ̤p�Ȫ����b�̫e��
					minHeapQueue.push(node);
				}
			}

			//3. �� min heap �����G�̧Ǩ��X�A�զ��s���@���`�I
			ListNode* headNode = new ListNode(-1);
			ListNode* moveNode = headNode;
			while (!minHeapQueue.empty())
			{
				auto getTopNode = minHeapQueue.top();
				minHeapQueue.pop();
				//�C�����X1�ӳ̤p��val�`�I
				moveNode->next = getTopNode;
				moveNode = moveNode->next;
				if (moveNode->next)
				{
					//push�ɷ|�N�̤pval�����b[0]��m
					minHeapQueue.push(moveNode->next);
				}
			}
			return headNode->next;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
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
		/// ���ո��2
		/// </summary>   
		Merge_k_Sorted_Lists_Model GetTestData002(void)
		{
			Merge_k_Sorted_Lists_Model result;
			vector<ListNode*> input;
			result.head = input;
			return result;//expect:[]
		};

		/// <summary>
		/// ���ո��3
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