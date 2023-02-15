#include "Medium\0120.Triangle.cpp"
using namespace Solution120;
using namespace std;

int main()
{
	Solution120::Triangle useClass;
	Solution120::Triangle::Triangle_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.minimumTotal(getTestModel.triangle);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.minimumTotal(getTestModel.triangle);
}