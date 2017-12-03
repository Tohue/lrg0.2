#include "SDL.h"
#include "Graphics.h"
#include "Game.h"
#include "Input.h"
#include "Sprite.h"
#include <string>

Graphics::Graphics(int x, int y)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(x, y, SDL_WINDOW_RESIZABLE, &Window, &Renderer);
	Screen = SDL_GetWindowSurface(Window);

}

void Graphics::UpdateGraphics()
{
	SDL_UpdateWindowSurface(Window);
	//*****The renderer is unnesessary b/c we use surfaces instead of textures
	//SDL_RenderPresent(Renderer);
	
	//**The following function turns the whole screen black every tick to draw everithyng again
	SDL_FillRect(Screen, NULL, 0x000000);
	SDL_Delay(50);
}
void Graphics::ShutDownGraphics()
{
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
}



int Graphics::ToggleFullScreen()
{
	Uint32 flags = (SDL_GetWindowFlags(Window) ^ SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (SDL_SetWindowFullscreen(Window, flags) < 0) // NOTE: this takes FLAGS as the second param, NOT true/false! 
	{
		std::cout << "Toggling fullscreen mode failed: " << SDL_GetError() << std::endl;
		return -1;
	}
	int w = 640, h = 480; // TODO: UPDATE ME 
	if ((flags & SDL_WINDOW_FULLSCREEN_DESKTOP) != 0)
	{
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
		SDL_RenderSetLogicalSize(Renderer, w, h);
		return 1;
	}
	SDL_SetWindowSize(Window, w, h);
	return 0;
}







//***********Img-related***********\\


Sprite* Graphics::NewSprite(std::string* file)
{
	SDL_Surface* Surf_Loaded = NULL;
	if ((Surf_Loaded = SDL_LoadBMP(file->c_str())) == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", file, SDL_GetError());
	}
	Sprite* image = new Sprite();
	image->surface = Surf_Loaded;
	return image;
}

Sprite* Graphics::NewSprite(std::string* file, int r, int g, int b)
{
	Sprite* image = new Sprite();
	image->surface = SDL_LoadBMP(file->c_str());

	SDL_SetColorKey(image->surface, SDL_TRUE | SDL_RLEACCEL, SDL_MapRGB(image->surface->format, r, g, b));

	return image;
}

bool Graphics::DrawSprite(Sprite* img, int x, int y)
{
	if (Screen == NULL || img->surface == NULL) 
		return false;

	SDL_Rect Area;
	Area.x = x;
	Area.y = y;

	SDL_BlitSurface(img->surface, NULL, Screen, &Area);
	return true;
}

bool Graphics::DrawSprite(Sprite* img, int x, int y, int alpha)
{
	if (Screen == NULL || img->surface == NULL)
		return false;

	SDL_Rect Area;
	Area.x = x;
	Area.y = y;
	SDL_SetSurfaceBlendMode(img->surface, SDL_BLENDMODE_BLEND);
	SDL_SetSurfaceAlphaMod(img->surface, alpha);
	SDL_BlitSurface(img->surface, NULL, Screen, &Area);
	SDL_SetSurfaceBlendMode(img->surface, SDL_BLENDMODE_NONE);
	return true;
}




bool Graphics::DrawSprite(Sprite* img, int x, int y, int startX, int startY, int endX, int endY)
{
	if (Screen == NULL || img->surface == NULL) {
		return false;

	}

	SDL_Rect Area;
	Area.x = x;
	Area.y = y;

	SDL_Rect SrcArea;
	SrcArea.x = startX;
	SrcArea.y = startY;
	SrcArea.w = endX;
	SrcArea.h = endY;

	SDL_BlitSurface(img->surface, &SrcArea, Screen, &Area);
	return true;
}


bool Graphics::DrawSprite(Sprite* img, int x, int y, int startX, int startY, int endX, int endY, int alpha)
{
	if (Screen == NULL || img->surface == NULL) {
		return false;

	}

	SDL_Rect Area;
	Area.x = x;
	Area.y = y;

	SDL_Rect SrcArea;
	SrcArea.x = startX;
	SrcArea.y = startY;
	SrcArea.w = endX;
	SrcArea.h = endY;
	SDL_SetSurfaceBlendMode(img->surface, SDL_BLENDMODE_BLEND);
	SDL_SetSurfaceAlphaMod(img->surface, alpha);
	SDL_BlitSurface(img->surface, &SrcArea, Screen, &Area);
	SDL_SetSurfaceBlendMode(img->surface, SDL_BLENDMODE_NONE);
	return true;
}

