#include "all.h"

//core ���������������
//imgproc ���Ժͷ�����ͼ���˲������α任�������͸��Ť������ɫ�ռ�ת����ֱ��ͼ
//video ��Ƶ����ģ�飬�˶�����  �������
//calib3d ���У׼  3D�ؽ�
//feature2d 2D������ܣ������������������ ������ƥ����
//objectect ���Ԥ������Ķ����ʵ��  �沿  �� ����
//highui ʹ�õļ�UI���ܽ���
//I/O  ��Ƶ�������Ƶ�������ӿ�




const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;
Mat src1, src2, src3, dst12,image;
//����ͼ��Ļ��
static void on_trackbar(int, void*)
{
	alpha = (double)alpha_slider \
		/ alpha_slider_max;
	beta = (1.0 - alpha);
	// ������ͼ����л��
	addWeighted(src1, alpha, src2,
		beta, 0.0, dst12);
	// ��ʾͼ��
	imshow("Linear Blend", dst12);
}

int main()
{
	
	src1 = imread("./InputImg/image1.bmp", IMREAD_ANYDEPTH | IMREAD_ANYCOLOR);
	src2 = imread("./InputImg/image2.bmp", IMREAD_ANYDEPTH | IMREAD_ANYCOLOR);
	//imshow("src1", src1);
	//imshow("src2", src2);

	src3 = imread("./InputImg/image1.png", IMREAD_ANYDEPTH | IMREAD_ANYCOLOR);
	std::vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);  //ѡ��png
	compression_params.push_back(9); //�����������Ҫ��ͼƬ����

	imwrite("./OutputImg/img.tif", src3, compression_params);


	
	//alpha_slider = 0;
	//namedWindow("Linear Blend",
	//	WINDOW_AUTOSIZE);
	//char TrackbarName[50];
	//// ������������
	//sprintf_s(TrackbarName,
	//	"Alpha x %d", alpha_slider_max);
	//// ����һ��������
	//createTrackbar(TrackbarName,
	//	"Linear Blend",
	//	&alpha_slider, alpha_slider_max,
	//	on_trackbar);
	//// �������¼�
	//on_trackbar(alpha_slider, 0);


	//Mat imageROI = src1(Rect(50, 50,src2.cols,src2.rows));
	////��3��������ģ�������ǻҶ�ͼ��
	//Mat mask = imread("./InputImg/image2.png", 0);
	////��4������Ĥ������ROI
	//src1.copyTo(imageROI, mask);
	////��5����ʾ���
	//namedWindow("Display");
	//imshow("Display", src1);

	//double alphaValue = 0.5;
	//double betaValue;
 //   Mat imageROI_1 = image(Rect(50, 50, src2.cols, src2.rows));
	////��2����ͼ���ϼ�Ȩ����
	//betaValue = (1.0 - alphaValue);
	//addWeighted(imageROI_1, alphaValue,
	//	src2, betaValue, 0.0, imageROI_1);
	////��3����������ʾԭͼ����
	//namedWindow("Ч��ͼ", 1);
	//imshow("Ч��ͼ", image);

	//Mat outputImage1,outputImage2,outputImage3;

	//SplitMerge(src1, src2,outputImage1, 0);
	//// ��ʾЧ��ͼ
	//namedWindow("B");
	//imshow("B", outputImage1);
	//SplitMerge(src1, src2,outputImage2, 1);
	//// ��ʾЧ��ͼ
	//namedWindow("G");
	//imshow("G", outputImage2);
	//SplitMerge(src1, src2,outputImage3, 2);
	//// ��ʾЧ��ͼ
	//namedWindow("R");
	//imshow("R", outputImage3);

	line_fit();

	cv::waitKey(0);
	return 0;
}