# Useful functions

### Add new component

KapEngine include component system. Because of this system, you can add components in your GameObject. To do that you have this function :

```cpp
addComponent(std::shared_ptr<Component>);
```

### Get contains component

If you can add components, you can get all components that GameObject contains. For that you can use these functions :

```cpp
/* KapEngine 1.0 */
Component &comp = getComponent("ComponentName");
/* Since KapEngine 1.1.02 */
MyComponent &comp = getComponent<MyComponent>();
```

### Remove component

If you can add components, logically you can remove components. To do that, you can use this function :

```cpp
/* if you component is shared_ptr */
removeComponent(myComponent);

/* if your component is reference or other */
removeComponent(myComponent.getId());
```

### Check contains component

You can check if your GameObject contains a specific component with the function below :

```cpp
bool result = hasComponent("ComponentName");
```

### Check GameObject is active

You can also check if your GameObject is active by this function :

```cpp
bool result = isACtive();
```

### Get scene

As you can read in [scene](../scene/) category, scenes are one of main system in KapEngine. Because of GameObjects are stock in scene, you can get the scene where your GameObject is stock with this function :

```cpp
SceneManagement::Scene &scene = getScene();
```
