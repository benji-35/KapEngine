/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Key
*/

#ifndef KEY_HPP_
#define KEY_HPP_

#include <string>

namespace KapEngine {
    namespace Events {

        class Key {
            public:
                Key() {}
                ~Key() {}

                /**
                 * @enum EKey
                 * enumeration of all keys that engine can detect
                 * @brief all keys
                 */
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

                /**
                 * @fn static EKey maxValue()
                 * Get the max value of the EKey enum
                 * @brief Max value EKey
                 * @return KapEngine::Events::Key::EKey 
                 */
                static EKey maxValue() {
                    return F15;
                }

                /**
                 * @fn static EKey minValue()
                 * Get the minimum value of the EKey enum
                 * @brief Minimum value EKey
                 * @return KapEngine::Events::Key::EKey 
                 */
                static EKey minValue() {
                    return UNKNOWN;
                }

                Key &operator=(EKey const& _ek) {
                    this->_last = _ek;
                    return *this;
                }
                Key &operator=(Key const& _k) {
                    this->_last = _k._last;
                    return *this;
                }
                bool operator==(EKey const& _ek) const {
                    return (this->_last == _ek);
                }
                bool operator==(Key const& _k) const {
                    return (this->_last == _k._last);
                }
                bool operator!=(EKey const& _ek) const {
                    return !(*this == _ek);
                }
                bool operator!=(Key const& _ek) const {
                    return !(*this == _ek);
                }

                /**
                 * @fn static bool intInEnum(int const& id)
                 * Check if index "id" exists in the KapEngine::Events::Key::EKey enum
                 * @brief Check id in enum
                 * @param id index (int)
                 * @retval true if index is in the KapEngine::Events::Key::EKey enum
                 * @retval false if index is not in the KapEngine::Events::Key::EKey enum
                 */
                static bool intInEnum(int const& id) {
                    if (id == -1)
                        return true;
                    if (id == 32)
                        return true;
                    if (id == 96)
                        return true;
                    if (id == 59)
                        return true;
                    if (id >= 44 && id <= 57)
                        return true;
                    //A to Z + 2 keyboard input
                    if (id >= 65 && id <= 93)
                        return true;
                    if (id >= 259 && id <= 269)
                        return true;
                    if (id >= 280 && id <= 284)
                        return true;
                    if (id >= 290 && id <= 301)
                        return true;
                    if (id >= 320 && id <= 336)
                        return true;
                    if (id >= 340)
                        return true;
                    if (id >= EKey::MENU && id <= EKey::F15)
                        return true;
                    return false;
                }

                /**
                 * @fn bool isKeyboardKey() const
                 * Check if _last variable is a keyboard key
                 * @brief Check is a keyboard key
                 * @retval true if _last is a keyboard key
                 * @retval false if _last is not a keyboard key
                 */
                bool isKeyboardKey() const {
                    if (_last >= 1 && _last <= EKey::VOLUME_DOWN)
                        return true;
                    if (_last >= EKey::TILDE && _last <= EKey::F15)
                        return true;
                    return false;
                }

                /**
                 * @fn bool isMouseKey() const
                 * permet de savoir si la touche enregistrer dans la variable _last est une touche de souris
                 * @brief vérifie si la touche provient de la souris
                 * @retval true si la touche vient de la souris
                 * @retval false si la touche n'est pas de la souris
                 */
                bool isMouseKey() const {
                    if (_last >= EKey::MOUSE_LEFT && _last <= EKey::MOUSE_BACK)
                        return true;
                    return false;
                }

                /**
                 * @fn bool isGamepadKey() const
                 * Check if _last is a gamepad key
                 * @brief Check is a gamepad key
                 * @retval true if _last is a gamepad key
                 * @retval false if _last is not a gamepad key
                 */
                bool isGamepadKey() const {
                    if (!isKeyboardKey() && !isMouseKey())
                        return true;
                    return false;
                }
                
                Key &operator=(int const& _k) {
                    if (_k > maxValue() || _k < minValue()) {
                        _last = UNKNOWN;
                    }else {
                        _last = (EKey) _k;
                    }
                    return *this;
                }

