# FOSSEE
**FOSSEE Tool Box project**

<h4>To run the program :</h4>
- Navigate to the repo folder (FOSSEE/Image_processing_toolbox)
- Make sure image.jpg is present
- execute the following code:

> gcc ipt.cpp

<h2>The program contains two functions:</h2><br>

<h3>1) imquantize():<br></h3>
- This function tries to do the work of imquantize() present in MATLAB, what it does is quantizes the image.
- It takes two arguments:
  * **input** : Contains the input image ( Mat data type)
  * **levels** : Contains the levels data (2-d vector)
- It quantizes the color of all pixels in input using levels
- It has one Output:
  * **output** : Contains the quantized image (Mat data type)

<br>

<h3>2) imfill():</h3>
- This functions tries to fill all the holes present in a binary image.<br>
- It takes only one argument:
  * **image** : Contains the input image(Binary) (Mat Data type)
- It uses **floodFill()** function to flood all the background pixels white starting from (0,0).
- Now the background and the edge of the hole is white and the hole itself is black.
- We invert this image so that the hole becomes white and rest becomes black.
- Now we add this image to input image to fill the holes.
- It has one Output:
  * **image_output** : Contains the output Binary image (Mat Data-type)
  
