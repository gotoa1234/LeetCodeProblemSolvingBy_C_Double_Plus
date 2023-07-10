#include "Easy/0228.Summary_Ranges.cpp"
using namespace Solution228;
using namespace std;

int main()
{
	Solution228::Summary_Ranges useClass;
	Solution228::Summary_Ranges::Summary_Ranges_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.summaryRanges(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.summaryRanges(getTestModel.nums);
}


