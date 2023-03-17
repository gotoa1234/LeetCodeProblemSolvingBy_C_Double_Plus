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