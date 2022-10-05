# Links

Links is the main system of Animator. It allows you to add logical way between two animation with or without conditions called "Trigger".



### Add new link

There is 2 ways to add new link

First one : without condition (at the end of animation, animator gonna take the second animation)

```cpp
/*
    animator is std::shared_ptr of Animator component
    you have already added your 2 animations "Anim1" and "Anim2" in your animator
*/
animator->addLink("Anim1", "Anim2");
```

Second one : with trigger (when trigger is call, animator gonna play second animation and stop first one)

```cpp
/*
    animator is std::shared_ptr of Animator component
    you have already added your 2 animations "Anim1" and "Anim2" in your animator
*/
animator->addLink("Anim1", "Anim2", "MyTrigger");

// or if you want set many triggers
std::vector<std::string> triggers;
triggers.push_back("MyTrigger1");
triggers.push_back("MyTrigger2");

animator->addLink("Anim1", "Anim2", triggers);
```



### Call trigger

Now we know how to link our animations. It's time to call trigger in condition from a component.

Example :

```cpp
// you are in MyComponent
// your animator is added to the same GameObject

//this include allows you to get events like inputs
#include "KapEngineEvents.hpp"

void KapEngine::MyGame::MyComponent::onUpdate() {
    if (getInput().getKeyDown(Events::Key::UP)) {
        auto &animator = getGameObject().getComponent<Animator>();
        animator.setTrigger("TriggerName");
    }
}
```

In this function, each time the user pressed UP, the trigger of animator is true. Then animator gonna change animation with the link you set with this name.
