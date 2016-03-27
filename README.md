# FOSSEE
FOSSEE Tool Box project

The program contains two functions
  1) imquantize():
        This function tries to do the work of imquantize() present in MATLAB, what it does is quantizes the image.
        It takes two arguments:
          -> input : Contains the input image ( Mat data type)
          -> levels : Contains the levels data (2-d vector)
        It quantizes the color of all pixels in input using levels
        It has one Output:
          -> output : Contains the quantized image (Mat data type)
  
  2) imfill():
        This functions tries to fill all the holes present in a binary image.
        It takes only one argument:
        -> image : Contains the input image(Binary) (Mat Data type)
        It uses floodFill() function to flood all the background pixels white starting from (0,0).
        Now the background and the edge of the hole is white and the hole itself is black.
        We invert this image so that the hole becomes white and rest becomes black.
        Now we add this image to input image to fill the holes.
        It has one Output:
          -> image_output : Contains the output Binary image (Mat Data-type)
  
