#ifndef IMG_H
#define IMG_H

#include "initialize.h"






/*
 * Dve strukture koje opisuju strukturu dva zaglavlja
 * kojima pocinje svaka slika u bmp formatu.
 */

// structures which represent structure of BMP file

typedef struct {                    // BMP file header structure
  unsigned short type;              // Magic number for file
  unsigned int size;                // Size of file
  unsigned short reserved1;         // Reserved
  unsigned short reserved2;         // Reserved
  unsigned int offsetbits;          // Offset to bitmap data
} BITMAPFILEHEADER;

typedef struct {                    // BMP file info structure
  unsigned int size;                // Size of info header
  unsigned int width;               // Width of image
  unsigned int height;              // Height of image
  unsigned short planes;            // Number of color planes
  unsigned short bitcount;          // Number of bits per pixel
  unsigned int compression;         // Type of compression to use
  unsigned int sizeimage;           // Size of image data
  int xpelspermeter;                // X pixels per meter
  int ypelspermeter;                // Y pixels per meter
  unsigned int colorsused;          // Number of colors used
  unsigned int colorsimportant;     // Number of important colors 
} BITMAPINFOHEADER;






/* Struktura za smestanje podataka o slici. */
// structure which represents image info data
typedef struct Image {
  int width, height; /* Dimenzije slike. */
  char *pixels; /* Niz u kojem se cuvaju podaci za sve piksele u obliku (R, G, B). */
} Image;

/* Funkcija koja inicijalizuje strukturu i vraca pokazivac na nju. */
// function which initializes image structure
Image *imageInit(int width, int height);

/*
 * Funkcija koja oslobadja prostor u kojem su se cuvali
 * podaci o slici.
 */
// function which frees allocated space for image structure
void imageDone(Image *image);

/*
 * Funkcija za ucitavanje podataka o slici koja se nalazi
 * u fajlu cije je ime filename u strukturu na koju pokazuje
 * image.
 */
// function which loads image data info
void imageRead(Image *image, char *filename);












#endif