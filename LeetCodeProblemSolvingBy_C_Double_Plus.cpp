#include <unordered_map>
#include "Easy\0088.Merge_Sorted_Array.cpp"
using namespace Solution88;

int main()
{
    Solution88::Merge_Sorted_Array useClass;
    Solution88::Merge_Sorted_Array::Merge_Sorted_Array_Model getTestModel = useClass.GetTestData001();
    useClass.merge(getTestModel.nums1, getTestModel.m, getTestModel.nums2, getTestModel.n);

    getTestModel = useClass.GetTestData002();
    useClass.merge(getTestModel.nums1, getTestModel.m, getTestModel.nums2, getTestModel.n);

    getTestModel = useClass.GetTestData003();
    useClass.merge(getTestModel.nums1, getTestModel.m, getTestModel.nums2, getTestModel.n);
    return 0;
}