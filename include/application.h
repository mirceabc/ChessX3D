#ifndef CHESSX3D_APPLICATION_H
#define CHESSX3D_APPLICATION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace ChessX3D {

    struct ApplicationWindowProperties {
        int width = 800;
        int height = 600;
        const char *title = "ChessX3D";
    };

    class Application {

    private:
        GLFWwindow *m_window = nullptr;
        ApplicationWindowProperties m_windowProperties;

        void Init();

        void ProcessInput();

    public:
        Application();

        ~Application();

        void Run();
    };

}
#endif //CHESSX3D_APPLICATION_H
