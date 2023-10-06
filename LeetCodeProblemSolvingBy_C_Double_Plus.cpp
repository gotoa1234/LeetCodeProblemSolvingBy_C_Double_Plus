#include "Easy\0566.Reshape_the_Matrix.cpp"
using namespace Solution566;

int main()
{
	Solution566::Reshape_the_Matrix useClass;
	Solution566::Reshape_the_Matrix::Reshape_the_Matrix_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.matrixReshape(getTestModel.mat, getTestModel.r, getTestModel.c);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.matrixReshape(getTestModel.mat, getTestModel.r, getTestModel.c);
}