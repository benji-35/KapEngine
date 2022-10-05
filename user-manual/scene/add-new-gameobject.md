# Add new GameObject

### About

The second major system in KapEngine is [GameObject](../gameobject/) system. You can understand what is it just with the link below :

{% content-ref url="../gameobject/what-is-it.md" %}
[what-is-it.md](../gameobject/what-is-it.md)
{% endcontent-ref %}

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
}
```
