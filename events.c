
#include <SDL2/SDL.h>

void HandleEvents(){
    SDL_Event eve;
    while(SDL_PollEvent(&eve)){
        switch(eve.type){
            case SDL_QUIT:

              break;
            case SDL_KEYDOWN:

              break;
            case SDL_KEYUP:

              break;

            default:
              break;
        }
    }
}

/*void KeyDown(SDL_Event *eve){

}
*/
