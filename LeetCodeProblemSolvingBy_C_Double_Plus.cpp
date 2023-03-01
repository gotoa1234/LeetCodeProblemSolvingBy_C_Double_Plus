#include "Medium\0134.Gas_Station.cpp"
using namespace Solution134;
using namespace std;

int main()
{
	Solution134::Gas_Station useClass;
	Solution134::Gas_Station::Gas_Station_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.canCompleteCircuit(getTestModel.gas, getTestModel.cost);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.canCompleteCircuit(getTestModel.gas, getTestModel.cost);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.canCompleteCircuit(getTestModel.gas, getTestModel.cost);
}