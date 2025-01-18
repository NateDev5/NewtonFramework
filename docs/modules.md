# Modules

#### [<- Back](../README.md)

---

Modules are essentially small parts of your app that have their own **attach**, **update** and **destroy** events.
This allows for a clean and organised app.
---
### Creating your own module
To create your own module you need to create a new class that inherits ```NewtonFramework::Module```

```c++
#include <NewtonFramework.h>

class YourModule final : public NewtonFramework::Module {
    void onAttach() override;
    void onUpdateStart() override;
    void onUpdate() override;
    void onUpdateEnd() override;
    void onDestroy() override;
}
```

You need to override all the methods from the base module class.

### Methods
**onAttach**: Runs once when it is pushed to the stack

**onUpdateStart**: Runs at the start of every frame

**onUpdate**: Runs every frame

**onUpdateEnd**: Runs at the end of every frame

**onDestroy**: Runs before exiting the program. This is usually used to clean up resources.

---
### Pushing a module to the stack
Pushing your custom module to the stack is essential if you want it to run. Pushing a module to the module stack is very straightforward.
```c++
#include <NewtonFramework.h>

int main () {
    auto* app = new NewtonFramework::Application("App name", {0, 0, 1});
    
    // Push it using this method right after creation
    app->pushModule(std::make_shared<YourModule>());
    
    app->run();
    delete app;
}
```

**NOTE**: It is very important for your module to be pushed **BEFORE** running the main app loop.