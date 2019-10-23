#include "all.h"



//改变图像对比度和亮度调整
void ChangeGain(Mat &src, Mat &des, float a, int b)
{
	//g(r,c) = a*f(r,c) + b
	des.create(src.rows, src.cols, src.type());
	for (int r = 0; r < src.rows; r++)
	{
		for (int c = 0; c < src.cols; c++)
		{
			for (int i = 0; i < 3; i++)
			{
				des.at<Vec3b>(r, c)[i] =
					saturate_cast<uchar>(a * src.at<Vec3b>(r, c)[i] + b);
			}   //saturate_cast 对结果进行转换，确保为有效值
		}
	}
}

//两幅图像混合
void on_trackbar(int, void*)
{   
	const int alpha_slider_max = 100;
	int alpha_slider=0;
	double alpha;
	double beta;
	Mat src1;
	Mat src2;
	Mat dst;

	alpha = (double)alpha_slider \
		/ alpha_slider_max;
	beta = (1.0 - alpha);
	// 对两幅图像进行混合
	addWeighted(src1, alpha, src2,
		beta, 0.0, dst);
	// 显示图像
	imshow("Linear_Blend", dst);
}

// 图像通道的分离与合并
///@srcImage const Mat 原始图像
///@logoImage const Mat 融合图像
///@outputImage Mat 输出图像
///@splitChannel int 图像的某个通道（0--2）
void SplitMerge(const Mat &srcImage,const Mat &logoImage,Mat &outputImage,int splitChannel)
{
	vector<Mat>channels;
	//把一个3通道图像转换成3个单通道图像
	//分离色彩通道
	split(srcImage, channels);

	// 得到其中一个通道的图像
	Mat ChannelImage =
		channels.at(splitChannel);

	//将原图的蓝色通道的（50,50）坐标处
	// 右下方的一块区域和logo图进行加权操作，
	// 将得到的混合结果存到imageBlueChannel中
	addWeighted(ChannelImage(
		Rect(50, 50, logoImage.cols,
			logoImage.rows)), 1.0, logoImage,
		0.9, 0, ChannelImage(Rect(50, 50,
			logoImage.cols, logoImage.rows)));

	// 将三个单通道重新合并成一个三通道
	merge(channels, outputImage);
}

//直线拟合
Mat line_fit() {
	cv::Mat image = cv::Mat::zeros(480, 640, CV_8UC3);

	//输入拟合点
	std::vector<cv::Point> points;
	points.push_back(cv::Point(48, 58));
	points.push_back(cv::Point(105, 98));
	points.push_back(cv::Point(155, 160));
	points.push_back(cv::Point(212, 220));
	points.push_back(cv::Point(248, 260));
	points.push_back(cv::Point(320, 300));
	points.push_back(cv::Point(350, 360));
	points.push_back(cv::Point(412, 400));

	//将拟合点绘制到空白图上
	for (int i = 0; i < points.size(); i++)
	{
		cv::circle(image, points[i],
			5, cv::Scalar(0, 0, 255), 2, 8, 0);
	}

	cv::Vec4f line_para;
	cv::fitLine(points, line_para,
		cv::DIST_L2, 0, 1e-2, 1e-2);

	std::cout << "line_para = "
		<< line_para << std::endl;

	//获取点斜式的点和斜率
	cv::Point point0;
	point0.x = line_para[2];
	point0.y = line_para[3];

	double k = line_para[1] / line_para[0];

	//计算直线的端点(y = k(x - x0) + y0)
	cv::Point point1, point2;
	point1.x = 0;
	point1.y = k * (0 - point0.x) + point0.y;
	point2.x = 640;
	point2.y = k * (640 - point0.x) + point0.y;

	cv::line(image, point1, point2,
		cv::Scalar(0, 255, 0), 2, 8, 0);

	return image;
}