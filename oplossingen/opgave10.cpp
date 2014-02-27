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

    //1. gaussiankernel
    const int AANTRIJ = 45;
    Mat kernel = getGaussianKernel(AANTRIJ,10.5,CV_32F);

    //2. kopieren in middenste kolom van vierkant matrix
    Mat square = Mat::zeros(AANTRIJ,AANTRIJ,CV_32F);
    Mat midden = square.col(AANTRIJ/2);
    kernel.col(0).copyTo(midden);

    //3. rijmatrix
    Mat row = getGaussianKernel(AANTRIJ,0.1,CV_32F);
    row = row.t();

    //4. filter square
    Mat gauss;
    filter2D(square,gauss,CV_32F,row);

    //5. DoGFilter
    Mat DoGFilter;
    Sobel(gauss,DoGFilter,CV_32F,1,0);

    //6. rotatie
    Point2f center(AANTRIJ/2,AANTRIJ/2);
    Mat rotMatrix = getRotationMatrix2D(center,-15,1);

    //7. roteer hondje
    Mat rotatedDoGFilter;
    warpAffine(DoGFilter,rotatedDoGFilter,rotMatrix,DoGFilter.size());
    Mat DoGFilterNormalized;
    normalize(rotatedDoGFilter,DoGFilterNormalized,0,1,NORM_MINMAX);

    //show
    imshow("hondje",DoGFilterNormalized);

    // Wait until user press some key
    waitKey(0);

    // 8. zet de afbeelding om naar grijswaarden en filter ze met het geroteerde DoG filter;
    Mat dst;
    cvtColor(img, dst, CV_RGB2GRAY);
    filter2D(dst, dst, CV_32F, rotatedDoGFilter);
    // 9. neem de absolute waarde van de filterrespons met abs;
    dst = abs(dst/512);    

    // 10. tweak de parameters van de Gaussianen en de kernelgrootte zodat je een goede orientatieselectiviteit verkrijgt;
    

    imshow("myWindow", dst);
    waitKey(0);

    return 0;
}