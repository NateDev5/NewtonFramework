# Menu bar

#### [<- Back](../README.md)

---

If you want to create your own menus at the top of your window you can!

---

### Creating your own menu
Creating your own menu is very simple you just need to create an instance of ```NewtonFramework::Menu``` and then add an item.
```c++

#include <NewtonFramework.h>

int main () {
    auto* app = new NewtonFramework::Application("App name", {0, 0, 1});
    
    NewtonFramework::Menu yourMenu = NewtonFramework::Menu("Your Menu Name");
    yourMenu.addItem("Do a task", [] () {
        // everything you want to happen when your item is clicked needs to be in here
    });
    // this will add your menu to the app
    app->addMenu(yourMenu);
    
    app->run();
    
    delete app;
}
```
**NOTE**: Menus need to be created and pushed **BEFORE** the main application loop

---

### Opening custom windows with a menu

```c++

#include <NewtonFramework.h>

int main () {
    auto* app = new NewtonFramework::Application("App name", {0, 0, 1});
    
    NewtonFramework::Menu yourMenu = NewtonFramework::Menu("Your Menu Name");
    yourMenu.addItem("Your Window", [app] () {
        app->addWindow<YourWindow>();
    });
    // this will add your menu to the app
    app->addMenu(yourMenu);
    
    app->run();
    
    delete app;
}
```