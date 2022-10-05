/*
** EPITECH PROJECT, 2022
** engine
** File description:
** KapEngineUi
*/

#ifndef INCLUDES_KAPENGINEUI_HPP_
#define INCLUDES_KAPENGINEUI_HPP_

namespace KapEngine {
    namespace UI {
        class Text;
        class Image;
        class Canvas;
        class UiFactory;
    }
}

#ifndef UI_FACTORY_HPP_
    #include "Legacy/UI/Factory/UiFactory.hpp"
#endif

#ifndef UICANVAS_HPP_
    #include "Legacy/UI/Canvas/UiCanvas.hpp"
#endif

#ifndef UIIMAGE_HPP_
    #include "Legacy/UI/Image/UiImage.hpp"
#endif

#ifndef UITEXT_HPP_
    #include "Legacy/UI/Text/UiText.hpp"
#endif

#endif /* !INCLUDES_KAPENGINEUI_HPP_ */
