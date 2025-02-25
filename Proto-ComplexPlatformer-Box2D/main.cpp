#include "Window.h"
#include "SpriteFactory.h"
#include "LevelLoader.h"
#include "Game.h"
#include "version.h"

int main(int argc, char *argv[])
{
    printf("Proto-ComplexPlatformer v%s", agp::VERSION().c_str());

    agp::Game::instance();
    agp::SpriteFactory::instance();
    agp::LevelLoader::instance();

    agp::Game::instance()->run();

    return EXIT_SUCCESS;
}
