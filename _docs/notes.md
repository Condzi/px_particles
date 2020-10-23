# **Remove unsued OpenGL pointers**
Right now we're loading all OpenGL functions, which is unnecessary -- we're only using a few. Load only those which we need and check for OpenGL version.