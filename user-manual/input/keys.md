# Keys

### Enumeration of all keys

```cpp
enum EKey {
                    UNKNOWN         = -1,        // Key: NULL, used for no key pressed
                    APOSTROPHE      = 39,       // Key: '
                    COMMA           = 44,       // Key: ,
                    MINUS           = 45,       // Key: -
                    PERIOD          = 46,       // Key: .
                    SLASH           = 47,       // Key: /
                    NUM0            = 48,       // Key: 0
                    NUM1            = 49,       // Key: 1
                    NUM2            = 50,       // Key: 2
                    NUM3            = 51,       // Key: 3
                    NUM4            = 52,       // Key: 4
                    NUM5            = 53,       // Key: 5
                    NUM6            = 54,       // Key: 6
                    NUM7            = 55,       // Key: 7
                    NUM8            = 56,       // Key: 8
                    NUM9            = 57,       // Key: 9
                    SEMICOLON       = 59,       // Key: ;
                    EQUAL           = 61,       // Key: =
                    A               = 65,       // Key: A | a
                    B               = 66,       // Key: B | b
                    C               = 67,       // Key: C | c
                    D               = 68,       // Key: D | d
                    E               = 69,       // Key: E | e
                    F               = 70,       // Key: F | f
                    G               = 71,       // Key: G | g
                    H               = 72,       // Key: H | h
                    I               = 73,       // Key: I | i
                    J               = 74,       // Key: J | j
                    K               = 75,       // Key: K | k
                    L               = 76,       // Key: L | l
                    M               = 77,       // Key: M | m
                    N               = 78,       // Key: N | n
                    O               = 79,       // Key: O | o
                    P               = 80,       // Key: P | p
                    Q               = 81,       // Key: Q | q
                    R               = 82,       // Key: R | r
                    S               = 83,       // Key: S | s
                    T               = 84,       // Key: T | t
                    U               = 85,       // Key: U | u
                    V               = 86,       // Key: V | v
                    W               = 87,       // Key: W | w
                    X               = 88,       // Key: X | x
                    Y               = 89,       // Key: Y | y
                    Z               = 90,       // Key: Z | z
                    LEFT_BRACKET    = 91,       // Key: [
                    BACKSLASH       = 92,       // Key: '\'
                    RIGHT_BRACKET   = 93,       // Key: ]
                    GRAVE           = 96,       // Key: `
                    SPACE           = 32,       // Key: Space
                    ESCAPE          = 256,      // Key: Esc
                    ENTER           = 257,      // Key: Enter
                    TAB             = 258,      // Key: Tab
                    BACKSPACE       = 259,      // Key: Backspace
                    INSERT          = 260,      // Key: Ins
                    DELETE          = 261,      // Key: Del
                    RIGHT           = 262,      // Key: Cursor right
                    LEFT            = 263,      // Key: Cursor left
                    DOWN            = 264,      // Key: Cursor down
                    UP              = 265,      // Key: Cursor up
                    PAGE_UP         = 266,      // Key: Page up
                    PAGE_DOWN       = 267,      // Key: Page down
                    HOME            = 268,      // Key: Home
                    END             = 269,      // Key: End
                    CAPS_LOCK       = 280,      // Key: Caps lock
                    SCROLL_LOCK     = 281,      // Key: Scroll down
                    NUM_LOCK        = 282,      // Key: NUM lock
                    PRINT_SCREEN    = 283,      // Key: Print screen
                    PAUSE           = 284,      // Key: Pause
                    F1              = 290,      // Key: F1
                    F2              = 291,      // Key: F2
                    F3              = 292,      // Key: F3
                    F4              = 293,      // Key: F4
                    F5              = 294,      // Key: F5
                    F6              = 295,      // Key: F6
                    F7              = 296,      // Key: F7
                    F8              = 297,      // Key: F8
                    F9              = 298,      // Key: F9
                    F10             = 299,      // Key: F10
                    F11             = 300,      // Key: F11
                    F12             = 301,      // Key: F12
                    LEFT_SHIFT      = 340,      // Key: Shift left
                    LEFT_CONTROL    = 341,      // Key: Control left
                    LEFT_ALT        = 342,      // Key: Alt left
                    LEFT_SUPER      = 343,      // Key: Super left
                    RIGHT_SHIFT     = 344,      // Key: Shift right
                    RIGHT_CONTROL   = 345,      // Key: Control right
                    RIGHT_ALT       = 346,      // Key: Alt right
                    RIGHT_SUPER     = 347,      // Key: Super right
                    KB_MENU         = 348,      // Key: KB menu
                    KP_0            = 320,      // Key: Keypad 0
                    KP_1            = 321,      // Key: Keypad 1
                    KP_2            = 322,      // Key: Keypad 2
                    KP_3            = 323,      // Key: Keypad 3
                    KP_4            = 324,      // Key: Keypad 4
                    KP_5            = 325,      // Key: Keypad 5
                    KP_6            = 326,      // Key: Keypad 6
                    KP_7            = 327,      // Key: Keypad 7
                    KP_8            = 328,      // Key: Keypad 8
                    KP_9            = 329,      // Key: Keypad 9
                    KP_DECIMAL      = 330,      // Key: Keypad .
                    KP_DIVIDE       = 331,      // Key: Keypad /
                    KP_MULTIPLY     = 332,      // Key: Keypad *
                    KP_SUBTRACT     = 333,      // Key: Keypad -
                    KP_ADD          = 334,      // Key: Keypad +
                    KP_ENTER        = 335,      // Key: Keypad Enter
                    KP_EQUAL        = 336,      // Key: Keypad =
                    BACK = 349,                 // Key: Android back button
                    MENU,                       // Key: Android menu button
                    VOLUME_UP,                  // Key: Android volume up button
                    VOLUME_DOWN,                // Key: Android volume down button
                    MOUSE_LEFT,                 // Mouse button left
                    MOUSE_RIGHT,                // Mouse button right
                    MOUSE_MIDDLE,               // Mouse button middle (pressed wheel)
                    MOUSE_SIDE,                 // Mouse button side (advanced mouse device)
                    MOUSE_EXTRA,                // Mouse button extra (advanced mouse device)
                    MOUSE_FORWARD,              // Mouse button fordward (advanced mouse device)
                    MOUSE_BACK,                 // Mouse button back (advanced mouse device)
                    //all gamepads
                    GAMEPAD_LEFT_FACE_UP,       // Gamepad left DPAD up button
                    GAMEPAD_LEFT_FACE_RIGHT,    // Gamepad left DPAD right button
                    GAMEPAD_LEFT_FACE_DOWN,     // Gamepad left DPAD down button
                    GAMEPAD_LEFT_FACE_LEFT,     // Gamepad left DPAD left button
                    GAMEPAD_RIGHT_FACE_UP,      // Gamepad right button up (i.e. PS3: Triangle, Xbox: Y)
                    GAMEPAD_RIGHT_FACE_RIGHT,   // Gamepad right button right (i.e. PS3: Square, Xbox: X)
                    GAMEPAD_RIGHT_FACE_DOWN,    // Gamepad right button down (i.e. PS3: Cross, Xbox: A)
                    GAMEPAD_RIGHT_FACE_LEFT,    // Gamepad right button left (i.e. PS3: Circle, Xbox: B)
                    GAMEPAD_LEFT_TRIGGER_1,     // Gamepad top/back trigger left (first), it could be a trailing button
                    GAMEPAD_LEFT_TRIGGER_2,     // Gamepad top/back trigger left (second), it could be a trailing button
                    GAMEPAD_RIGHT_TRIGGER_1,    // Gamepad top/back trigger right (one), it could be a trailing button
                    GAMEPAD_RIGHT_TRIGGER_2,    // Gamepad top/back trigger right (second), it could be a trailing button
                    GAMEPAD_MIDDLE_LEFT,        // Gamepad center buttons, left one (i.e. PS3: Select)
                    GAMEPAD_MIDDLE,             // Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX)
                    GAMEPAD_MIDDLE_RIGHT,       // Gamepad center buttons, right one (i.e. PS3: Start)
                    GAMEPAD_LEFT_THUMB,         // Gamepad joystick pressed button left
                    GAMEPAD_RIGHT_THUMB,        // Gamepad joystick pressed button right
                    //gamepad 0
                    GAMEPAD0_LEFT_FACE_UP,       // Gamepad left DPAD up button
                    GAMEPAD0_LEFT_FACE_RIGHT,    // Gamepad left DPAD right button
                    GAMEPAD0_LEFT_FACE_DOWN,     // Gamepad left DPAD down button
                    GAMEPAD0_LEFT_FACE_LEFT,     // Gamepad left DPAD left button
                    GAMEPAD0_RIGHT_FACE_UP,      // Gamepad right button up (i.e. PS3: Triangle, Xbox: Y)
                    GAMEPAD0_RIGHT_FACE_RIGHT,   // Gamepad right button right (i.e. PS3: Square, Xbox: X)
                    GAMEPAD0_RIGHT_FACE_DOWN,    // Gamepad right button down (i.e. PS3: Cross, Xbox: A)
                    GAMEPAD0_RIGHT_FACE_LEFT,    // Gamepad right button left (i.e. PS3: Circle, Xbox: B)
                    GAMEPAD0_LEFT_TRIGGER_1,     // Gamepad top/back trigger left (first), it could be a trailing button
                    GAMEPAD0_LEFT_TRIGGER_2,     // Gamepad top/back trigger left (second), it could be a trailing button
                    GAMEPAD0_RIGHT_TRIGGER_1,    // Gamepad top/back trigger right (one), it could be a trailing button
                    GAMEPAD0_RIGHT_TRIGGER_2,    // Gamepad top/back trigger right (second), it could be a trailing button
                    GAMEPAD0_MIDDLE_LEFT,        // Gamepad center buttons, left one (i.e. PS3: Select)
                    GAMEPAD0_MIDDLE,             // Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX)
                    GAMEPAD0_MIDDLE_RIGHT,       // Gamepad center buttons, right one (i.e. PS3: Start)
                    GAMEPAD0_LEFT_THUMB,         // Gamepad joystick pressed button left
                    GAMEPAD0_RIGHT_THUMB,        // Gamepad joystick pressed button right
                    //gamepad 1
                    GAMEPAD1_LEFT_FACE_UP,       // Gamepad left DPAD up button
                    GAMEPAD1_LEFT_FACE_RIGHT,    // Gamepad left DPAD right button
                    GAMEPAD1_LEFT_FACE_DOWN,     // Gamepad left DPAD down button
                    GAMEPAD1_LEFT_FACE_LEFT,     // Gamepad left DPAD left button
                    GAMEPAD1_RIGHT_FACE_UP,      // Gamepad right button up (i.e. PS3: Triangle, Xbox: Y)
                    GAMEPAD1_RIGHT_FACE_RIGHT,   // Gamepad right button right (i.e. PS3: Square, Xbox: X)
                    GAMEPAD1_RIGHT_FACE_DOWN,    // Gamepad right button down (i.e. PS3: Cross, Xbox: A)
                    GAMEPAD1_RIGHT_FACE_LEFT,    // Gamepad right button left (i.e. PS3: Circle, Xbox: B)
                    GAMEPAD1_LEFT_TRIGGER_1,     // Gamepad top/back trigger left (first), it could be a trailing button
                    GAMEPAD1_LEFT_TRIGGER_2,     // Gamepad top/back trigger left (second), it could be a trailing button
                    GAMEPAD1_RIGHT_TRIGGER_1,    // Gamepad top/back trigger right (one), it could be a trailing button
                    GAMEPAD1_RIGHT_TRIGGER_2,    // Gamepad top/back trigger right (second), it could be a trailing button
                    GAMEPAD1_MIDDLE_LEFT,        // Gamepad center buttons, left one (i.e. PS3: Select)
                    GAMEPAD1_MIDDLE,             // Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX)
                    GAMEPAD1_MIDDLE_RIGHT,       // Gamepad center buttons, right one (i.e. PS3: Start)
                    GAMEPAD1_LEFT_THUMB,         // Gamepad joystick pressed button left
                    GAMEPAD1_RIGHT_THUMB,        // Gamepad joystick pressed button right
                    //specials keys
                    TILDE,
                    UNDERSCORE,
                    F13,
                    F14,
                    F15,
                    //equalities
                    QUOTE = APOSTROPHE,
                    SUBSTRACT = MINUS,          // '-'
                    DIVIDE = SLASH,             // '/'
                    POINT = PERIOD,             // '.'

                };

```



### Useful functions

* static intInEnum : you can check if int value is contain in EKey enum
* static minValue : give you the minimum int value that EKey enum contains
* static maxValue : give you the maximum int value that EKey enum contains
* isKeyboardKey : check if current key is a keyboard key
* isMouseKey : check if current key is a mouse key
* isGamepadKey : check if current key is a gamepad key
* get : get key contain in Key class
* toString : get name of input
* getTextValue : give char value that can write in text with current key
