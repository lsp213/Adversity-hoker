#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiFileTest.h"
class QtGuiFileTest : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiFileTest(QWidget *parent = Q_NULLPTR);
public slots:
	void OpenDataFile(bool);
	void FreAnalysis(bool);
	void AddNoise(bool);
	void Filtering(bool);

private:
	Ui::QtGuiFileTestClass ui;
	uint16_t datalen;
	int datadtype;
	int flag;
	int noise_flag;
	uint32_t uint_database[4096];
	int32_t int_database[4096];
	float float_database[4096];
	double dataBuf[4096]; //数据缓冲区
	uint16_t freq; //信号频率
	uint16_t sampleRate; //采样频率
	uint16_t mag; //信号幅度
	void read_config(void);
protected:
	//Event handler
	void paintEvent(QPaintEvent* event);//重载绘图事件
	void resizeEvent(QResizeEvent* event);
};
