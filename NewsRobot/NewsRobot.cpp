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
	vector<string> m_csv_date;
public:
	void ReadRow(istream& str) {	/// взято с http://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c 
		string line;
		getline(str, line);
		stringstream lineStream(line);
		string cell;
		m_csv_date.clear();
		while (getline(lineStream, cell, '\t'))
		{
			m_csv_date.push_back(cell);
		}
	}
	size_t size() const {
		return m_csv_date.size();
	}
	string const& operator[](size_t index) const {
		return m_csv_date[index];
	}


};

istream& operator>>(istream& str, ReadCSV& date)
{
	date.ReadRow(str);
	return str;
}
class News {
protected:
	vector<string> m_date;
	vector<string> m_currency;
	vector<string> m_description;
	vector<string> m_impact;
	vector<string> m_actual;
	vector<string> m_forecast;
	vector<string> m_previous;
public:
	News() {}
	~News() {}

	void SetDate(string c_date) { m_date.push_back(c_date); }
	void SetCurrency(string c_currency) { m_currency.push_back(c_currency); }
	void SetDescription(string c_description) { m_description.push_back(c_description); }
	void SetImpact(string c_impact) { m_impact.push_back(c_impact); }
	void SetActual(string c_actual) { m_actual.push_back(c_actual); }
	void SetForecast(string c_forecast) { m_forecast.push_back(c_forecast); }
	void SetPrevious(string c_previous) { m_previous.push_back(c_previous); }

	void ShowDate(int i) { cout << m_date[i] << endl; }
	void ShowCurrency(int i) { cout << m_currency[i] << endl; }
	void ShowDescription(int i) { cout << m_description[i] << endl; }
	void ShowImpact(int i) { cout << m_impact[i] << endl; }
	void ShowActual(int i) { cout << m_actual[i] << endl; }
	void ShowForecast(int i) { cout << m_forecast[i] << endl; }
	void ShowPrevious(int i) { cout << m_previous[i] << endl; }
};

class RobotControll {
protected:
	char* m_input_news_file = 0;
	char m_input_statistic_file = 0;
	News m_input_news;
public:
	void SetNewsFile(char* c_input_news_file) { c_input_news_file = m_input_news_file; }
	void SetStatisticFile(char c_input_statistic_file) { c_input_statistic_file = m_input_statistic_file; }

	void ReadNewsFile();
};

void RobotControll::ReadNewsFile() {
	ifstream	file("News_2007_2015.csv");
	ReadCSV Row;
	while (file >> Row)
	{
		m_input_news.SetDate(Row[0]);
		m_input_news.SetCurrency(Row[1]);
		m_input_news.SetDescription(Row[2]);
		m_input_news.SetImpact(Row[3]);
		m_input_news.SetActual(Row[4]);
		m_input_news.SetForecast(Row[5]);
		m_input_news.SetPrevious(Row[6]);

	}
	m_input_news.ShowDate(10);
	m_input_news.ShowCurrency(10);
	m_input_news.ShowDescription(10);
	m_input_news.ShowImpact(10);
	m_input_news.ShowActual(10);
	m_input_news.ShowForecast(10);
	m_input_news.ShowPrevious(10);
}

int main() {
	RobotControll GrandControll;
	GrandControll.SetNewsFile("News_2007_2015.csv");
	GrandControll.ReadNewsFile();

	return 0;
}


