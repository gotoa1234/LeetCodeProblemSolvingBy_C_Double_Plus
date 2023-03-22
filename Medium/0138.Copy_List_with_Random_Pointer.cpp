#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution138
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0138.Copy_List_with_Random_Pointer.cpp"
    using namespace Solution138;

    int main()
    {
        Solution138::Copy_List_with_Random_Pointer useClass;
        Solution138::Copy_List_with_Random_Pointer::Copy_List_with_Random_Pointer_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.copyRandomList(getTestModel.head);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.copyRandomList(getTestModel.head);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.copyRandomList(getTestModel.head);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �ϥ��H�����w�ƻs�C��
    /// </summary>
    class Copy_List_with_Random_Pointer
    {
    public:
        //Definition for singly-linked list.
        struct Node {
            int val;
            Node* next;
            Node* random;

            Node(int _val) {
                val = _val;
                next = NULL;
                random = NULL;
            }
        };
#pragma region Model
    public:
        class Copy_List_with_Random_Pointer_Model
        {
        public:
            Node* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Q��HashTable�����qHead�}�l�M���C��Node�P����clone Node����m
        ///                �M��A�qhead�M���C��Node������Clone Node�åB�Nnext �P random�j�_��
        ///      Runtime :    4 ms Beats 91.4 %
        /// Memory Usage : 11.3 MB Beats 31.41 %
        /// </summary>
        /// <returns></returns>
        Node* copyRandomList(Node* head) 
        {            
            //1. �إ�hashTable �åB�O���Ҧ� (��lNode , cloneNode)�����Y
            unordered_map<Node*, Node*> hashMap;
            Node* moveNode = head;
            while (moveNode != NULL) 
            {
                Node* clone = new Node(moveNode->val);
                hashMap[moveNode] = clone;
                moveNode = moveNode->next;
            }
            //2. �q�Y�A�]�@���A��Ҧ���lNode�����Y�j�������clone Node�W
            moveNode = head;
            while (moveNode != NULL) 
            {
                hashMap[moveNode]->next = hashMap[moveNode->next];
                hashMap[moveNode]->random = hashMap[moveNode->random];
                moveNode = moveNode->next;
            }
            //3. �NClone���Y��^�Y�����`�׽ƻs (deep clone)
            return hashMap[head];
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Copy_List_with_Random_Pointer_Model GetTestData001(void)
        {
            Copy_List_with_Random_Pointer_Model result{};
            result.head = new Node(7);
            Node* nodeB = new Node(13);
            Node* nodeC = new Node(11);
            Node* nodeD = new Node(10);
            Node* nodeE = new Node(1);

            result.head->next = nodeB;
            nodeB->next = nodeC;
            nodeC->next = nodeD;
            nodeD->next = nodeE;

            result.head->random = nullptr;
            nodeB->random = result.head;
            nodeC->random = nodeE;
            nodeD->random = nodeC;
            nodeE->random = result.head;
            
            //adjList = [[7,null],[13,0],[11,4],[10,2],[1,0]]
            return result;//expect: [[7,null],[13,0],[11,4],[10,2],[1,0]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Copy_List_with_Random_Pointer_Model GetTestData002(void)
        {
            Copy_List_with_Random_Pointer_Model result{};
            //adjList = [[1,1],[2,1]]
            return result;//expect: [[1,1],[2,1]]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Copy_List_with_Random_Pointer_Model GetTestData003(void)
        {
            Copy_List_with_Random_Pointer_Model result{};
            //adjList = [[3,null],[3,0],[3,null]]
            return result;//expect: [[3,null],[3,0],[3,null]]
        };
#pragma endregion TestData
    };
}