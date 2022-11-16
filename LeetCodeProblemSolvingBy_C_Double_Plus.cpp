
#include "0060.Permutation_Sequence.cpp"
#include <string>
#include <numeric>
using namespace Solution60;
using namespace std;


int main()
{
    int N = 5;
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        v.push_back(i);
    }

    vector<string> temp{};
    while (next_permutation(v.begin(), v.end())) {
        string newItem{};
        for (auto itemChar : v) {
            newItem.push_back(itemChar + '0');
        }        
        temp.push_back(newItem + "\r\n");
    }

    string s = accumulate(temp.begin(), temp.end(), string{});
	Solution60::Permutation_Sequence useClass;
	Solution60::Permutation_Sequence::Permutation_Sequence_Model getTestModel = useClass.GetTestData001();
    auto result4 = useClass.getPermutation(5, 23);
	auto result1 = useClass.getPermutation(getTestModel.n, getTestModel.k);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.getPermutation(getTestModel.n, getTestModel.k);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.getPermutation(getTestModel.n, getTestModel.k);

	
}