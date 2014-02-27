#include <iostream>
#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;


int main(int argc, char **argv){
    if (argc != 2){
        //wrong input count
        cout << "usage: " << argv[0] << " path_to_image" << endl;
        return -1;
    }else{
        Mat img;
        img = imread(argv[1],CV_LOAD_IMAGE_COLOR);

        //check if file is opened
        if (!img.data){
            cout << argv[1] << " is not a valid file path" << endl;
            return -2;
        }

//show first image (uncomment if needed)
        namedWindow( "image", WINDOW_AUTOSIZE );// Create a window for display.
        imshow( "image", img );                   // Show our image inside it.
        waitKey(0);

//grey
        cvtColor(img, img, CV_BGR2GRAY);
        imshow("image",img);
        waitKey(0);

//threshold
        double minVal, maxVal;
        minMaxLoc(img, &minVal, &maxVal); //find minimum and maximum intensities
        threshold(img,img,maxVal/2,0,THRESH_TRUNC);
        imshow("image",img);
        waitKey(0);

//write output
        imwrite("grey.png",img);
        waitKey(0);
    }

}