                /**
                 * @fn std::string toString() const
                 * Get name of key in string value
                 * @brief Get key name
                 * @return std::string
                 */
                std::string toString() const {
                    switch (_last) {
                        case A:
                            return "A";
                        case B:
                            return "B";
                        case C:
                            return "C";
                        case D:
                            return "D";
                        case E:
                            return "E";
                        case F:
                            return "F";
                        case G:
                            return "G";
                        case H:
                            return "H";
                        case I:
                            return "I";
                        case J:
                            return "J";
                        case K:
                            return "K";
                        case L:
                            return "L";
                        case M:
                            return "M";
                        case N:
                            return "N";
                        case O:
                            return "O";
                        case P:
                            return "P";
                        case Q:
                            return "Q";
                        case R:
                            return "R";
                        case S:
                            return "S";
                        case T:
                            return "T";
                        case U:
                            return "U";
                        case V:
                            return "V";
                        case W:
                            return "W";
                        case X:
                            return "X";
                        case Y:
                            return "Y";
                        case Z:
                            return "Z";
                        case NUM0:
                            return "NUM0";
                        case NUM1:
                            return "NUM1";
                        case NUM2:
                            return "NUM2";
                        case NUM3:
                            return "NUM3";
                        case NUM4:
                            return "NUM4";
                        case NUM5:
                            return "NUM5";
                        case NUM6:
                            return "NUM6";
                        case NUM7:
                            return "NUM7";
                        case NUM8:
                            return "NUM8";
                        case NUM9:
                            return "NUM9";
                        case ESCAPE:
                            return "ESCAPE";
                        case LEFT_CONTROL:
                            return "LEFT_CONTROL";
                        case LEFT_SHIFT:
                            return "LEFT_SHIFT";
                        case LEFT_ALT:
                            return "LEFT_ALT";
                        case LEFT_SUPER:
                            return "LEFT_SUPER";
                        case RIGHT_CONTROL:
                            return "RIGHT_CONTROL";
                        case RIGHT_SHIFT:
                            return "RIGHT_SHIFT";
                        case RIGHT_ALT:
                            return "RIGHT_ALT";
                        case RIGHT_SUPER:
                            return "RIGHT_SUPER";
                        case LEFT_BRACKET:
                            return "BACKSLASH";
                        case RIGHT_BRACKET:
                            return "RIGHT_BRACKET";
                        case SEMICOLON:
                            return "SEMICOLON";
                        case COMMA:
                            return "COMMA";
                        case PERIOD:
                            return "PERIOD | POINT";
                        case SLASH:
                            return "SLASH | DIVIDE";
                        case BACKSLASH:
                            return "BACKSLASH";
                        case EQUAL:
                            return "EQUAL";
                        case UNDERSCORE:
                            return "UNDERSCORE";
                        case SPACE:
                            return "SPACE";
                        case ENTER:
                            return "ENTER";
                        case BACKSPACE:
                            return "BACKSPACE";
                        case TAB:
                            return "TAB";
                        case PAGE_UP:
                            return "PAGE_UP";
                        case PAGE_DOWN:
                            return "PAGE_DOWN";
                        case END:
                            return "END";
                        case HOME:
                            return "HOME";
                        case INSERT:
                            return "INSERT";
                        case DELETE:
                            return "DELETE";
                        case KP_ADD:
                            return "KP_ADD";
                        case SUBSTRACT:
                            return "MINUS";
                        case KP_MULTIPLY:
                            return "KP_MULTIPLY";
                        case LEFT:
                            return "LEFT";
                        case RIGHT:
                            return "RIGHT";
                        case UP:
                            return "UP";
                        case DOWN:
                            return "DOWN";
                        case KP_0:
                            return "KP_0";
                        case KP_1:
                            return "KP_1";
                        case KP_2:
                            return "KP_2";
                        case KP_3:
                            return "KP_3";
                        case KP_4:
                            return "KP_4";
                        case KP_5:
                            return "KP_5";
                        case KP_6:
                            return "KP_6";
                        case KP_7:
                            return "KP_7";
                        case KP_8:
                            return "KP_8";
                        case KP_9:
                            return "KP_9";
                        case F1:
                            return "F1";
                        case F2:
                            return "F2";
                        case F3:
                            return "F3";
                        case F4:
                            return "F4";
                        case F5:
                            return "F5";
                        case F6:
                            return "F6";
                        case F7:
                            return "F7";
                        case F8:
                            return "F8";
                        case F9:
                            return "F9";
                        case F10:
                            return "F10";
                        case F11:
                            return "F11";
                        case F12:
                            return "F12";
                        case F13:
                            return "F13";
                        case F14:
                            return "F14";
                        case F15:
                            return "F15";
                        case PAUSE:
                            return "PAUSE";
                        case MOUSE_LEFT:
                            return "MOUSE_LEFT";
                        case MOUSE_RIGHT:
                            return "MOUSE_RIGHT";
                        case MOUSE_MIDDLE:
                            return "MouseMiddle";
                        case MOUSE_EXTRA:
                            return "MOUSE_EXTRA";
                        case MOUSE_SIDE:
                            return "MOUSE_SIDE";
                        case MOUSE_BACK:
                            return "MOUSE_BACK";
                        case MOUSE_FORWARD:
                            return "MOUSE_FORWARD";
                        case MENU:
                            return "MENU (Android)";
                        default:
                            return "Unknown";
                    }
                }

                EKey get() const {
                    return _last;
                }

            protected:
            private:
                EKey _last = UNKNOWN;
        };

    }
}

#endif /* !KEY_HPP_ */
