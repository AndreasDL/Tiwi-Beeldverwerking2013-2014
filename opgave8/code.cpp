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
    namedWindow( "normal", WINDOW_AUTOSIZE);// Create a window for display.
    imshow( "normal", image );
    //waitKey(0);

    //structuring element
    double m = -0.1;
    Mat tmp;
    Mat trans(2,3,CV_64F,0.0);
    trans.at<double>(0,0)=1;
    trans.at<double>(0,1)=m;//m
    trans.at<double>(0,2)=100;

    trans.at<double>(1,0)=0;
    trans.at<double>(1,1)=1;
    trans.at<double>(1,2)=0;

    warpAffine(image, tmp, trans, Size(500,500));
    cout<< trans << endl;


    //toon tweede
    namedWindow( "normal2", WINDOW_AUTOSIZE );// Create a window for display.
    imshow("normal2",tmp);
    waitKey(0);
    waitKey(0);
    waitKey(0);
    waitKey(0);

    
    return 0;

}
