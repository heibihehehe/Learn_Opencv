#include "all.h"

//core 定义基本数据类型
//imgproc 线性和非线性图像滤波，几何变换，仿射和透视扭曲，颜色空间转换，直方图
//video 视频分析模块，运动估计  对象跟踪
//calib3d 相机校准  3D重建
//feature2d 2D特征框架，特征检测器，描述符 描述符匹配器
//objectect 检测预定义类的对象和实例  面部  人 汽车
//highui 使用的简单UI功能界面
//I/O  视频捕获和视频编码器接口




const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;
Mat src1, src2, src3, dst12,image;
//两幅图像的混合
static void on_trackbar(int, void*)
{
	alpha = (double)alpha_slider \
		/ alpha_slider_max;
	beta = (1.0 - alpha);
	// 对两幅图像进行混合
	addWeighted(src1, alpha, src2,
		beta, 0.0, dst12);
	// 显示图像
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
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);  //选择png
	compression_params.push_back(9); //在这个填入你要的图片质量

	imwrite("./OutputImg/img.tif", src3, compression_params);


	
	//alpha_slider = 0;
	//namedWindow("Linear Blend",
	//	WINDOW_AUTOSIZE);
	//char TrackbarName[50];
	//// 滑动条的名字
	//sprintf_s(TrackbarName,
	//	"Alpha x %d", alpha_slider_max);
	//// 创建一个滑动条
	//createTrackbar(TrackbarName,
	//	"Linear Blend",
	//	&alpha_slider, alpha_slider_max,
	//	on_trackbar);
	//// 滑动条事件
	//on_trackbar(alpha_slider, 0);


	//Mat imageROI = src1(Rect(50, 50,src2.cols,src2.rows));
	////【3】加载掩模（必须是灰度图）
	//Mat mask = imread("./InputImg/image2.png", 0);
	////【4】将掩膜拷贝到ROI
	//src1.copyTo(imageROI, mask);
	////【5】显示结果
	//namedWindow("Display");
	//imshow("Display", src1);

	//double alphaValue = 0.5;
	//double betaValue;
 //   Mat imageROI_1 = image(Rect(50, 50, src2.cols, src2.rows));
	////【2】做图像混合加权操作
	//betaValue = (1.0 - alphaValue);
	//addWeighted(imageROI_1, alphaValue,
	//	src2, betaValue, 0.0, imageROI_1);
	////【3】创建并显示原图窗口
	//namedWindow("效果图", 1);
	//imshow("效果图", image);

	//Mat outputImage1,outputImage2,outputImage3;

	//SplitMerge(src1, src2,outputImage1, 0);
	//// 显示效果图
	//namedWindow("B");
	//imshow("B", outputImage1);
	//SplitMerge(src1, src2,outputImage2, 1);
	//// 显示效果图
	//namedWindow("G");
	//imshow("G", outputImage2);
	//SplitMerge(src1, src2,outputImage3, 2);
	//// 显示效果图
	//namedWindow("R");
	//imshow("R", outputImage3);

	line_fit();

	cv::waitKey(0);
	return 0;
}