#pragma once

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <exception>
#include <vector>

namespace Kent {
    class Application {
    public:
        Application();
        ~Application();
        void run();

    private:
        VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
        void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
        void initWindow();
        void initVulkan();
        bool checkValidationLayerSupport();
        VkResult createInstance();
        void cleanUp();
    private:
        GLFWwindow* window;
        uint16_t windowWidth;
        uint16_t windowHeight;
        VkInstance instance;
        VkDebugUtilsMessengerEXT debugMessenger;
        const std::vector<const char*> validationLayers = {
            "VK_LAYER_KHRONOS_validation"
        };
    };
}
