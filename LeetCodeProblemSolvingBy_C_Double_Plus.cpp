#include <unordered_map>
#include "Hard/0174.Dungeon_Game.cpp"
using namespace Solution174;

int main()
{
    Solution174::Dungeon_Game useClass;
    Solution174::Dungeon_Game::Dungeon_Game_Model getTestModel = useClass.GetTestData001();
    auto result1 = useClass.calculateMinimumHP(getTestModel.dungeon);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.calculateMinimumHP(getTestModel.dungeon);
}