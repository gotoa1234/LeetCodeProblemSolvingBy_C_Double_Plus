#include "0052.N_Queens_II.cpp"
using namespace Solution52;
using namespace std;

int main()
{

	Solution52::N_Queens_II useClass;
	Solution52::N_Queens_II::N_Queens_II_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.totalNQueens(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.totalNQueens(getTestModel.n);
	return 0;
}
