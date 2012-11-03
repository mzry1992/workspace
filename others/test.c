/**************************
filename:getpicture.c

This file comes from the internet.
How to compile this file ? Like below.

gcc -o output main.c -lX11 -ljpeg
***************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>

#include <jpeglib.h>



/***************************************************************
Write XImage data to a JPEG file

Must include <jpeglib.h>
Return value:
0 - failed
1 - success
****************************************************************/
static char err_str[256];

int JpegWriteFileFromImage(char *filename, XImage* img)
{
    FILE* fp;
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    fp = fopen(filename,"wb");
    if(fp==NULL)
    {
        memset(err_str, 0, sizeof(err_str));
        sprintf(err_str,"cannot write file %s",filename);
        printf("JpegWriteFileFromImage：%s",err_str);
        return 0;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    jpeg_stdio_dest(&cinfo,fp);
    cinfo.image_width = img->width;
    cinfo.image_height = img->height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_start_compress(&cinfo,TRUE);

    JSAMPROW row_pointer[1];/* pointer to scanline */
    unsigned char* pBuf = (unsigned char*)malloc(3*img->width);
    row_pointer[0] = pBuf;

    int i=0;
    while(cinfo.next_scanline < cinfo.image_height)
    {
        int j=0;
        for(i=0; i<img->width; i++)
        {
//memcpy(pBuf+j,img->data+cinfo.next_scanline*img->bytes_per_line+i*4,3);
            *(pBuf+j) = *(img->data+cinfo.next_scanline*img->bytes_per_line+i*4+2);
            *(pBuf+j+1) = *(img->data+cinfo.next_scanline*img->bytes_per_line+i*4+1);
            *(pBuf+j+2) = *(img->data+cinfo.next_scanline*img->bytes_per_line+i*4);
            j+=3;
        }
        jpeg_write_scanlines(&cinfo,row_pointer,1);
    }

    free(pBuf);
    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);

    fclose(fp);
    return 1;
}

/*****************************************************************
Capture a local screenshot of the desktop,
saving to the file specified by filename.
If type = 0, then write a bitmap file, else
write a JPEG file.

Return Value:
0 - fail
1 - success
******************************************************************/
int CaptureDesktop(char* filename)
{
    Window desktop;
    Display* dsp;
    XImage* img;

    int screen_width;
    int screen_height;

    dsp = XOpenDisplay(NULL);/* Connect to a local display */
    if(NULL==dsp)
    {
//sprintf(err_str,"Error:Cannot connect to local display\n");
        printf("CaptureDesktop","Cannot connect to local display");
        return 0;
    }
//desktop = RootWindow(dsp,0);/* Refer to the root window */
    if(0==desktop)
    {
//printf("cannot get root window\n");
        printf("CaptureDesktop","cannot get root window");
        return 0;
    }

    /* Retrive the width and the height of the screen */
    screen_width = DisplayWidth(dsp,0);
    screen_height = DisplayHeight(dsp,0);

    /* Get the Image of the root window */
    img = XGetImage(dsp,desktop,0,0,screen_width,screen_height,~0,ZPixmap);


    JpegWriteFileFromImage(filename,img);

    XDestroyImage(img);
    XCloseDisplay(dsp);
    return 1;
}

int main()
{
    CaptureDesktop("./screenshot.jpeg");
//CaptureDesktop("./screenshot.jpg",1);
    printf("Done.\n");
}
