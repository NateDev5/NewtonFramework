# Utils

#### [<- Back](../README.md)

---

## Time
Get the delta time:
```c++
NWT_TIME->deltaTime(); // return a float
```

--- 
## Logging
 
### How to log
Logging is very straighforward you have a couple macros that you can use
```c++
NWT_INFO(message);
NWT_INFO(message, scope);

NWT_WARN(message);
NWT_WARN(message, scope);

NWT_ERR(message);
NWT_ERR(message, scope);

NWT_DBG(message);
NWT_DBG(message, scope);
```

### Creating a custom sink

You can create a custom sink to handle logs yourself. For example if you want to log to a file.
To create a new sink just create a class that inherits ```NewtonFramework::LogSink```
```c++
class YourSink final : public LogSink {
    void write(const LogData &logData) override;
};
```
Override the write method. This is the method where you will be able to handle the logs yourself.
Everytime something is logged this method is called.

### Pushing your sink
If you dont push your sink it wont be used
```c++
NWT_LOGGER.addSink(YourSinkSharedPtr)
```
The add sink method takes a shared pointer of your sink as an argument