#include <stdio.h>
#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
Mat imquantize(Mat input, vector< vector<int> > levels)
{
	/* Input
			--> image : It is  the input image
			--> levels : It is a two dimension vector containing thresholds (levels)
		Output
			--> output : It is the output image with same size as input
	*/
	//Initializing Output Matrix (image)
	Mat output(input.size(), input.type(),Scalar::all(1));

	for (int x = 0; x < input.rows; x++)
	{
		for(int y = 0; y < input.cols; y++)
		{
			//check whether image is grayscale or BGR
			if(levels.size() == 1)
			{
				//image is grayscale
				for (int z = 1; z <  levels[0].size();z++)
				{
					// if pixel is lower then the lowest threshold then assign 0
					if(input.at<uchar>(x,y) <= levels[0][0])
						output.at<uchar>(x,y) = 0;
					// if pixel is higher then the highest threshold then assign 255
					else if(input.at<uchar>(x,y) > levels[0][levels[0].size() -1])
						output.at<uchar>(x,y) = 255;
					// if pixel lies b/w levels[0][z-1] and levels[0][z] then assign z*255/levels[0].size()
					else if(levels[0][z-1] < input.at<uchar>(x,y) && levels[0][z] < input.at<uchar>(x,y) )
						output.at<uchar>(x,y) = z*255/levels[0].size();
					else
						continue;
				}
			}
			else
			{
				//Applying thresholds to blue values
				for (int z = 1; z < levels[0].size();z++)
				{
					if(input.at<Vec3b>(x,y)[0] < levels[0][0])
						output.at<Vec3b>(x,y)[0] = 0;
					else if(input.at<Vec3b>(x,y)[0] >= levels[0][levels[0].size() - 1])
						output.at<Vec3b>(x,y)[0] = 255;
					else if(input.at<Vec3b>(x,y)[0] >= levels[0][z-1] and input.at<Vec3b>(x,y)[0] < levels[0][z])
						output.at<Vec3b>(x,y)[0] = z*255/levels[0].size();
					else
						continue;
				}

				//Applying thresholds to green values
				for (int z = 1; z < levels[1].size();z++)
				{
					if(input.at<Vec3b>(x,y)[1] < levels[1][0])
						output.at<Vec3b>(x,y)[1] = 0;
					else if(input.at<Vec3b>(x,y)[1] >= levels[1][levels[1].size() - 1])
						output.at<Vec3b>(x,y)[1] = 255;
					else if(input.at<Vec3b>(x,y)[1] >= levels[1][z-1] and input.at<Vec3b>(x,y)[1] < levels[1][z])
						output.at<Vec3b>(x,y)[1] = (z)*255/levels[1].size();
					else
						continue;
				}

				//Applying thresholds to rec values
				for (int z = 1; z < levels[2].size();z++)
				{
					if(input.at<Vec3b>(x,y)[2] < levels[2][0])
						output.at<Vec3b>(x,y)[2] = 0;
					else if(input.at<Vec3b>(x,y)[2] >= levels[2][levels[2].size() - 1])
						output.at<Vec3b>(x,y)[2] = 255;
					else if(input.at<Vec3b>(x,y)[2] >= levels[2][z-1] and input.at<Vec3b>(x,y)[2] < levels[2][z])
						output.at<Vec3b>(x,y)[2] = z*255/levels[2].size();
					else
						continue;
				}
			}
		}
    }
    return output;
}
Mat imfill(Mat image)
{
	/*
		Input:
			image : Input image should be binary
		Output:
			image_output : It will be a binary imagewith its holes filled
	*/
	Mat image_floodfilled,image_output,image_floodfilled_inv;
	//Copying the input image to image_flood_fill
	image_floodfilled = image.clone();
    //starting from (0,0) all the connected pixels will become white (background is white now)
	floodFill(image_floodfilled,cv::Point(0,0),Scalar(255));
    //Invert image so that the hole is white now
	bitwise_not(image_floodfilled,image_floodfilled_inv);
    // merging two images so that hole gets filled
	image_output = (image_floodfilled_inv | image );
	return image_output;
}
int main(int argc, char **argv)
{
	Mat image_input,image_threshold,image_filled,image_quantized;
	vector< vector<int> > labels;
	labels.resize(1);
	for (int i =0;i<5;i++)
		labels[i].resize(1);
	labels[0][0] = 255/2;
	image_input = cv::imread("ps.jpg",IMREAD_GRAYSCALE);
	threshold(image_input,image_threshold,220, 255, THRESH_BINARY_INV);
	image_filled = imfill(image_threshold);
	image_quantized = imquantize(image_input,labels);
    imshow("Original Image",image);
    imshow("Quantized Image",image_quantized);
    imshow("Filled Image",image_filled);
    waitKey(0);
	return 0;
}
