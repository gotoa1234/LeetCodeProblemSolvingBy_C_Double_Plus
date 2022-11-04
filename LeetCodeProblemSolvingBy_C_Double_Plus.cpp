#include "0050.Pow_x_n.cpp"
using namespace Solution50;
using namespace std;

int main()
{

	Solution50::Pow_x_n useClass;
	Solution50::Pow_x_n::Pow_x_n_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.myPow(getTestModel.x, getTestModel.n);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.myPow(getTestModel.x, getTestModel.n);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.myPow(getTestModel.x, getTestModel.n);

	getTestModel = useClass.GetTestData004();
	auto result4 = useClass.myPow(getTestModel.x, getTestModel.n);
	return 0;
}
