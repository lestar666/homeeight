
#include <iostream>
#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat dst;
	Mat src = imread("lena.jpg", 1);

	double angle = -10.0;
	double scale = 1;

	Point2f center(src.cols / 2.0, src.rows / 2.0);
	Mat rot =getRotationMatrix2D(center, angle, scale);

	Rect bbox = RotatedRect(center, src.size(), angle).boundingRect();

	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	warpAffine(src, dst, rot, bbox.size());

	imshow("src", src);
	imshow("dst", dst);
	
	waitKey(0);
	return 0;
}

