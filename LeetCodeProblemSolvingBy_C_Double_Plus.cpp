#include "0059.Spiral_Matrix_II.cpp"
using namespace Solution59;
using namespace std;

int main()
{
	Solution59::Spiral_Matrix_II useClass;
	Solution59::Spiral_Matrix_II::Spiral_Matrix_II_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.generateMatrix(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.generateMatrix(getTestModel.n);
}
