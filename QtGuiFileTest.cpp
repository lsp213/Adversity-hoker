#include "QtGuiFileTest.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include<qpainter.h>
#include<cmath>
#include"Fft.h"
using namespace std;
double* s;
#define PI 3.14159265353
#pragma execution_character_set("utf-8")
QtGuiFileTest::QtGuiFileTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.openFile,SIGNAL(clicked(bool)), this, SLOT(OpenDataFile(bool)));
	connect(ui.timeFre, SIGNAL(clicked(bool)), this, SLOT(FreAnalysis(bool)));
	connect(ui.addNoise, SIGNAL(clicked(bool)), this, SLOT(AddNoise(bool)));
	connect(ui.filtering, SIGNAL(clicked(bool)), this, SLOT(Filtering(bool)));
	datalen = 0;
	datadtype = 0;
	flag = 0;
	noise_flag = 0;
}
//��ȡ�����ļ�
void QtGuiFileTest::OpenDataFile(bool)
{
	ifstream ifs;
	 string dataFileName = ".\\12_1928401038.dat";//��ָ��·���ļ�

	ifs.open(dataFileName);//��ָ�������ļ�
	if (!ifs.is_open())  return;// �ļ���ʧ��	

	string line_string;//���ַ���
	string note;//�������ݣ�һ����
	int data_num_line;//�������ݣ�ÿ��������

	//��ȡ�ļ�ͷ
	getline(ifs, line_string);
	istringstream ss(line_string);//ʹ���������ַ��������Է���õ�ÿ������

	//��ȡ�ļ�ͷ���ļ�ͷ����ʹ��һ�л�����ַ�������
	//if (line_string.length() > 0)
	{
		ss >> note;  // 20220406
		ss >> sampleRate; //������
		ss >> data_num_line; //ÿ��������
		ss >> datadtype;//��������ֵ��0��32λ�з���������1��ʾ32λ�޷���������2��ʾ������
	}

	int data_lines = 0;//������������
	//��ȡ���ݣ�һ������
	while (getline(ifs, line_string))
	{
		ss = istringstream(line_string);
		//������ȡһ���е�ÿ�����ݣ������뻺����
		for (int i = 0; i < data_num_line; i++)
		{
			switch (datadtype)
			{
			case 0:    ss >> int_database[i+data_lines*data_num_line]; break; //����32λ�з�������
			case 1:    ss >> uint_database[i + data_lines * data_num_line]; break; //����32λ�޷�������
			default:   ss >> float_database[i + data_lines * data_num_line]; break; //���両����
			}
		}
		data_lines++;
		datalen += data_num_line;
	}
	

	//�ر��ļ�
	ifs.close();//�ļ�ʹ�ý���

	//��ʾ����������
	ostringstream os;
	ui.textBrowser->clear();
	string dat;
	dat =to_string(sampleRate);
	QString str = "����Ƶ��Ϊ:";
	str = str+ QString::fromStdString(dat) + "\n";
	ui.textBrowser->insertPlainText(str);
	dat = to_string(data_num_line);
	str = "ÿ��������Ϊ:";
	str = str + QString::fromStdString(dat) + "\n";
	ui.textBrowser->insertPlainText(str);
	dat = "uint32";
	str = "��������Ϊ:";
	str = str + QString::fromStdString(dat) + "\n";
	ui.textBrowser->insertPlainText(str);
	for (int i = 0; i < datalen; i++)
	{
		switch (datadtype)
		{
		case 0:    dat = to_string(int_database[i]); break; //����32λ�з�������
		case 1:    dat = to_string(uint_database[i]); break; //����32λ�޷�������
		default:   dat = to_string(float_database[i]); break; //���両����
		}
		if ((i + 1) % data_num_line == 0)
			dat += "\n";
		else
			dat += " ";
		//os << dat <<"\n";
		ui.textBrowser->insertPlainText(QString::fromStdString(dat));
	}
	for (int i = 0; i < datalen; i++)
	{
		dataBuf[i] = uint_database[i] /60* 1.0;
	}
	update();
}


