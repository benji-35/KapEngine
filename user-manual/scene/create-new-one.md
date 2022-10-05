# Create new one

### About

If [KapEngine](https://github.com/benji-35/KapEngine) include scenes system, create scenes is really important.

By this importance, our goal is to give you the easiest way to create your own. The main camera of the scene is create automaticly.

### Example

<pre class="language-cpp"><code class="lang-cpp">/* since KapEngine 1.1 */
int main() {
    // before, KapEngine already init and in variable call engine
    auto scene = engine.getSceneManager()->createScene("Scene Name");
    // here scene is shared_ptr
}
<strong>
</strong><strong>/* KapEngine 1.0 */
</strong><strong>int main() {
</strong>    // before, KapEngine already init and in variable call engine
    auto scene = KapEngine::Factory::createScene("Scene Name", *engine.getSceneManager());
    // here scene is shared_ptr
}</code></pre>
