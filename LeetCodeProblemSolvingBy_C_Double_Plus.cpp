#include "0051.N_Queens.cpp"
using namespace Solution51;
using namespace std;

int main()
{

	Solution51::N_Queens useClass;
	Solution51::N_Queens::N_Queens_Model getTestModel = useClass.GetTestData002();
	auto result1 = useClass.solveNQueens(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.solveNQueens(getTestModel.n);
	return 0;
}
