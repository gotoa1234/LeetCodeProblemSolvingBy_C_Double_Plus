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
	/// k-Group �����ϦV�`�I
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
		///         ����G�Q�λ��j�A�C���P�_�O�_�i���XK�ӡA�Y�O�h�i��Ӧ�C�f�V�ƦC�A�_�h�N���ƧǡC
		///      Runtime:     4 ms, faster than 99.96% of C++ online submissions for Reverse Nodes in k-Group.
		/// Memory Usage : 11.4 MB,   less than 71.97% of C++ online submissions for Reverse Nodes in k - Group.
		/// </summary>
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {

			//1. �p�G����I
			if (head == nullptr)
				return head;

			//2. �C���ˮ֬O�_�����զ�k�Ӧ�C�A�p�G�����h��������I
			ListNode* check = head;
			for (int index = 0; index < k; index++)
			{
				if (check == NULL)
					return head;
				check = check->next;
			}

			//3. ���j�B�z�A�N�Ӳ�(k��)�`�I���˧ǡA�åB�O���Ӧ�C�� Head��next �]���U�Ӳժ����ٵ��G
			ListNode* combindNodes = NULL;//�զ������G
			ListNode* nextHeadNode = NULL;//�U�@�ӹw����Head
			ListNode* moveNode = head;//�첾��
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
		/// ���ո��1
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
		/// ���ո��2
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