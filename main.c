#include <SDL2/SDL.h>
#include <stdbool.h>

// Constants for the game window and paddles
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int PADDLE_WIDTH = 15;
const int PADDLE_HEIGHT = 100;
const int BALL_SIZE = 15;

// Structs for paddles and ball
typedef struct {
    int x, y;
    int velY;
} Paddle;

typedef struct {
    int x, y;
    int velX, velY;
} Ball;

// Function prototypes
void initSDL(SDL_Window **window, SDL_Renderer **renderer);
void closeSDL(SDL_Window *window, SDL_Renderer *renderer);
void processInput(bool *running, Paddle *paddle);
void updateGame(Paddle *leftPaddle, Paddle *rightPaddle, Ball *ball);
void renderGame(SDL_Renderer *renderer, Paddle leftPaddle, Paddle rightPaddle, Ball ball);

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    bool running = true;

    Paddle leftPaddle = {10, WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2, 0};
    Paddle rightPaddle = {WINDOW_WIDTH - 10 - PADDLE_WIDTH, WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2, 0};
    Ball ball = {WINDOW_WIDTH / 2 - BALL_SIZE / 2, WINDOW_HEIGHT / 2 - BALL_SIZE / 2, -1, -1};

    initSDL(&window, &renderer);

    // Main game loop
    while (running) {
        processInput(&running, &leftPaddle);
        updateGame(&leftPaddle, &rightPaddle, &ball);
        renderGame(renderer, leftPaddle, rightPaddle, ball);

        // Delay to cap the frame rate
        SDL_Delay(16); // Approximately 60 frames per second
    }

    closeSDL(window, renderer);
    return 0;
}

void initSDL(SDL_Window **window, SDL_Renderer **renderer) {
    SDL_Init(SDL_INIT_VIDEO);
    *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
}

void closeSDL(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void processInput(bool *running, Paddle *paddle) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *running = false;
        }
        // Handle paddle movement input here...
    }
    // Handle continuous key press for paddle movement here...
}

void updateGame(Paddle *leftPaddle, Paddle *rightPaddle, Ball *ball) {
    // Update paddle positions, ball movement, and collision detection here...
}

void renderGame(SDL_Renderer *renderer, Paddle leftPaddle, Paddle rightPaddle, Ball ball) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(renderer);

    // Render paddles and ball here...

    // Swap the buffer
    SDL_RenderPresent(renderer);
}
