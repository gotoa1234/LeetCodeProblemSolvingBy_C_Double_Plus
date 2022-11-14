#include "0057.Insert_Interval.cpp"
using namespace Solution57;
using namespace std;

int main()
{
	Solution57::Insert_Interval useClass;
	Solution57::Insert_Interval::Insert_Interval_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.insert(getTestModel.intervals, getTestModel.newInterval);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.insert(getTestModel.intervals, getTestModel.newInterval);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.insert(getTestModel.intervals, getTestModel.newInterval);

	getTestModel = useClass.GetTestData004();
	auto result4 = useClass.insert(getTestModel.intervals, getTestModel.newInterval);
}