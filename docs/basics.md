# Basics

#### [<- Back](../README.md)

---
### **Creating an application**

```c++
NewtonFramework::Application(const std::string& appName, const Version& version);
```
```c++
#include <NewtonFramework.h>

int main () {
    // Create the app
    auto* app = new NewtonFramework::Application("App name", {0, 0, 1});
    
    // Run it
    app->run();
    
    // Delete it
    delete app;
}
```

##### Version struct:
```c++
struct Version {
   unsigned int major;
   unsigned int minor;
   unsigned int patch;
}
```
---
### Activating features
The framework comes with basic features that can be enabled after your app creation.
```NewtonFramework::Application::enableFeature(AppFeature feature)```

To enable a feature simply do:
```c++
#include <NewtonFramework.h>

int main () {
    auto* app = new NewtonFramework::Application("App name", {0, 0, 1});
    
    // This is how you enable it
    app->enableFeature(NewtonFramework::Profiler);
    app->enableFeature(NewtonFramework::Logs);
    
    app->run();
    
    delete app;
}
```
**NOTE**: It is very important that features are enabled **BEFORE** running the main application loop.

**Features list**:
- Profiler
- Logs
- Stdout Sink