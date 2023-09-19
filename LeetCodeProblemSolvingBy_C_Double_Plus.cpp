#include <vector>
#include "Easy\0350.Intersection_of_Two_Arrays_II.cpp"
using namespace Solution350;

int main()
{
	Solution350::Intersection_of_Two_Arrays_II useClass;
	Solution350::Intersection_of_Two_Arrays_II::Intersection_of_Two_Arrays_II_Model getTestModel = useClass.GetTestData001();
	auto result = useClass.intersect(getTestModel.nums1, getTestModel.nums2);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.intersect(getTestModel.nums1, getTestModel.nums2);
	return 0;
}