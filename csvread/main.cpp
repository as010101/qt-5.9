#include <QCoreApplication>


#include <iostream>

#include <string>

#include <fstream>

#include <vector>

#include "parse_csv.h"
int test_parse_cvs_1();
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
  test_parse_cvs_1();
    return a.exec();
}




int test_parse_cvs_1()

{

    std::ifstream file("D:/data/20191218_MarketData_600030.csv");



    std::vector<std::vector<std::string>> data;

    CSVIterator loop(file);

    for (; loop != CSVIterator(); ++loop) {

        CSVRow row = *loop;   //重载了*

        std::vector<std::string> tmp(row.size());

        for (int i = 0; i < row.size(); ++i) {

            tmp[i] = row[i];

        }

        data.emplace_back(tmp);

    }



    for (int i = 0; i < data.size(); ++i) {

        for (int j = 0; j < data[i].size(); ++j) {

            fprintf(stdout, "%s\t", data[i][j].c_str());

        }

        fprintf(stdout, "\n");

    }



    return 0;

}



