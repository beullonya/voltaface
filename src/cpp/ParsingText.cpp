#include <emscripten.h>
#include <limits>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <random>


EMSCRIPTEN_KEEPALIVE
std::vector<std::vector<std::string>> CsvParsing(std::stringstream &csvString) {
	//CSV 2차원 벡터로 파싱

	std::vector<std::vector<std::string>> csvMatrix;
	std::vector<std::string> csv_String;
	std::string buffer;


	int i = 0;
	csvMatrix.push_back(csv_String);
	while (getline(csvString, buffer, ',') ) {  // 2차원 벡터로 파싱 ',' 쉼표에 따라서 1차원 벡터 (col)
		
		if (buffer.find("\n") != std::string::npos) { // '\n' 개행문자 진입시 2차원 벡터 (row)
			buffer.erase(std::remove(buffer.begin(), buffer.end(), '\n'), buffer.end()); // 개행문자 제거
			csvMatrix.push_back(csv_String);
			i++;
		}
		csvMatrix[i].push_back(buffer);
	}

		std::cout << std::endl;
		std::cout << "csv저장완료" << std::endl;
		std::cout << std::endl;

	/*	//파싱한 문자 출력
	for (int i = 0; i < csv_mat.size(); i++) {
		for (int j = 0; j < csv_mat[i].size(); j++) {
			std::cout << csv_mat[i][j] << ',';
		}
		std::cout << std::endl;
	}*/
	
	std::cout << "파싱완료" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	return csvMatrix;
}
