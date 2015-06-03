/// NewsRobot.cpp: ���������� ���������������� ������� ��� ���������� DLL.
/// NewsRobot - ��������� ��������. ��� ������� ������� ����� �� ������� �� ���� �������.
/// ver. t.1.0  - ������ ��������������� ��� �����. ����������� �� OnInit() mql5 ���� ��� � ������
///				����� ��������� ���� ���������� � �� �������� ��������� ������ � ������ � ���������,
///             ����� ������ ��� ���� ����� mql5. ����� ��������� � ������ ��������� ������ � ������
///             ����� ������ �������� ���������� ��� ���. � ����� ��������� �����. ������� ��������� 
///             �������� ����� mql5 ��� ����������� �� �����������.

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

class RobotControll {
protected:
	char* m_input_news_file=0;
	char m_input_statistic_file=0;
	News m_current_news;

public:
	void SetNewsFile(char* c_input_news_file) { c_input_news_file = m_input_news_file; }
	char* ShowNewsFile() { return m_input_news_file; }
	void SetStatisticFile(char c_input_statistic_file) { c_input_statistic_file = m_input_statistic_file; }
	char ShowStatisticFile() { return m_input_statistic_file; }

	void ReadNewsFile(char* c_news_file);
};
class NewsAnalitic {

};
class News {
protected:
	int m_date_year;
	int m_date_month;
	int m_date_day;
	int m_date_hour;
	int m_date_minute;

	char* m_currency;   
	char* m_description;
	char* m_impact;
	char* m_actual;
	char* m_forecast;
	char* m_previous;

public:
	News() {}
	~News() {}
};

int main() {
	RobotControll GrandControll;
	GrandControll.SetNewsFile("News_2007_2015.csv");
	return 0;
}

void RobotControll::ReadNewsFile(char * c_news_file)
{
	ifstream infile(m_input_news_file);
	cout << "END" << endl;
}
