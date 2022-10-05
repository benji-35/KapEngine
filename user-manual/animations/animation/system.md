# System

Animation is a simple logic that follow the clock of KapEngine. This clock is made from your internal computer system. For this simple logic you have some functions give to you listed [there](functions.md).



The clock of engine is punctuated by a variable that contain the refreshing of your animation. Basically this refreshing amount is set to 25ms. You can change this amount by using this function below:

```
//you are in your main function
int main() {
    KapEngine::KapEngine engine(false, "My Game", "Version", "Company");
    
    //this line gonna set your refreshing time to 35ms
    engine.setFixedTime(35);
}
```
