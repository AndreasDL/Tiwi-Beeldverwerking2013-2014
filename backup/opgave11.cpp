#include <iostream>
#include <cstdio>
#include "opencv/cv.h"
#include "opencv/highgui.h"
using namespace cv;
using namespace std;

int main(int argc, char** argv){
    if (argc != 2){
        cout << "usage: " << argv[0] << " <imagename>" << endl;
    }
    
    // Read image from file 
    Mat img = imread(argv[1]);

    //if fail to read the image
    if ( img.empty() ){
          cout << "Error loading the image" << endl;
          return -1; 
    }

    //Create a window  && show first
    namedWindow("window", 1);
    imshow("window",img);

    //Canny (afbeelding=> edges)
    Mat edges;
    Canny(img, edges, 15, 10);
    //edges.convertTo(edges,CV_8UC1);
    

    //Hough-Lines (edges=>lijntjes)
    vector<Vec2f> lines;
    HoughLines(edges, lines, 1, 0.01, 80);

    //line (tekenen)
    Mat result = img;
    for( size_t i = 0; i < lines.size(); i++ ){
        float rho = lines[i][0];
        float theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta);
        double b = sin(theta);
        double x0 = a*rho;
        double y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        line( result, pt1, pt2, Scalar(0,0,255), 1, CV_AA);
    }
    
    namedWindow("result", 1);
    imshow("result", result);
    waitKey(0);

    return 0;
}