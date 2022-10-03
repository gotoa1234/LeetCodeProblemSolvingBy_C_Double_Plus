#include "0011.Container_With_Most_Water.cpp"
using namespace Solution11;
using namespace std;

int main()
{
	Solution11::Container_With_Most_Water useClass;
	Solution11::Container_With_Most_Water::Container_With_Most_Water_Model getTestModel = useClass.GetTestData001();
	int result = useClass.maxArea(getTestModel.height);

	getTestModel = useClass.GetTestData002();
	result = useClass.maxArea(getTestModel.height);

	return 0;
}