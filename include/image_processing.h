#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

image generate_frame_seed(int width, int height, image seed);
image delete_edge_cell(image fichier, image output);
image reverse (image fichier, image reversed);
image hole_plugging(image fichier, image output);
image manual_erosion(image fichier , int rep);

#endif
