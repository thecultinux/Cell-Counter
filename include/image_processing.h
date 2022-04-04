#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

image generate_frame_seed(int width, int height);
image delete_edge_cell(image fichier);
image reverse (image fichier);
image hole_plugging(image fichier);
image manual_erosion(image fichier , int rep);

#endif
