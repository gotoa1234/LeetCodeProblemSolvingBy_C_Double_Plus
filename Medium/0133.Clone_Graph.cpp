#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution133
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0133.Clone_Graph.cpp"
    using namespace Solution133;

    int main()
    {
        Solution133::Clone_Graph useClass;
        Solution133::Clone_Graph::Clone_Graph_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.cloneGraph(getTestModel.node);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.cloneGraph(getTestModel.node);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.cloneGraph(getTestModel.node);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �J����
    /// </summary>
    class Clone_Graph
    {
    public:
        //Definition for singly-linked list.
        struct Node {
            int val;
            vector<Node*> neighbors;
            Node() {
                val = 0;
                neighbors = vector<Node*>();
            }
            Node(int _val) {
                val = _val;
                neighbors = vector<Node*>();
            }
            Node(int _val, vector<Node*> _neighbors) {
                val = _val;
                neighbors = _neighbors;
            }
        };
#pragma region Model
    public:
        class Clone_Graph_Model
        {
        public:
            Node* node;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         �D�ءG�D�ص��wNode �åB��Node�|���۾F(neighbors)���`�I�A�ؼЬO�ƻs�D�ص���Node��X���c�@�Ҥ@�˪�Node
        ///         ����G�Q�Τ@��HashTable �[�W���j�A�C�ӸI�쪺�`�I�O����HashTable���A�M�Ỽ�j�����F�~�`�I�A�Q�������F�~
        ///               �|�Q�O���bHashTable���A����Ҧ����I���Q����
        ///      Runtime�G   0 ms Beats   100 %
        /// Memory Usage�G 8.7 MB Beats 64.99 %
        /// </summary>
        /// <returns></returns>
        unordered_map<Node*, Node*> _hashTable;
        Node* cloneGraph(Node* node) {
            _hashTable = unordered_map<Node*, Node*>();
            return helper(node);
        }
        Node* helper(Node* node) 
        {
            //1-1. ���X����Ÿ`�I
            if (node == nullptr) 
                return NULL;
            //1-2. �p�G�w�s�b�F�~���A�h���έ��Ʊ����A�i�H����
            else if (_hashTable.count(node))
                return _hashTable[node];
            //2. �إߤ@��Clone�����c (�����c�|���ۤv��Val �P �F�~�`�I)
            Node* clone = new Node(node->val);
            _hashTable[node] = clone;
            //3. ���j�����F�~
            for (Node* neighbor : node->neighbors) 
                clone->neighbors.push_back(helper(neighbor));
            //4. �p�G�o���`�I���F�~�����������A�N���إߪ�Clone���G��^
            return clone;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Clone_Graph_Model GetTestData001(void)
        {
            Clone_Graph_Model result{};
            auto nodeA = new Node(1);
            auto nodeB = new Node(2);
            auto nodeC = new Node(3);
            auto nodeD = new Node(4);
            nodeA->neighbors.push_back(nodeB);
            nodeA->neighbors.push_back(nodeD);

            nodeB->neighbors.push_back(nodeA);
            nodeB->neighbors.push_back(nodeC);

            nodeC->neighbors.push_back(nodeB);
            nodeC->neighbors.push_back(nodeD);

            nodeD->neighbors.push_back(nodeA);
            nodeD->neighbors.push_back(nodeC);                        
            result.node = nodeA;
            return result;//expect: [[2,4],[1,3],[2,4],[1,3]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Clone_Graph_Model GetTestData002(void)
        {
            Clone_Graph_Model result{};
            //adjList = [[]]
            return result;//expect: [[]]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Clone_Graph_Model GetTestData003(void)
        {
            Clone_Graph_Model result{};
            //adjList = []
            return result;//expect: []
        };
#pragma endregion TestData
    };
}