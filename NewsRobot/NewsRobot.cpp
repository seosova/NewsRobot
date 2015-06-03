/// NewsRobot.cpp: определяет экспортированные функции для приложения DLL.
/// NewsRobot - новостной советник. Для анализа реакции рынка на новости по всем валютам.
/// ver. t.1.0  - версия предназначенная для теста. Запускается по OnInit() mql5 один раз в начале
///				далее загружает весь каллендарь и по условиям формирует массив с датами и решениями,
///             после отдает его весь сразу mql5. Далее находится в режиме получения данных и только
///             после сделок получает результаты для дат. В конце формирует отчет. Входные параметры 
///             задаются через mql5 для возможности их оптимизации.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
class ReadCSV {
protected:
	vector<string> m_date;
public:
	void ReadRow(istream& str) {	/// взято с http://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c 
		string line;
		getline(str, line);
		stringstream lineStream(line);
		string cell;
		m_date.clear();
		while (getline(lineStream, cell, '\t'))
		{
			m_date.push_back(cell);
		}
	}
	size_t size() const {
		return m_date.size();
	}
	string const& operator[](size_t index) const {
		return m_date[index];
	}


};

istream& operator>>(istream& str, ReadCSV& date)
{
	date.ReadRow(str);
	return str;
}
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
	void SetDateYear(int c_date_year) { m_date_day = c_date_year; }
	void SetDateMonth(int c_date_month) { m_date_month = c_date_month; }
	void SetDateDay(int c_date_day) { m_date_day = c_date_day; }
	void SetDateHour(int c_date_hour) { m_date_hour = c_date_hour; }
	void SetDateMinute(int c_date_minute) { m_date_minute = c_date_minute; }
	void SetCurrency(char* c_currency) { m_currency = c_currency; }
	void SetDescription(char* c_description) { m_description = c_description; }
	void SetImpact(char* c_impact) { m_impact = c_impact; }
	void SetActual(char* c_actual) { m_actual = c_actual; }
	void SetForecast(char* c_forecast) { m_forecast = c_forecast; }
	void SetPrevious(char* c_previous) { m_previous = c_previous; }
};

class RobotControll {
protected:
	char* m_input_news_file = 0;
	char m_input_statistic_file = 0;
//	News m_current_news;

public:
	void SetNewsFile(char* c_input_news_file) { c_input_news_file = m_input_news_file; }
	void SetStatisticFile(char c_input_statistic_file) { c_input_statistic_file = m_input_statistic_file; }

	void ReadNewsFile();
};

void RobotControll::ReadNewsFile() {
	ifstream	file(m_input_news_file);
	ReadCSV Row;
	while (file >> Row)
	{
		cout << "4th Element(" << Row[3] << ")\n";
	}
}

int main() {
	RobotControll GrandControll;
	GrandControll.SetNewsFile("News_2007_2015.csv");
	GrandControll.ReadNewsFile();

	return 0;
}

