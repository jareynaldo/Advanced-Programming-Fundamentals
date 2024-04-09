//
// Created by Jose reynaldo on 4/6/2024.
//

#ifndef IMAGE_PROCESSOR_SOURCE_H
#define IMAGE_PROCESSOR_SOURCE_H

#pragma pack(push, 1)
struct TGAHeader {
    char  idLength;
    char  colorMapType;
    char  imageType;
    short colorMapOrigin;
    short colorMapLength;
    char  colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char  bitsPerPixel;
    char  imageDescriptor;
};
#pragma pack(pop)


#endif //IMAGE_PROCESSOR_SOURCE_H
