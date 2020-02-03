warmup4: hw4_provided.c hw4_provided.h warmup4.c warmup4.h warmup4_main.c
	clang -Wall -lpng -o warmup4 hw4_provided.c warmup4.c warmup4_main.c

hw4: hw4.h hw4.c hw4_main.c hw4_provided.c hw4_provided.h
	clang -Wall -lpng -o hw4 hw4.c hw4_main.c hw4_provided.c
