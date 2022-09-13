#include "0016.3Sum_Closet.cpp"
using namespace Solution16;
using namespace std;

int main()
{
	Solution16::Three_Sum_Closet useClass;
	Solution16::Three_Sum_Closet::Three_Sum_Closet_Model getTestModel = useClass.GetTestData001();
	int result = useClass.threeSumClosest(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData002();
	result = useClass.threeSumClosest(getTestModel.nums, getTestModel.target);

	getTestModel = useClass.GetTestData003();
	result = useClass.threeSumClosest(getTestModel.nums, getTestModel.target);

	return 0;
}