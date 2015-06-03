/// NewsRobot.cpp: определяет экспортированные функции для приложения DLL.
/// NewsRobot - новостной советник. Для анализа реакции рынка на новости по всем валютам.
/// ver. t.1.0  - версия предназначенная для теста. Запускается по OnInit() mql5 один раз в начале
///				далее загружает весь каллендарь и по условиям формирует массив с датами и решениями,
///             после отдает его весь сразу mql5. Далее находится в режиме получения данных и только
///             после сделок получает результаты для дат. В конце формирует отчет. Входные параметры 
///             задаются через mql5 для возможности их оптимизации.

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
