# Events

#### [<- Back](../README.md)

---

Events are useful for plenty of things but mainly allowing communication between different parts of your app without connection.

---

### Creating a new event

Create a new class that inherits ```NewtonFramework::Event```
Then you can do anything you want with this event. If you want to process/store data you can do it in this class.
```c++
#include <NewtonFramework.h>

class EmptyEvent final : public NewtonFramework::Event {};
```

```c++
#include <NewtonFramework.h>

class EventWithStuff final : public NewtonFramework::Event {
    private:
        std::string data1_;
        int data2_;
    public:
         EventWithStuff(const std::string& data1, int data2)
            : data1_(data1), data2_(data2) {}
        
        [[nodiscard]] std::string getData1 () const {
            return data1_;
        }
        
        [[nodiscard]] int getData2 () const {
            return data2_;
        }
};
```

---

### Subscribing to events
```c++
// The param is the callback that will happen when the event is triggered
NWT_EVENTS.subscribe<YourEvent>(std::bind(&YourClass::eventHappend, this));
```
```c++
// You can add a place holder if you want to receive the event instance to the data
NWT_EVENTS.subscribe<YourEvent>(std::bind(&YourClass::eventHappend, this, std::placeholders::_1));
```
---

### Invoking events
```c++
NWT_EVENTS.invoke<YourEvent>(YourEvent());
```