#include "glad/glad.h"
#include "GLFW/glfw3.h"

class GameEngine {
public:
    void init();
    void run();
    void shutdown();
private:
    GLFWwindow* window;
    void processInput();
};