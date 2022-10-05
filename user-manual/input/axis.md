# Axis

### About

Axis is simple logic way to detect inputs and give to them a logic. Axis contain positive and negative input. When you gonna call getAxis button, you gonna get the result of checking input.



### Containing

* Postive : Key that give you 1.f value
* Alt Positive : alternative Key that give you 1.f value
* Negative : Key that give you -1.f value
* Alt Negative : alternative Key that give you -1.f value
* Joystick Id : id of joystick (Depends of your graphical library)
* Gamepad Id : the id of gamepad

If you invert keys, you can invert values by set "invert" variable of axis by true.



### Example

```cpp
KapEngine::Events::Input::Axis axis("Vertical");

//init vertical axis
axis.positiveButton = KapEngine::Events::Key::W;
axis.altPositiveButton = KapEngine::Events::Key::UP;
axis.negativeButton = KapEngine::Events::Key::S;
axis.altNegativeButton = KapEngine::Events::Key::DOWN;
```
