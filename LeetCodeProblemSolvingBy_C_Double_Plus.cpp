#include "0056.Merge_Intervals.cpp"
using namespace Solution56;
using namespace std;

int main()
{
	Solution56::Merge_Intervals useClass;
	Solution56::Merge_Intervals::Merge_Intervals_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.merge(getTestModel.intervals);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.merge(getTestModel.intervals);
}
