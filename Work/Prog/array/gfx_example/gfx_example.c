#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gfx.h"

/// Render some white noise.
/// @param context graphical context to use.
static void render(struct gfx_context_t *context, int width, int height) {
	gfx_clear(context, COLOR_BLACK);

	for (int i = 0; i < width*height/10; i++) {
		int x = rand() % context->width;
		int y = rand() % context->height;
		uint32_t intensity = rand() % 256;  // 8-bit per color channel
		uint32_t color = MAKE_COLOR(intensity,intensity,intensity);
		gfx_putpixel(context, x, y, color);
	}
}

/// Program entry point.
/// @return the application status code (0 if success).
int main() {
	int width = 800, height = 600;
	struct gfx_context_t *ctxt = gfx_create("Example", width, height);
	if (!ctxt) {
		fprintf(stderr, "Graphics initialization failed!\n");
		return EXIT_FAILURE;
	}

	while (gfx_keypressed() != SDLK_ESCAPE) {
		render(ctxt, width, height);
		gfx_present(ctxt);
	}

	gfx_destroy(ctxt);
	return EXIT_SUCCESS;
}
