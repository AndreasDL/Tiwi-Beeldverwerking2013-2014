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
    
    //toon eerste
    namedWindow( "normal", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "normal", image );
    //waitKey(0);

    //filter
    Mat diffX;//,diffY;
    Sobel(image,diffX,-1,1,0,3);
    //Sobel(image,diffY,-1,0,1);


    //toon tweede
    namedWindow( "normal2", WINDOW_AUTOSIZE );// Create a window for display.
    imshow("normal2",diffX);

    waitKey(0);
    
    return 0;

}
