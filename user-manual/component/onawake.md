# onAwake

### Why ?

Useful to initiate values.

This function is called only once : at the beginning of the scene (each time scene is loaded).

### When ?

At the beginning of game. Even if your component is disable, this function gonna be call.

### Prototype

```cpp
//hpp
void onAwake() override;
//cpp
void KapEngine::MyGame::MyComponent::onAwake() {
    //do what you want
}
```
