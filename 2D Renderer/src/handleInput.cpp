#include"../header/handleInput.hpp"

handleInput::handleInput() { 
}

void handleInput::MiddlewareHandleInput(GLFWwindow* window,int key,int scancode,int action,int mods) {

	switch (key) {
      case static_cast<int>(INPUT::A_BUTTON):
            switch (action) {
            // button press
              case static_cast<int>(INPUT::KEY_IS_PRESSED):
                LOGINFO<std::string>("A button pressed");
                break;
                //button release
              case static_cast<int>(INPUT::KEY_IS_RELEASED):
                    LOGINFO<std::string>("A button released");
                    break;
                default:
                LOGINFO<std::string>("Current key is being pressed");
            }
            break;

	 case static_cast<int>(INPUT::W_BUTTON):
        switch (action) {
            // button press
          case static_cast<int>(INPUT::KEY_IS_PRESSED):
            LOGINFO<std::string>("W button pressed");
            break;
            // button release
          case static_cast<int>(INPUT::KEY_IS_RELEASED):
            LOGINFO<std::string>("W button released");
            break;
          default:
            LOGINFO<std::string>("Current key is being pressed");
        }
        break;

      case static_cast<int>(INPUT::S_BUTTON):
           switch (action) {
               // button press
             case static_cast<int>(INPUT::KEY_IS_PRESSED):
               LOGINFO<std::string>("S button pressed");
               break;
               // button release
             case static_cast<int>(INPUT::KEY_IS_RELEASED):
               LOGINFO<std::string>("S button released");
               break;
             default:
               LOGINFO<std::string>("Current key is being pressed");
           }
           break;

      case static_cast<int>(INPUT::D_BUTTON):
        switch (action) {
            // button press
          case static_cast<int>(INPUT::KEY_IS_PRESSED):
            LOGINFO<std::string>("D button pressed");
            break;
            // button release
          case static_cast<int>(INPUT::KEY_IS_RELEASED):
            LOGINFO<std::string>("D button released");
            break;
          default:
            LOGINFO<std::string>("Current key is being pressed");
        }
        break;

      case static_cast<int>(INPUT::ARROW_UP_BUTTON):
        switch (action) {
            // button press
          case static_cast<int>(INPUT::KEY_IS_PRESSED):
            LOGINFO<std::string>("ARROW UP button pressed");
            break;
            // button release
          case static_cast<int>(INPUT::KEY_IS_RELEASED):
            LOGINFO<std::string>("ARROW UP button released");
            break;
          default:
            LOGINFO<std::string>("Current key is being pressed");
        }
        break;

       case static_cast<int>(INPUT::ARROW_DOWN_BUTTON):
        switch (action) {
            // button press
          case static_cast<int>(INPUT::KEY_IS_PRESSED):
            LOGINFO<std::string>("ARRROW DOWN button pressed");
            break;
            // button release
          case static_cast<int>(INPUT::KEY_IS_RELEASED):
            LOGINFO<std::string>("ARROW DOWN button released");
            break;
          default:
            LOGINFO<std::string>("Current key is being pressed");
        }
        break;

       case static_cast<int>(INPUT::ARROW_LEFT_BUTTON):
         switch (action) {
             // button press
           case static_cast<int>(INPUT::KEY_IS_PRESSED):
             LOGINFO<std::string>("ARROW LEFT button pressed");
             break;
             // button release
           case static_cast<int>(INPUT::KEY_IS_RELEASED):
             LOGINFO<std::string>("ARROW LEFT button released");
             break;
           default:
             LOGINFO<std::string>("Current key is being pressed");
         }
         break;

         case static_cast<int>(INPUT::ARROW_RIGHT_BUTTON):
         switch (action) {
             // button press
           case static_cast<int>(INPUT::KEY_IS_PRESSED):
             LOGINFO<std::string>("ARROW RIGHT button pressed");
             break;
             // button release
           case static_cast<int>(INPUT::KEY_IS_RELEASED):
             LOGINFO<std::string>("ARROW RIGHT button released");
             break;
           default:
             LOGINFO<std::string>("Current key is being pressed");
         }
         break;

         //will add some more custom Key input as we progress

        case static_cast<int>(INPUT::EXIT_BUTTON):
            //we will close the window when this button is pressed
           switch (action) {
               // button press
             case static_cast<int>(INPUT::KEY_IS_PRESSED):
               LOGINFO<std::string>("EXIT button pressed");
               //call function to set window to close
               glfwSetWindowShouldClose(window, GL_TRUE);
               break;
               // button release
             case static_cast<int>(INPUT::KEY_IS_RELEASED):
               LOGINFO<std::string>("EXIT button released");
               break;
             default:
               LOGINFO<std::string>("Current key is being pressed");
           }
           break;

            default:
           LOGINFO<std::string>("Another Key has been pressed");
             break;
  }

}

handleInput::~handleInput() {
	//delete resources
}