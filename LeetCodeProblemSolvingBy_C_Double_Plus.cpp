
#include "0037.Sudoku_Solver.cpp"
using namespace Solution37;
using namespace std;

int main()
{
	Solution37::Sudoku_Solver useClass;
	Solution37::Sudoku_Solver::Sudoku_Solver_Model getTestModel = useClass.GetTestData001();
	useClass.solveSudoku(getTestModel.board);

	getTestModel = useClass.GetTestData002();
	useClass.solveSudoku(getTestModel.board);
	return 0;
}
