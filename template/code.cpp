#include <iostream>
#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"



using namespace cv;
using namespace std;
int main(int argc, char **argv){
	if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    //amedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    //imshow( "Display window", image );                   // Show our image inside it.

    //waitKey(0);

    Mat gray_image;
    gray_image = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE); 

    Mat thresh;
    double value = 127;
	int threshold_type=3;
	double max_BINARY_value = 255;
    threshold(gray_image,thresh,value,max_BINARY_value,threshold_type);

 	namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", thresh);                   // Show our image inside it.


    imwrite( "Gray_Image.png", gray_image );
    imwrite( "Thresh_Image.png", thresh );
    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;

}
