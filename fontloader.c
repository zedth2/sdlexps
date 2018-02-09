
TTF_Font* FontInit(const char* fontpath, int ptsize){
    TTF_Font *font = TTF_OpenFont(fontpath, ptsize);
    if(NULL == font){
        printf("ERROR : Failed to load font. %s\n", TTF_GetError());
        return null;
    }

    return font;
}
