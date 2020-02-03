/* Mason Wang, masonwang */
/* CS152, Winter 2019 */
/* hw4 */


#ifndef HW4_H
#define HW4_H


#define ROWS 50
#define COLS 50






/* hide_image
 * hides an image in resulting image matrix
 * inputs:
 *  unsigned int ref_r[ROWS][COLS] - red matrix of reference image
 *  unsigned int ref_g[ROWS][COLS] - green matrix of reference image
 *  unsigned int ref_b[ROWS][COLS] - blue matrix of reference image
 *  unsigned int hid_r[ROWS][COLS] - red matrix of hidden image
 *  unsigned int hid_g[ROWS][COLS] - green matrix of hidden image
 *  unsigned int hid_b[ROwS][COLS] - blue matrix of hidden image
 *  unsigned int res_r[ROWS][COLS] - red matrix of resulting image
 *  unsigned int res_g[ROWS][COLS] - green matrix of resulting image
 *  unsigned int res_b[ROwS][COLS] - blue matrix of resulting image
 *  unsigned int height - height of all images
 *  unsigned int width - width of all images
 * output: res_r, res_g, res_b are output params
*/
void hide_image(
	unsigned int ref_r[ROWS][COLS],
	unsigned int ref_g[ROWS][COLS],
	unsigned int ref_b[ROWS][COLS],
	unsigned int hid_r[ROWS][COLS],
	unsigned int hid_g[ROWS][COLS],
	unsigned int hid_b[ROWS][COLS],
	unsigned int res_r[ROWS][COLS],
	unsigned int res_g[ROWS][COLS],
	unsigned int res_b[ROWS][COLS],
	unsigned int height, unsigned int width);


/* extract_image
 * the hidden image is actually the result we are outputting,
 * the resulting image is the input
 * inputs:
 *  unsigned int hid_r[ROWS][COLS] - red matrix of hidden image
 *  unsigned int hid_g[ROWS][COLS] - green matrix of hidden image
 *  unsigned int hid_b[ROwS][COLS] - blue matrix of hidden image
 *  unsigned int res_r[ROWS][COLS] - red matrix of resulting image
 *  unsigned int res_g[ROWS][COLS] - green matrix of resulting image
 *  unsigned int res_b[ROwS][COLS] - blue matrix of resulting image
 *  unsigned int height - height of all images
 *  unsigned int width - width of all images
 * output: hid_r, hid_g, hid_b are output params
*/

void extract_image(
	unsigned int res_r[ROWS][COLS],
	unsigned int res_g[ROWS][COLS],
	unsigned int res_b[ROWS][COLS],
	unsigned int hid_r[ROWS][COLS],
	unsigned int hid_g[ROWS][COLS],
	unsigned int hid_b[ROWS][COLS],
	unsigned int height, unsigned int width);


/* encode
 * hides a picture
 * inputs -
 * 	*ref_filename --- place of reference image
 *      *hid_filename --- place of hidden image
 *      *enc_filename --- place to encode the image
 * outputs --- void
*/
void encode(char *ref_filename, char *hid_filename, char *enc_filename);

/* decode
 * reveals a picture
 * inputs -
 *      *hid_filename --- extracted image
 *      *enc_filename --- encoded image
 * outputs --- void
*/
void decode(char *enc_filename, char *hid_filename);

#endif
