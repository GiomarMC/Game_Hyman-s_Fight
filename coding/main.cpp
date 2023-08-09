#include "game_controller.h"
#include <memory>

int main()
{
    std::unique_ptr<Game_controller> game = std::make_unique<Game_controller>();
    game -> run();

    return 0;
}