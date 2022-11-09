#include "0054.Spiral_Matrix.cpp"
using namespace Solution54;
using namespace std;

int main()
{

	Solution54::Spiral_Matrix useClass;
	Solution54::Spiral_Matrix::Spiral_Matrix_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.spiralOrder(getTestModel.matrix);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.spiralOrder(getTestModel.matrix);
	return 0;
}