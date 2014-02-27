#include <iostream>
#include <cstdio>
#include "opencv/cv.h"
#include "opencv/highgui.h"
using namespace cv;
using namespace std;



int main(int argc, char** argv){
    if (argc != 3){
        cout << "usage: " << argv[0] << " <imagename1> <imagename2>" << endl;
    }
    
    // Read image from file 
    Mat img1 = imread(argv[1]);
    //if fail to read the image
    if ( img1.empty() ){
        cout << "Error loading image 1" << endl;
        return -1; 
    }
    Mat img2 = imread(argv[2]);
    if ( img2.empty() ){
        cout << "Error loading image 2" << endl;
        return -2;
    }

    //Create a window  && show first
    Mat img1_gray;
    cvtColor(img1, img1_gray, CV_BGR2GRAY);
    Mat img2_gray;
    cvtColor(img2, img2_gray, CV_BGR2GRAY);

    //goodfeatures to track
    int r = 4;
    RNG rng(12345);

    vector<Point2f> corners1;
    goodFeaturesToTrack(img1_gray, corners1, 100 , 0.01, 10);
    vector<Point2f> corners2;
    goodFeaturesToTrack(img2_gray, corners2, 100 , 0.01, 10);

    for( int i = 0; i < corners1.size(); i++ ){ 
        circle( img1, corners1[i], r, Scalar(0,0,255));
    }
    for( int i = 0; i < corners2.size(); i++ ){ 
        circle( img2, corners2[i], r, Scalar(0,0,255));
    }

    /// Show what you got
    namedWindow("img1", 1);
    imshow( "img1", img1 );
    namedWindow("img2", 1);
    imshow( "img2", img2 );


    waitKey(0);

    return 0;
}