#include "0042.Trapping_Rain_Water.cpp"
using namespace Solution42;
using namespace std;

int main()
{
	int result = 0;
	Solution42::Trapping_Rain_Water useClass;
	Solution42::Trapping_Rain_Water::Trapping_Rain_Water_Model getTestModel = useClass.GetTestData001();
	result = useClass.trap(getTestModel.height);

	getTestModel = useClass.GetTestData002();
	result = useClass.trap(getTestModel.height);
	return 0;
}
