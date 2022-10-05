# Add animations

If animator manage animations, you should have animations in animator component. Because of that you can add you animation in the animator.



### Example

```cpp
/*
    In this exemple you 2 variables
    Your component animator in std::shared_ptr (shared_ptr is only if you keep value of compoent creation)
    Your animation in std::shared_ptr (same as animator, shared_ptr is only for variable creation)
*/

animator->addAnim(animation, "My unique animation name for animator");
```

{% hint style="warning" %}
Each animations in same Animator must have a unique name in animator.
{% endhint %}

This unique name allows you to create links between animations.
