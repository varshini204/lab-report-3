#include <opencv2/opencv.hpp> //include necessary libraries
#include <iostream>

using namespace cv; //include appropriate namespaces before coding
using namespace std;

int main(int argc, char** argv){
    Mat image,threshold_red,threshold_green, threshold_blue; //define matrix variables to store images
    // Load the image
    image = imread("C:/Users/varsh/OneDrive/Desktop/construction project/OpenCV inc CodeBlocks LATEST/OpenCV Task/Images/BlueCar.bmp");

    // Threshold the image based on the BGR values
    inRange(image, Scalar(0, 0, 150), Scalar(70, 70, 255), threshold_red);    // Red threshold
    inRange(image, Scalar(0, 150, 0), Scalar(70, 255, 70), threshold_green);  // Green threshold
    inRange(image, Scalar(150, 0, 0), Scalar(240, 100, 100), threshold_blue);  // Blue threshold

    // calculate the area of each color threshold image
    double area_red = countNonZero(threshold_red);
    double area_green = countNonZero(threshold_green);
    double area_blue = countNonZero(threshold_blue);

    // Find the color with the largest area
    Scalar color;
    if (area_red > area_green && area_red > area_blue)
        color = Scalar(0, 0, 255);    // Red
    else if (area_green > area_red && area_green > area_blue)
        color = Scalar(0, 255, 0);    // Green
    else if (area_blue > area_red && area_blue > area_green)
        color = Scalar(255, 0, 0);    // Blue

    // draw a rectangle around the largest color area
    Rect rect;
    if (color == Scalar(0, 0, 255))  // red
    {
        rect = boundingRect(threshold_red);
        cout << "detected colour: red" << endl;
    }
    else if (color == Scalar(0, 255, 0))  // green
    {
        rect = boundingRect(threshold_green);
        cout << "detected colour: green" << endl;
    }
    else if (color == Scalar(255, 0, 0))  // blue
    {
        rect = boundingRect(threshold_blue);
        cout << "detected colour: blue" << endl;
    }
    rectangle(image, rect, color, 2); //draw rectangle on image
    imshow("Image", image);

    // Wait for user input
    waitKey();
    return 0;
}
