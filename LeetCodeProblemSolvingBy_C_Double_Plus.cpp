#include <vector>
#include "0733.Flood_Fill.cpp"
using namespace Solution733;

int main()
{
	Solution733::Flood_Fill useClass;
	Solution733::Flood_Fill::Flood_Fill_Model getTestModel = useClass.GetTestData001();
	vector<vector<int>> result = useClass.floodFill(getTestModel.image, getTestModel.sr, getTestModel.sc, getTestModel.color);

	getTestModel = useClass.GetTestData002();
	result = useClass.floodFill(getTestModel.image, getTestModel.sr, getTestModel.sc, getTestModel.color);
	return 0;
}
