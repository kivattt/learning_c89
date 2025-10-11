#gcc -O3 -std=c89 -pedantic -Wall -Wextra -Wconversion -Werror -fsanitize=address main.c -o main -lpthread
gcc -O3 -std=c99 -pedantic -Wall -Wextra -Wconversion -Werror -I./raylib/include -L./raylib/lib main.c -o main -lpthread -lraylib
