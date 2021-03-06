﻿
#include <iostream>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("1.jpg", 1);
	Mat mid, dst;

	Canny(src, mid, 50, 200, 3);
	cvtColor(mid, dst, COLOR_GRAY2BGR);

	vector<Vec2f> lines;

	HoughLines(mid, lines, 1, CV_PI / 180, 91);


	std::vector<cv::Vec2f>::iterator it = lines.begin();
	for (; it != lines.end(); ++it) {
		float rho = (*it)[0], theta = (*it)[1];
		cv::Point pt1, pt2;
		double a = cos(theta);
		double b = sin(theta);
		double x0 = a * rho;
		double y0 = b * rho;
		pt1.x = cv::saturate_cast <int>(x0 + 1000 * (-b));
		pt1.y = cv::saturate_cast <int>(y0 + 1000 * (a));
		pt2.x = cv::saturate_cast <int>(x0 - 1000 * (-b));
		pt2.y = cv::saturate_cast <int>(y0 - 1000 * (a));
		cv::line(dst, pt1, pt2, cv::Scalar(0, 0, 255), 1, CV_AA);
	}
	imshow("src", src);
	imshow("mid", mid);
	imshow("dst", dst);


	waitKey(0);
	return 0;
}

