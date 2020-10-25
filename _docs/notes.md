# **Pulsating**
When I was playing around with the program I noticed a nice effect. When you click in the middle of the screen in some intervals, let's say 0-1s, then nice effect is forming. Maybe add this feature as a demonstration? This migh be an additional command line argument, `-pulse_demo`.

# **Remove unsued OpenGL pointers**
Right now we're loading all OpenGL functions, which is unnecessary -- we're only using a few. Load only those which we need and check for OpenGL version.