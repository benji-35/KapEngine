# getMouse

{% hint style="warning" %}
This function is only accessible in a component function
{% endhint %}

### Why

while your game is running, you could need to get mouse position.

This function can give you the position of mouse.



### Example

```cpp
// You are in component function
Tools::Vector2 pos = getMouse().getPosition();
```
