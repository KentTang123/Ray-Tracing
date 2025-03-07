#include <iostream>
#include <core/application.h>

int main() {

    try {
        Kent::Application app;
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "end successfully" << std::endl;

    return 0;
}