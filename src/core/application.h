#pragma once

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <exception>
#include <vector>
#include <cstring>
#include <iostream>

namespace Kent {
    class Application {
    public:
        Application();
        ~Application();
        void run();
    private:
        void initWindow();
        void initVulkan();
        bool checkValidationLayerSupport()const;
        std::vector<const char*> getRequiredExtensions()const;
        static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData);
        VkResult CreateDebugUtilsMessengerEXT(
            VkInstance instance,
            const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
            const VkAllocationCallbacks* pAllocator,
            VkDebugUtilsMessengerEXT* pDebugMessenger);
        void DestroyDebugUtilsMessengerEXT(
            VkInstance instance,
            VkDebugUtilsMessengerEXT debugMessenger,
            const VkAllocationCallbacks* pAllocator);
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo)const;
        VkResult setupDebugMessenger();
        VkResult createInstance();
        void cleanUp();
    private:
        GLFWwindow* window;
        uint16_t windowWidth;
        uint16_t windowHeight;
        bool  enableValidationLayers;
        const std::vector<const char*> validationLayers = {
            "VK_LAYER_KHRONOS_validation"
        };
        VkDebugUtilsMessengerEXT debugMessenger;
        VkInstance instance;
    };
}
