#include <SDL3/SDL.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 640;
const float TRIANGLE_SIZE = 200.0f;

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	SDL_CreateWindowAndRenderer("Hello, I am a Triangle!", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

	SDL_Vertex verticies[3];	
	SDL_zeroa(verticies);
	verticies[0].position.x = static_cast<float>(WINDOW_WIDTH / 2.0f);
	verticies[0].position.y = (static_cast<float>(WINDOW_HEIGHT) - TRIANGLE_SIZE) / 2.0f;
	verticies[0].color.r = 1.0f;
	verticies[0].color.g = 1.0f;

	
	verticies[1].position.x = (static_cast<float>(WINDOW_WIDTH) + TRIANGLE_SIZE) / 2.0f; 
	verticies[1].position.y = (static_cast<float>(WINDOW_HEIGHT) + TRIANGLE_SIZE) / 2.0f;
	verticies[1].color.g = 1.0f;
	verticies[1].color.b = 1.0f;


	verticies[2].position.x = (static_cast<float>(WINDOW_WIDTH) - TRIANGLE_SIZE) / 2.0f; 
	verticies[2].position.y = (static_cast<float>(WINDOW_HEIGHT) + TRIANGLE_SIZE) / 2.0f;
	verticies[2].color.b = 1.0f;
	verticies[2].color.r = 1.0f;

	SDL_RenderGeometry(renderer, NULL, verticies, 3, NULL, 0);
	SDL_RenderPresent(renderer);
	
	bool running = true;
	SDL_Event event;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}
	}


	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}
