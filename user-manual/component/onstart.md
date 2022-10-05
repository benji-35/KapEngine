# onStart

### Why ?

As the [onAwake](onawake.md) function, this function is made to init variables.

### When ?

The difference between onAwake and this function is condition of execution. This function is call in same way of onAwake but the component have to be enable.

### Prototype

```cpp
//hpp
void onStart() override;
//cpp
void KapEngine::MyGame::MyComponent::onStart() {
    //do what you want
}
```
