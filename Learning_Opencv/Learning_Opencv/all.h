#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>   
using namespace cv; 
using namespace std;
 
//����ͼ��
// void imread(const String& filename, int flags = IMREAD_COLOR);

 //��ʾͼ��
// void imshow(const String& winname, InputArray mat);

 //�ȴ����̰��£���ʱ����
// int waitKey(int delay = 0);

 //��ͼƬ���浽������
// void imwrite(const String& filename, InputArray img,const std::vector<int>& params = std::vector<int>());
 
//ͼ���ϣ���������ͼ��ļ�Ȩ��
// void addWeighted(InputArray src1,double alpha, InputArray src2,double beta, double gamma, OutputArray dst, int dtype = -1);
 
//����һ�����Ե�����ֵ�Ĺ켣���������ӵ�ָ���Ĵ�����
 //int createTrackbar(const String& trackbarname, const String& winname,int* value, int count, TrackbarCallback onChange = 0, void* userdata = 0);

 //��Ĥmask  ��ֵͼ����ά���� ����ѡ����ͼ��ͼ�λ����壬�Դ����ͼ��ȫ����ֲ��������ڵ���������ͼ���������������

 //��ͨ�����������ɼ�����ͨ��������
 //void split(const Mat& src, Mat*mvbegin);
 //void split(InputArray m, OutputArrayOfArrays mv);

 //�����������Ϻϳ�һ����ͨ��������
// void merge(const Mat* mv, size_tcount, OutputArray dst);
//void merge(InputArrayOfArrays mv, OutputArray dst);

//����ͼ������ ָ�����
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

//at ����  mat.at<Vec3b>(row,col)[c]
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

//����������
//auto it = mat.begin<Vec3b>();
//auto it_end = mat.end<Vec3b>();
//for (; it != it_end; it++)
//{
//	(*it).val[0] = 0;   //B
//	(*it).val[1] = 0;   //G
//	(*it).val[2] = 255; //R
//}

//�ı�ͼ��ԱȶȺ����ȵ���
void ChangeGain(Mat &src, Mat &des, float a, int b);

//ֱ�����
void fitLine(InputArray points, OutputArray line, int distType, double param, double reps, double aeps);
	// ������㼯��һ��Ϊ��ά�����vector�㼯��,����㼯��һ���Ƿ�����������һ�������ֱ���ϵĵ㣩,��Vec4f��2d)��Vec6f(3d)��vector��,��������,�������,����ľ��Ȳ���
   // �ǶȾ��Ȳ��� 

   //����ͼ����
void on_trackbar(int, void*);

//ͼ���ͨ��������ϲ���
void SplitMerge(const Mat &srcImage,
	const Mat &logoImage,
	Mat &outputImage,
	int splitChannel);

//ֱ�����
Mat line_fit();

//�����˲�



