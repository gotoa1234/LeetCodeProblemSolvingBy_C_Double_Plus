#include <unordered_map>
#include "0073.Set_Matrix_Zeroes.cpp"
using namespace Solution73;

int main()
{
    Solution73::Set_Matrix_Zeroes useClass;
    Solution73::Set_Matrix_Zeroes::Set_Matrix_Zeroes_Model getTestModel = useClass.GetTestData001();
    useClass.setZeroes(getTestModel.matrix);

    getTestModel = useClass.GetTestData002();
    useClass.setZeroes(getTestModel.matrix);

    return 0;
}