
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main()
{ 
	Mat src = imread("1.jpg");  
	Mat mid, dst;


	Canny(src, mid, 50, 200, 3);
	cvtColor(mid, dst, COLOR_GRAY2BGR);

	
	vector<Vec4i> lines;
	HoughLinesP(mid, lines, 1, CV_PI / 180, 40, 50, 10);

	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line( dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186,88,255), 1, CV_AA);
	}

	imshow("dst", dst);

	waitKey(0);

	return 0;
}
