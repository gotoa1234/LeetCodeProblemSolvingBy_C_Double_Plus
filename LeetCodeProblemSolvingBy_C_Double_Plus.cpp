#include <unordered_map>
#include "0074.Search_a_2D_Matrix.cpp"
using namespace Solution74;

int main()
{
    Solution74::Search_a_2D_Matrix useClass;
    Solution74::Search_a_2D_Matrix::Search_a_2D_Matrix_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.searchMatrix(getTestModel.matrix, getTestModel.target);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.searchMatrix(getTestModel.matrix, getTestModel.target);

    return 0;
}