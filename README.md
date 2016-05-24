ROI Selection
================

Select bounding box and save cropped image for each image in a directory
### Clone
    git clone git@github.com:sthoduka/roi_selection.git

### Build
    cd roi_selection
    mkdir build
    cd build
    cmake ..
    make

### Run
    ./roi_selection directory/containing/images

### Usage
- To select bounding boxes for a displayed frame:
    - Click two points on the window to define the bounding box (top left, bottom right)
    - Press 'y' if you're satisfied, 'q' to quit, or any other key to redo the bounding box for the image
- Cropped images are saved in directory/containing/images/cropped
