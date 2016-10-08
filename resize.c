/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    if (n < 0 || n > 100)
    {
        printf("Rescaling value is out of range. "); 
        return 1; 
    }
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    BITMAPINFOHEADER bInfoHdr2; 
    BITMAPFILEHEADER bFHdr2; 
    
    bInfoHdr2 = bi; 
    bFHdr2 = bf; 
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //int origWidth = bi.biWidth; 
    
    bInfoHdr2.biWidth = bi.biWidth * n; 
    bInfoHdr2.biHeight = bi.biHeight * n; 
    
    int padding2 = (4 - (bInfoHdr2.biWidth * 3) % 4) % 4; 


    //bInfoHdr2.biSizeImage = (bInfoHdr2.biWidth + padding2) * abs(bInfoHdr2.biHeight); 
    bInfoHdr2.biSizeImage = (bInfoHdr2.biWidth * 3 + padding2) * abs(bInfoHdr2.biHeight);
    bFHdr2.bfSize = 54 + bInfoHdr2.biSizeImage; 
    
    //Writing the output file headers 
    fwrite(&bFHdr2, sizeof(BITMAPFILEHEADER), 1, outptr); 
    fwrite(&bInfoHdr2, sizeof(BITMAPINFOHEADER), 1, outptr); 

    
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * 3) % 4) % 4;
    //int moveBack = (bi.biWidth * 3) + padding; 


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int counter2 = 0; counter2 < n; counter2++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
          
                // write RGB triple to outfile
                for (int counter = 0; counter < n; counter++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding2; k++)
            {
                fputc(0x00, outptr);
            }
            
            if (counter2 < n - 1)
            {
                fseek(inptr, -(bi.biWidth * 3 + padding), SEEK_CUR); 
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
