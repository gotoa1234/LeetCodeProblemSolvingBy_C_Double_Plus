#include "Easy\0111.Minimum_Depth_of_Binary_Tree.cpp"
using namespace Solution111;
using namespace std;

int main()
{
	Solution111::Minimum_Depth_of_Binary_Tree useClass;
	Solution111::Minimum_Depth_of_Binary_Tree::Minimum_Depth_of_Binary_Tree_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.minDepth(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.minDepth(getTestModel.root);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.minDepth(getTestModel.root);
}