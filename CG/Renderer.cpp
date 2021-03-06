#include "Renderer.h"

#include "ScreenPixels.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}


//this function turns on the specified pixels on screen
void Renderer::drawPixels(const std::vector<Pixel>& pixels)
{
	int numPixels = pixels.size();

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_INT, sizeof(Pixel), &pixels[0].x);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(Pixel), &pixels[0].color);

	glDrawArrays(GL_POINTS, 0, numPixels);
}

#ifdef SCREEN_PIXELS_BUFFER_IMPLEMENT
//this function turns on the specified pixels on screen
void Renderer::drawScreenPixels(const ScreenPixels& pixels)
{
	int numPixels = pixels.size();

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, &pixels[0]);

	glDrawPixels(pixels.width(), pixels.height(), GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);
}

#else
#ifdef SCREEN_PIXELS_LIST_IMPLEMENT

//this function turns on the specified pixels on screen
void Renderer::drawScreenPixels(const ScreenPixels &pixels)
{
	int numPixels = pixels.size();

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_INT, sizeof(Pixel), &pixels[0]);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(Pixel), &pixels[0].color);

	glDrawArrays(GL_POINTS, 0, numPixels);
}

#endif // SCREEN_PIXELS_LIST_IMPLEMENT
#endif // SCREEN_PIXELS_BUFFER_IMPLEMENT