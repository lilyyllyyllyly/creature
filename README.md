this is really badly made its 3 am help me

it just spawns a bunch of windows with an image until you kill it with ctrl+c

doesnt work well on wayland because it cant position the windows on random locations but it does run fine

## Installation
- Dependencies
  * glfw (and by extension opengl)
  * [lodepng](https://lodev.org/lodepng/)

clone the repo and enter the project folder:
```
git clone https://github.com/lilyyllyyllyly/creature
cd creature
```

install `lodepng.c` and `lodepng.h` from the [lodepng website](https://lodev.org/lodepng/) and put them in the project folder

run `make`

you can then run it with `./creature filename` where `filename` is the path to a png file (has to be png, no other image formats)
