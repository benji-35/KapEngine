# Create new one

### About



### Example

```cpp
/* since KapEngine 1.1 */
int main() {
    // before, KapEngine already init and scene too. The scene in stock in scene variable
    auto gameObject = scene->createGameObject("GameObject Name");
}

/* KapEngine 1.0 */
int main() {
    // before, KapEngine already init and scene too. The scene in stock in scene variable
    auto gameObject = KapEngine::Factory::createEmptyGameObject(scene, "GameObject Name");
}C+
```
