# OpenGL + SIMD + C++
It's a test project. Main purpose is to play with SIMD (Single Instruction Multiple Data). I'm using [vectorclass](https://github.com/vectorclass) library for SIMD, [SFML](https://github.com/sfml/sfml) for Window creation and input handling. 
# **Using**
Use *left mouse button* to attract particles towards it. Hold *left shift* to attract them continuously.
# **Command line arguments**
`-arg_name=value`, for example `-win_w=1280 -win_h=720`.
| argument  |  description | default value |
| :-  |  :- | :- |
| win_w  | window width, has to be divisible by 4 | 800 |
| win_h  | window height | 600 |
| fps  | FPS limit | 0 (no limit) |
| alignment  | alignment of particles memory, has to be power of 2 | 32 |


# Compiling
Just open the .sln using Visual Studio 2019 and compile. Binaries will in the `_binaries` folder.

# [YouTube video](https://youtu.be/A0FwfGXOCbs)
# Screens
Just note that the coolset thing about this program is that particles move really fast. It's hard to catch the fun stuff on still images. Following screenshots were captured in a 1000x1000 window, 1 milion particles.
![](_img/ss_1.png)
![](_img/ss_2.png)
![](_img/ss_3.png)
![](_img/ss_4.png)