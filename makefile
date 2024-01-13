COMP=clang
OPTIONS=-Wall -Wextra -Werror -Wno-unused-parameter -O2
DEBUG=-fsanitize=address,undefined -g3

SOURCES=creature.c lodepng.c
OUTPUT=creature
LIBS=-lglfw -lGL

final:
	${COMP} ${OPTIONS} ${LIBS} ${SOURCES} -o ${OUTPUT}

debug:
	${COMP} ${OPTIONS} ${LIBS} ${DEBUG} ${SOURCES} -o ${OUTPUT}
