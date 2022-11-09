#include "0053.Maximum_Subarray.cpp"
using namespace Solution53;
using namespace std;

int main()
{

	Solution53::Maximum_Subarray useClass;
	Solution53::Maximum_Subarray::Maximum_Subarray_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.maxSubArray(getTestModel.nums);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.maxSubArray(getTestModel.nums);
	return 0;
}