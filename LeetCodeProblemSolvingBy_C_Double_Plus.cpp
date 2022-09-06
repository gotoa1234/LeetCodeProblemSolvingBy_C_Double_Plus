#include <vector>
#include "0692.Top_K_Frequent_Words.cpp"
using namespace Solution692;

int main()
{

    Solution692::Top_K_Frequent_Words useClass;
    Solution692::Top_K_Frequent_Words::Top_K_Frequent_Words_Model getTestModel = useClass.GetTestData001();
    vector<string> result = useClass.topKFrequent(getTestModel.words, getTestModel.k);

    getTestModel = useClass.GetTestData002();
    result = useClass.topKFrequent(getTestModel.words, getTestModel.k);
    return 0;
}