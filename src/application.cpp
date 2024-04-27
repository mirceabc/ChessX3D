#include "application.h"

namespace ChessX3D {

    Application::Application() {
        Init();
    }

    Application::~Application() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void Application::Init() {
        if (!glfwInit()) {
            std::cerr << "ERROR::GLFW::INITIALIZATION_FAILED" << std::endl;
            exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        m_window = glfwCreateWindow(m_windowProperties.width, m_windowProperties.height, m_windowProperties.title,
                                    nullptr, nullptr);

        if (!m_window) {
            std::cerr << "ERROR::GLFW::WINDOW_CREATION_FAILED" << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(m_window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cerr << "ERROR::GLAD::INITIALIZATION_FAILED" << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glViewport(0, 0, m_windowProperties.width, m_windowProperties.height);

        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow *window, int width, int height) {
            glViewport(0, 0, width, height);
        });
    }

    void Application::Run() {
        while (!glfwWindowShouldClose(m_window)) {
            ProcessInput();
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(m_window);
            glfwPollEvents();
        }
    }

    void Application::ProcessInput() {
        if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(m_window, true);
        }
    }
}

