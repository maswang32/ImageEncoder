/* Mason Wang, masonwang */
/* CS152, Winter 2019 */
/* hw4 */

#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"
#include "hw4_provided.h"





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
void hide_image(unsigned int ref_r[ROWS][COLS],
	unsigned int ref_g[ROWS][COLS],
	unsigned int ref_b[ROWS][COLS],
	unsigned int hid_r[ROWS][COLS],
	unsigned int hid_g[ROWS][COLS],
	unsigned int hid_b[ROWS][COLS],
	unsigned int res_r[ROWS][COLS],
	unsigned int res_g[ROWS][COLS],
	unsigned int res_b[ROWS][COLS],
	unsigned int height, unsigned int width)
{
    //error if height or width exceeds rows/cols
    if((height>ROWS)||(width>COLS))
    {
        fprintf(stderr, "error hide_image: size invalid");
        return;
    }
    int r;
    //goes through all the rows of red matrix
    for(r =0; r<height; r++)
    {
        int c;
	//goes through all the items of red matrix
        for(c=0; c<width; c++)
        {
	    //checks if hidden is greater than 128, then adjusts
            if(hid_r[r][c] >= 128)
            {
		//if ref is even, make it odd
                if((ref_r[r][c]%2)==0)
                {
			res_r[r][c] = ref_r[r][c]+1;
                }
		//do nothing if not
		else
		{
			res_r[r][c] = ref_r[r][c];
		}
            }
            //if it's smaller than 128...
            else
            {
		//if ref is odd, make it even
                if((ref_r[r][c]%2) ==1)
                {
                    res_r[r][c] = ref_r[r][c] - 1;
                }
		//do nothing if not
		else
		{
			res_r[r][c] = ref_r[r][c];
		}
            }

	    //if hid green is greater than 128, make sure it's odd
            if(hid_g[r][c] >= 128)
            {
		//if it's even add one, to make it odd
                if((ref_g[r][c]%2)==0)
                {
                    res_g[r][c] = ref_g[r][c]+1;
                }
		//don't change ref if it's already odd
		else
		{
			res_g[r][c] = ref_g[r][c];
		}
            }
	    //if ref green is less than 128...
            else
            {
		//and if it's odd, make it even
                if((ref_g[r][c]%2) ==1)
                {
                    res_g[r][c] = ref_g[r][c] - 1;
                }
		//if it's even, keep it even
		else
		{
			res_g[r][c] = ref_g[r][c];
		}
            }


	    //if blue of hid is greater than 128
            if(hid_b[r][c] >= 128)
            {
		//and if ref is even, make it odd
                if((ref_b[r][c]%2)==0)
                {
                    res_b[r][c] = ref_b[r][c]+1;
                }
		//otherwise, keep it the same as ref
		else
		{
			res_b[r][c] = ref_b[r][c];
		}
            }
	    //if hid blue is less than 128
            else
            {
		//AND if ref isn't even, then make it even
                if((ref_b[r][c]%2) ==1)
                {
                    res_b[r][c] = ref_b[r][c] - 1;
                }
		//otherwise, keep res the same as ref
		else
		{
			res_b[r][c] = ref_b[r][c];
		}
            }
        }
    }
}





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
	unsigned int height, unsigned int width)
{
    //error if the size is too big
    if((height>ROWS)||(width>COLS))
    {
        fprintf(stderr, "error extract_image: size invalid");
        return;
    }

    int r;
    //goes through rows of the res image
    for(r=0; r<height; r++)
    {
        int c;
	//goes through each element in the res image
        for(c=0; c<width; c++)
        {
	    //if res is even, set hid_red to zero
            if((res_r[r][c]%2)==0)
            {
                hid_r[r][c] = 0;
            }
	    //otherwise, set it to 255
            else
            {
                hid_r[r][c] = 255;
            }

            //if res is even, set hid to zero
            if((res_g[r][c]%2)==0)
            {
                hid_g[r][c] = 0;
            }
	    //otherwise, set it to 255
            else
            {
                hid_g[r][c] = 255;
            }


	    //if res pixel blue is even set hid to zero
            if((res_b[r][c]%2)==0)
            {
                hid_b[r][c] = 0;
            }
	    //otherwise, set it to 255
            else
            {
                hid_b[r][c] = 255;
            }
        }
    }
}


/* encode
 * hides a picture
 * inputs -
 * 	*ref_filename --- place of reference image
 *  *hid_filename --- place of hidden image
 *  *enc_filename --- place to encode the image
 * outputs --- void
*/
void encode(char *ref_filename, char *hid_filename, char *enc_filename)
{
    unsigned int ref_r[ROWS][COLS];
	unsigned int ref_g[ROWS][COLS];
	unsigned int ref_b[ROWS][COLS];
	unsigned int hid_r[ROWS][COLS];
	unsigned int hid_g[ROWS][COLS];
	unsigned int hid_b[ROWS][COLS];
	unsigned int res_r[ROWS][COLS];
	unsigned int res_g[ROWS][COLS];
	unsigned int res_b[ROWS][COLS];
	unsigned int width;
	unsigned int height;
	unsigned int width1;
	unsigned int height1;

    provided_read_png(ref_filename, ref_r, ref_g, ref_b, &width, &height);
    provided_read_png(hid_filename, hid_r, hid_g, hid_b, &width1, &height1);
    //error if images aren't the same size
    if(!((width1 == width)&&(height1 == height)))
    {
        fprintf(stderr, "error encode: images must be the same size");
        return;
    }
    hide_image(ref_r, ref_g, ref_b, hid_r, hid_g, hid_b, res_r, res_g, res_b,
    height, width);
    provided_write_png(enc_filename, res_r, res_g, res_b, width, height);
}

/* decode
 * reveals a picture
 * inputs -
 *      *hid_filename --- extracted image
 *      *enc_filename --- encoded image
 * outputs --- void
*/
void decode(char *enc_filename, char *hid_filename)
{
	unsigned int hid_r[ROWS][COLS];
	unsigned int hid_g[ROWS][COLS];
	unsigned int hid_b[ROWS][COLS];
	unsigned int res_r[ROWS][COLS];
	unsigned int res_g[ROWS][COLS];
	unsigned int res_b[ROWS][COLS];
	unsigned int width;
	unsigned int height;

    provided_read_png(enc_filename, res_r, res_g, res_b, &width, &height);
    extract_image(res_r, res_g, res_b, hid_r, hid_g, hid_b, height, width);
    provided_write_png(hid_filename, hid_r, hid_g, hid_b, width, height);
}




