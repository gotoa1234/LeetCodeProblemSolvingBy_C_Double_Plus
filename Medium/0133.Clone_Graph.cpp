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
    /// §J¶©¹Ï
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
        ///         «ä¸ô ¡G
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
        Node* cloneGraph(Node* node) {
            return{};
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
            Clone_Graph_Model result;
            result.node = new Node();
            //adjList = [[2,4],[1,3],[2,4],[1,3]]
            return result;//expect: [[2,4],[1,3],[2,4],[1,3]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Clone_Graph_Model GetTestData002(void)
        {
            Clone_Graph_Model result;
            //adjList = [[]]
            return result;//expect: [[]]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Clone_Graph_Model GetTestData003(void)
        {
            Clone_Graph_Model result;
            //adjList = []
            return result;//expect: []
        };
#pragma endregion TestData
    };
}