#include <unordered_map>
#include "Easy/0160.Intersection_of_Two_Linked_Lists.cpp"
using namespace Solution160;

int main()
{
    Solution160::Intersection_of_Two_Linked_Lists useClass;
    Solution160::Intersection_of_Two_Linked_Lists::Intersection_of_Two_Linked_Lists_Model getTestModel = useClass.GetTestData001();
    auto result = useClass.getIntersectionNode(getTestModel.headA, getTestModel.headB);

    return 0;
}