#include "all.h"



//�ı�ͼ��ԱȶȺ����ȵ���
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
			}   //saturate_cast �Խ������ת����ȷ��Ϊ��Чֵ
		}
	}
}

//����ͼ����
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
	// ������ͼ����л��
	addWeighted(src1, alpha, src2,
		beta, 0.0, dst);
	// ��ʾͼ��
	imshow("Linear_Blend", dst);
}

// ͼ��ͨ���ķ�����ϲ�
///@srcImage const Mat ԭʼͼ��
///@logoImage const Mat �ں�ͼ��
///@outputImage Mat ���ͼ��
///@splitChannel int ͼ���ĳ��ͨ����0--2��
void SplitMerge(const Mat &srcImage,const Mat &logoImage,Mat &outputImage,int splitChannel)
{
	vector<Mat>channels;
	//��һ��3ͨ��ͼ��ת����3����ͨ��ͼ��
	//����ɫ��ͨ��
	split(srcImage, channels);

	// �õ�����һ��ͨ����ͼ��
	Mat ChannelImage =
		channels.at(splitChannel);

	//��ԭͼ����ɫͨ���ģ�50,50�����괦
	// ���·���һ�������logoͼ���м�Ȩ������
	// ���õ��Ļ�Ͻ���浽imageBlueChannel��
	addWeighted(ChannelImage(
		Rect(50, 50, logoImage.cols,
			logoImage.rows)), 1.0, logoImage,
		0.9, 0, ChannelImage(Rect(50, 50,
			logoImage.cols, logoImage.rows)));

	// ��������ͨ�����ºϲ���һ����ͨ��
	merge(channels, outputImage);
}

//ֱ�����
Mat line_fit() {
	cv::Mat image = cv::Mat::zeros(480, 640, CV_8UC3);

	//������ϵ�
	std::vector<cv::Point> points;
	points.push_back(cv::Point(48, 58));
	points.push_back(cv::Point(105, 98));
	points.push_back(cv::Point(155, 160));
	points.push_back(cv::Point(212, 220));
	points.push_back(cv::Point(248, 260));
	points.push_back(cv::Point(320, 300));
	points.push_back(cv::Point(350, 360));
	points.push_back(cv::Point(412, 400));

	//����ϵ���Ƶ��հ�ͼ��
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

	//��ȡ��бʽ�ĵ��б��
	cv::Point point0;
	point0.x = line_para[2];
	point0.y = line_para[3];

	double k = line_para[1] / line_para[0];

	//����ֱ�ߵĶ˵�(y = k(x - x0) + y0)
	cv::Point point1, point2;
	point1.x = 0;
	point1.y = k * (0 - point0.x) + point0.y;
	point2.x = 640;
	point2.y = k * (640 - point0.x) + point0.y;

	cv::line(image, point1, point2,
		cv::Scalar(0, 255, 0), 2, 8, 0);

	return image;
}