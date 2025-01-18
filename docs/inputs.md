# Inputs

#### [<- Back](../README.md)

---

Input handling is a major part of your app if you are using this framework to make a game, sandbox or just something where you need to have user input.

---

### Key input
To handle a key press just add this in your update loop of your [module](modules.md):
```c++
if (NWT_INPUT.isKeyDown(NWT_KEY_A)) {
    // Key is held down
}

if (NWT_INPUT.isKeyPressed(NWT_KEY_A)) {
    // Key is pressed once
{
```

---

### Mouse input
Mouse input is the same as key input but with different method names and params:
```c++
if (NWT_INPUT.isMouseButtonDown(NWT_MOUSE_BUTTON_1)) {
    // Mouse button is held down
}

if (NWT_INPUT.isMouseButtonPressed(NWT_MOUSE_BUTTON_1)) {
    // Mouse button is pressed once
{
```