void QtGuiFileTest::FreAnalysis(bool)
{
	read_config();
	//��������
	int i,num = 0;
	string dat;
	float dT = 1.0;
	sampleRate = 1024;
	ui.textBrowser->clear();
	if (flag == 0)
	{
		flag = 1; 
		float dt = dT / sampleRate;
		for (i = 0; i < 4096; i++)
		{
			dataBuf[i] = mag /200 * sin(2 * PI * freq * i * dt);
		}

	}
	else
	{
		flag = 0;
		compx* data = new compx[1024];
		for (i = 0; i < 1024; i++)
		{
			data[i].real = dataBuf[i];
			data[i].imag = 0.0;
		}
		s = FFT(data);
		QString str = "��ҪƵ��Ϊ:\n";
		ui.textBrowser->insertPlainText(str);
		for (i = 0; i < 1024; i++)
		{
			dataBuf[i] = -1 * s[i] / 1000.0;
			if ((s[i] > 250) && (i < 500))
			{
				num = i;
				dat = to_string(num);
				dat += "\n";
				ui.textBrowser->insertPlainText(QString::fromStdString(dat));
			}
		}
		delete[] data;
	}
	update();
}


void QtGuiFileTest::AddNoise(bool)
{
	if (flag == 1)
	{
		for (int i = 0; i < 1024; i++)
		{
			dataBuf[i] = dataBuf[i] + mag / 300 * sin(8* PI * freq * i * 1 / 1024)+ mag / 300 * sin(10 * PI * freq * i * 1 / 1024);
		}
		noise_flag = 1;
	}
	else
	{
		flag = 1;
		read_config();
		for (int i= 0; i < 4096; i++)
		{
			dataBuf[i] = mag / 200 * sin(2 * PI * freq * i * 1/1024);
		}
		noise_flag = 1;
	}
	update();
}

void QtGuiFileTest::Filtering(bool)
{
	double buffer = 0.0;
	if (noise_flag == 1)
	{
		noise_flag = 0;
		for (int i = 2; i < 1024; i++)
		{
			//buffer = dataBuf[i];
			//dataBuf[i - 1] = 0.5 * dataBuf[i - 1] + (1 - 0.5) * buffer;
			dataBuf[i - 2] = 0.3 * dataBuf[i] + 0.2 * dataBuf[i-1]+0.5*dataBuf[i-2];
		}
	}
	update();
}



void QtGuiFileTest::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);

	int xaxis = 500;
	int yaxis = 350;
	painter.setPen(QColor(255, 0, 0));
	for (int i = 0; i < this->width(); i++)
	{
		painter.drawLine(QPoint(xaxis + i, yaxis + dataBuf[i] * 100), QPoint(xaxis + i + 1, yaxis + dataBuf[i + 1] * 100));
	}
}

void QtGuiFileTest::resizeEvent(QResizeEvent* event)
{
	update();
}

void QtGuiFileTest::read_config(void)
{
	ifstream ifs;
	string dataFileName = ".\\Signal.cfg";//��ָ��·���ļ�

	ifs.open(dataFileName);//��ָ�������ļ�
	if (!ifs.is_open())  return;// �ļ���ʧ��	
	string line_string;//���ַ���

	//��ȡ�ļ�ͷ
	while (getline(ifs, line_string))
	{
		if (line_string.find("1928401038") != std::string::npos)
		{
			getline(ifs, line_string);
			istringstream ss(line_string);//ʹ���������ַ��������Է���õ�ÿ������
			{
				ss >> sampleRate;
				ss >> freq;
				ss >> mag; 
			}
			break;
			cout << sampleRate << freq << mag<<endl;
		}
	}
	ifs.close();//�ļ�ʹ�ý���
}
