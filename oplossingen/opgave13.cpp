#include <iostream>
#include <cstdio>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
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

    //Fastfeature detector
    FastFeatureDetector ffd;
    vector<KeyPoint> keyP1;
    ffd.detect(img1, keyP1);
    vector<KeyPoint> keyP2;
    ffd.detect(img2, keyP2);

    BriefDescriptorExtractor bde;
    Mat descript1;
    bde.compute(img1, keyP1, descript1);
    Mat descript2;
    bde.compute(img2, keyP2, descript2);

    BFMatcher bfm;
    vector<vector<DMatch> > matches;
    bfm.knnMatch(descript1, descript2, matches,32);

    Mat result;
    drawMatches(img1, keyP1, img2, keyP2, matches, result);

    /// Show what you got
    namedWindow("img1", 1);
    imshow( "img1", result );
    /*namedWindow("img2", 1);
    imshow( "img2", img2 );chr*/


    waitKey(0);
    return 0;
}