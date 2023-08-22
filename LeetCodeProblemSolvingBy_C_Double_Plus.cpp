#include "Medium\0223.Rectangle_Area.cpp"
using namespace Solution223;
using namespace std;

int main()
{
	vector<vector<int>> result = {};
	Solution223::Rectangle_Area useClass;
	Solution223::Rectangle_Area::Rectangle_Area_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.computeArea(getTestModel.ax1, getTestModel.ay1, getTestModel.ax2, getTestModel.ay2, getTestModel.bx1, getTestModel.by1, getTestModel.bx2, getTestModel.by2);

	/*getTestModel = useClass.GetTestData002();
	auto result2 = useClass.computeArea(getTestModel.ax1, getTestModel.ay1, getTestModel.ax2, getTestModel.ay2, getTestModel.bx1, getTestModel.by1, getTestModel.bx2, getTestModel.by2);*/

	return 0;
}
