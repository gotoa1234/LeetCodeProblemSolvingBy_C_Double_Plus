#include <vector>
#include "0692.Top_K_Frequent_Words.cpp"
using namespace Solution692;

bool comp(int a, int b)
{
    return (a < b);
}
int main()
{
    int v[] = { 3, 2, 10, 45, 33, 56, 23, 47 };
    nth_element(v, v + 5, v + 8, comp);
    for (int i = 0; i < 8; ++i) {
        cout << v[i] << " ";
    }
    return 0;

    Solution692::Top_K_Frequent_Words useClass;
    Solution692::Top_K_Frequent_Words::Top_K_Frequent_Words_Model getTestModel = useClass.GetTestData001();
    vector<string> result = useClass.topKFrequent(getTestModel.words, getTestModel.k);

    getTestModel = useClass.GetTestData002();
    result = useClass.topKFrequent(getTestModel.words, getTestModel.k);
    return 0;
}