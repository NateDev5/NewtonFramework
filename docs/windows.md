# Windows

#### [<- Back](../README.md)

---

This framework allows you to create your own ImGui Windows very easily.

---

### Creating your custom window
To create your custom window you first need to create a new class that inherits ```NewtonFramework::ImGuiWindow```
```c++
#include <NewtonFramework.h>

class YourWindow final : public NewtonFramework::ImGuiWindow {
public:
    YourWindow();
    void render() override;
};
```
You need to override the render function and have a constructor.

Then in your source file, in the render function you can design your window using the ImGui library. You can also set the name of your window in the constructor.
```c++
YourWindow::YourWindow() {
    // This is a method from the base class
    // If its not called your window will just be called "Window"
    setWindowName("Test Window");
}

void YourWindow::render() {
    ImGui::Text("This is a test window from NewtonFramework!");
}
```

---

### Displaying your window

To display your window you just need to call one method from the app class after its initialization.
```c++
#include <NewtonFramework.h>

int main () {
    auto* app = new NewtonFramework::Application("App name", {0, 0, 1});
    
    // This will display your window when your app starts
    app->addWindow<YourWindow>();
    
    app->run();
    delete app;
}
```

To add your window to the menu bar see: [Menu bar](./menubar.md)