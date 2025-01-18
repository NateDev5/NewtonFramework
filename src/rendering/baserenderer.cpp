//
// Created by nate on 1/18/25.
//

#include "baserenderer.h"

#include <glad/glad.h>

void NewtonFramework::BaseRenderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}
