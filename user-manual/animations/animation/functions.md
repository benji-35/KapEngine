# Functions

The component Animation allow you to use 3 functions and 3 events.



### Fucntions

These three functions are made to initiate or update values during your animation.

* onPlay : often use to initiate values at the beginning, this function is call when your animation gonna start
* onUpdateAnim : use to change values during your animation. This function is the only function call when your animation is playing.
* onResetAnim : useful if your animation is in loop mode. This function is made to initiate values after playing.



### Events

* getOnStart : Events::EventAction called automaticaly once during onPlay
* getOnEnd : Evetns::EventAction called when your animation ended BUT not in loop mode
* getOnRestart : Events::EventAction called when your animation restart

{% hint style="warning" %}
getOnRestart : available only when animation is in loop mode
{% endhint %}
