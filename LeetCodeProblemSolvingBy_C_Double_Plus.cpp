#include "Easy\0119.Pascal_s_Triangle_II.cpp"
using namespace Solution119;
using namespace std;

int main()
{
	Solution119::Pascal_s_Triangle_II useClass;
	Solution119::Pascal_s_Triangle_II::Pascal_s_Triangle_II_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.getRow(getTestModel.rowIndex);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.getRow(getTestModel.rowIndex);
}