#include "Medium\0103.Binary_Tree_Zigzag_Level_Order_Traversal.cpp"
#include <iostream>
#include <unordered_map>
#include <string>
using namespace Solution103;
using namespace std;


int main()
{
	Solution103::Binary_Tree_Level_Order_Traversal useClass;
	Solution103::Binary_Tree_Level_Order_Traversal::Binary_Tree_Level_Order_Traversal_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.zigzagLevelOrder(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.zigzagLevelOrder(getTestModel.root);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.zigzagLevelOrder(getTestModel.root);
}