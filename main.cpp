#include <iostream>
#include <memory>

#include "GameEngineConfig.h"
#include "GameEngine.hpp"
#include "InitException.hpp"

int main() {
    using namespace std;

	cout << "Game Engine!" << endl;
	cout << "Version: " << GameEngine_VERSION_MAJOR << "." << GameEngine_VERSION_MINOR << endl;

    std::unique_ptr<GameEngine> engine = std::make_unique<GameEngine>();
    
    try {
        engine->init();
    } catch (InitException e) {
        cout << e.what();
        engine->shutdown();
        return 1;
    }

    engine->run();
    engine->shutdown();

    return 0;
}