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
    	auto result1 = useClass.rotateRight(getTestModel.head, getTestModel.k);
    
    	getTestModel = useClass.GetTestData002();
    	auto result2 = useClass.rotateRight(getTestModel.head, getTestModel.k);
    
    	getTestModel = useClass.GetTestData003();
    	auto result3 = useClass.rotateRight(getTestModel.head, getTestModel.k);
    
    	getTestModel = useClass.GetTestData004();
    	auto result4 = useClass.rotateRight(getTestModel.head, getTestModel.k);
    
    	getTestModel = useClass.GetTestData005();
    	auto result5 = useClass.rotateRight(getTestModel.head, getTestModel.k);
    	return 0;
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �������
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
		///         ����G��X�V�k���ʪ��W�h
		///               1. �M����X�����`����X �A�i�H�o�� k % X �|�O�u���m�A�ðO�����ڸ`�I
		///               2. �A�Q���`���� X - (k % X) �N�|�O�_�INode
		///               3. �N���ڸ`�I ���V�� �Y�`�I�A�åB�A���� X - (k % X) ��_�I (��������)
		///               Time : O(n)
		///      Runtime:    3 ms Beats 99.48 %
		/// Memory Usage :11.7 MB Beats 55.34 %
		/// </summary>
	public:
		ListNode* rotateRight(ListNode* head, int k) {
            ListNode* fakeNode = head;
			ListNode* moveNode = head;
			ListNode* endNode = head;

			//1. ��X�`���B�̫�@�Ӹ`�I
			int maxLength = 0;
			while (moveNode)
			{
				endNode = moveNode;
				moveNode = moveNode->next;
				maxLength++;
			}
			
			//2. �ư����I/���έp�⪺����
			if (k == 0 || head == nullptr || k % maxLength == 0)
				return head;

			//3. �N�����V�Y�A�ç�X�s���Y
			ListNode* targetNode = head;
			ListNode* leastTargetNode = head;
			for (int moveStep = maxLength - (k % maxLength);
				moveStep > 0;
				moveStep--)
			{
				leastTargetNode = targetNode;
				targetNode = targetNode->next;
			}
			leastTargetNode->next = nullptr;
			endNode->next = head;
			return targetNode;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
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
		/// ���ո��2
		/// </summary>   
		Rotate_List_Model GetTestData002(void)
		{
			Rotate_List_Model result;
			vector<int> input = { 0,1,2 };
			result.head = ConstructNodes(input);
			result.k = 4;
			return result;//expect:[2,0,1] 
		};

		Rotate_List_Model GetTestData003(void)
		{
			Rotate_List_Model result;
			vector<int> input = { 1,2,3,4,5 };
			result.head = ConstructNodes(input);
			result.k = 4;
			return result;//expect:[2,3,4,5,1]
		};

		Rotate_List_Model GetTestData004(void)
		{
			Rotate_List_Model result;
			vector<int> input = {  };
			result.head = ConstructNodes(input);
			result.k = 0;
			return result;//expect:[]
		};

		Rotate_List_Model GetTestData005(void)
		{
			Rotate_List_Model result;
			vector<int> input = {  };
			result.head = ConstructNodes(input);
			result.k = 1;
			return result;//expect:[]
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