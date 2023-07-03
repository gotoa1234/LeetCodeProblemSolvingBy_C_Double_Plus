#include <unordered_map>
#include "easy/0303.Range_Sum_Query_Immutable.cpp"
using namespace Solution303;

int main()
{
	vector<int> teemp = { -2, 0, 3, -5, 2, -1};
	Solution303::NumArray useClass(teemp);
	auto get = useClass.sumRange(2, 5);
	return 0;
}