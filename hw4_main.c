/* Mason Wang, masonwang */
/* CS152, Winter 2019 */
/* warmup4 */

#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"
#include "hw4_provided.h"

int main()
{
	unsigned int r[ROWS][COLS];

	unsigned int g[ROWS][COLS];
	
	unsigned int b[ROWS][COLS];
	unsigned int w;
	unsigned int h;


	//hiding the uchicago image in the happy face image
	printf("\n\n\nHiding the UChicago Image in the happy face image...\n");
	encode("happyface.png", "uchicago.png", "test1_encode_result.png");
	
	//makes the encode result html
	provided_read_png("test1_encode_result.png", r, g, b, &w, &h);
	provided_print_image_to_html("test1_encode_result.html", r, g, b, w, h);

	printf("Decoding test 1, the happy face encoded with uchicago.png\n");
	decode("test1_encode_result.png", "test1_decode_result.png");

	//makes the decode result html
	provided_read_png("test1_decode_result.png", r, g, b, &w, &h);
	provided_print_image_to_html("test1_decode_result.html", r, g, b, w, h);


	
	//hiding the happy face image in the uchicago image
	printf("\n\n\nHiding the happy face image in the uchicago image...\n");
	encode("uchicago.png", "happyface.png", "test2_encode_result.png");
	
	//makes the encode result html
	provided_read_png("test2_encode_result.png", r, g, b, &w, &h);
	provided_print_image_to_html("test2_encode_result.html", r, g, b, w, h);

	printf("Decoding test 2, the uchicago image encoded with happy face\n");
	decode("test2_encode_result.png", "test2_decode_result.png");

	//makes the decode result html
	provided_read_png("test2_decode_result.png", r, g, b, &w, &h);
	provided_print_image_to_html("test2_decode_result.html", r, g, b, w, h);
	

}
