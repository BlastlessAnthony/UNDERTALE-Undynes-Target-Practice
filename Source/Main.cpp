#include "Application.hpp"
using namespace OrionFramework;
int main(int argc, char **argv) {
    Application *app = new Application();
    while (!app->should_close) {
        app->Update();
    }
}