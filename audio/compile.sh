#gcc -O3 -std=c89 -pedantic -Wall -Wextra -Wconversion -Werror -fsanitize=address main.c -o main -lpthread
gcc -O3 -std=c99 -pedantic -Wall -Wextra -Wconversion -Werror -I./include -Wl,-rpath=./lib -L./lib main.c -o main -lpthread -lraylib
