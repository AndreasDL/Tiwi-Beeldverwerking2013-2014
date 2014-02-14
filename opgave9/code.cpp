#include <iostream>
#include <cstdio>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

struct data{
    int count;
    Point2f src[4];
    Point2f dst[4];
    Mat* img;
};
void transformer(int event, int x, int y, int flags, void* d);

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

    //Create a window
    namedWindow("My Window", 1);

    //set the callback function for any mouse event
    data d;
    d.count = 0;
    d.img = &img;
    setMouseCallback("My Window", transformer, &d);

    //show the image
    imshow("My Window", img);
    // Wait until user press some key
    waitKey(0);waitKey(0);

    return 0;
}

void transformer(int event, int x, int y, int flags, void* d){
    data* dat = (data*) d;
    if  ( event == EVENT_LBUTTONDOWN ){
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;

        if (dat->count < 4){
            dat->src[dat->count]=Point2f(x,y);
            dat->count++;
        }else{
            dat->dst[dat->count-4]=Point2f(x,y);
            dat->count++;
        }

        if(dat->count == 8){
            //http://stackoverflow.com/questions/10125432/recognizing-rectangular-area-in-an-image
            Mat kernel = getPerspectiveTransform(dat->src,dat->dst);
            
            //vervormen
            Mat tmp;
            warpPerspective(*dat->img,tmp,kernel,(*dat->img).size());

            //show
            namedWindow("warp",1);
            imshow("warp",tmp);
            waitKey(0);
        }
    }
}