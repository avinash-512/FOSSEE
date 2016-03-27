# FOSSEE
FOSSEE Tool Box project

The program contains two functions:<br>
  1) **imquantize():**<br>
        This function tries to do the work of imquantize() present in MATLAB, what it does is quantizes the image.<br>
        It takes two arguments:<br>
          -> **input** : Contains the input image ( Mat data type)<br>
          -> **levels** : Contains the levels data (2-d vector)<br>
        It quantizes the color of all pixels in input using levels<br>
        It has one Output:<br>
          -> **output** : Contains the quantized image (Mat data type)<br>
  <br>
  2) imfill():<br>
        This functions tries to fill all the holes present in a binary image.<br>
        It takes only one argument:<br>
        -> **image** : Contains the input image(Binary) (Mat Data type)<br>
        It uses floodFill() function to flood all the background pixels white starting from (0,0).<br>
        Now the background and the edge of the hole is white and the hole itself is black.<br>
        We invert this image so that the hole becomes white and rest becomes black.<br>
        Now we add this image to input image to fill the holes.<br>
        It has one Output:<br>
          -> **image_output** : Contains the output Binary image (Mat Data-type)<br>
  
To run the program :
>g++ xyz.cpp
