#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>   
using namespace cv; 
using namespace std;
 
//加载图像
// void imread(const String& filename, int flags = IMREAD_COLOR);

 //显示图像
// void imshow(const String& winname, InputArray mat);

 //等待键盘按下，延时作用
// int waitKey(int delay = 0);

 //将图片保存到磁盘中
// void imwrite(const String& filename, InputArray img,const std::vector<int>& params = std::vector<int>());
 
//图像混合，计算两幅图像的加权和
// void addWeighted(InputArray src1,double alpha, InputArray src2,double beta, double gamma, OutputArray dst, int dtype = -1);
 
//创建一个可以调整数值的轨迹条，并附加到指定的窗口上
 //int createTrackbar(const String& trackbarname, const String& winname,int* value, int count, TrackbarCallback onChange = 0, void* userdata = 0);

 //掩膜mask  多值图像或二维数组 ；用选定的图像、图形或物体，对处理的图像（全部或局部）进行遮挡，来控制图像处理的区域或处理过程

 //多通道的数组分离成几个单通道的数组
 //void split(const Mat& src, Mat*mvbegin);
 //void split(InputArray m, OutputArrayOfArrays mv);

 //将多个数组组合合成一个多通道的数组
// void merge(const Mat* mv, size_tcount, OutputArray dst);
//void merge(InputArrayOfArrays mv, OutputArray dst);

//访问图像像素 指针访问
//for (int row = 0; row < mat.rows; row++)
//{
//	for (int col = 0; col < mat.cols; col++)
//	{
//		Vec3b *c = mat.ptr<Vec3b>(row, col);
//		c->val[0] = 0;      //B
//		c->val[1] = 255;    //G
//		c->val[2] = 0;      //R
//	}
//}

//at 访问  mat.at<Vec3b>(row,col)[c]
//for (int row = 0; row < mat.rows; row++)
//{
//	for (int col = 0; col < mat.cols; col++)
//	{
//		Vec3b &m = mat.at<Vec3b>(row, col);
//		m[0] = 100;
//		m[1] = 100;
//		m[2] = 100;
//	}
//}

//迭代器访问
//auto it = mat.begin<Vec3b>();
//auto it_end = mat.end<Vec3b>();
//for (; it != it_end; it++)
//{
//	(*it).val[0] = 0;   //B
//	(*it).val[1] = 0;   //G
//	(*it).val[2] = 255; //R
//}

//改变图像对比度和亮度调整
void ChangeGain(Mat &src, Mat &des, float a, int b);

//直线拟合
void fitLine(InputArray points, OutputArray line, int distType, double param, double reps, double aeps);
	// 待输入点集（一般为二维数组或vector点集）,输出点集（一个是方向向量，另一个是拟合直线上的点）,（Vec4f（2d)或Vec6f(3d)的vector）,距离类型,距离参数,径向的精度参数
   // 角度精度参数 

   //两幅图像混合
void on_trackbar(int, void*);

//图像的通道分离与合并】
void SplitMerge(const Mat &srcImage,
	const Mat &logoImage,
	Mat &outputImage,
	int splitChannel);

//直线拟合
Mat line_fit();

//线性滤波



