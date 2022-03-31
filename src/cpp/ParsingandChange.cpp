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

// #ifdef __cplusplus
// extern "C" {
// #endif

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

EMSCRIPTEN_KEEPALIVE
std::vector<std::string> ChangeText(std::vector<std::string>& vectorString, std::vector<std::vector<std::string>> csvMatrix) {
	
	std::cout << "		<< 변환 중 >>"  << std::endl;
	
	std::string binSpace = "\0";
	std::string binEnter = "\n";

	// 난수 생성
	
	
	
	for (int i = 0; i < vectorString.size(); i++) {
		for (int j = 0; j < csvMatrix.size(); j++) {
			bool isChanged = false;

			for (int k = 0; k < csvMatrix[j].size(); k++) {
				if (isChanged == false) { // 변환이 되었는지 확인

					if (vectorString[i].find((std::string)csvMatrix[j][k]) != std::string::npos) {
						if (csvMatrix[j][k].compare(binSpace) == 0 || csvMatrix[j][k].compare(binEnter) == 0)	{
							break; }

						std::vector<std::string> compareArray;
						int count = 0;

						for (int n = 0; n < csvMatrix[j].size(); n++) {

							if (csvMatrix[j][n].compare(binSpace) == 0 || csvMatrix[j][k].compare(binEnter) == 0) {
								break;	}

							if (k != n) {
								compareArray.push_back(csvMatrix[j][n]);
								count++;
							}					
						}


						if (count - 1 == 0) {
							vectorString.at(i).replace(vectorString.at(i).find((std::string)csvMatrix[j][k]), ((std::string)csvMatrix[j][k]).length(), (std::string)compareArray[0]);
							isChanged = true;
						}

						else if (count - 1 > 0) {

							std::random_device rd;
							std::mt19937 gen(rd());
							std::uniform_int_distribution<int> dis(0, count - 1); // 오버플로우 되지 않게 -1 함.
							//난수 범위 CSV안에있는 원소 갯수만큼 count로할당

							vectorString.at(i).replace(vectorString.at(i).find((std::string)csvMatrix[j][k]), ((std::string)csvMatrix[j][k]).length(), (std::string)compareArray[dis(gen)]);

							isChanged = true;
						}

						compareArray.clear();
						std::vector<std::string>().swap(compareArray);

					}
				}
					// 난수값 적용하여 단어 바꾸기
					// 만약에 바꾼단어가 ' ' 공백일 경우 또는 변환한 단어가 그대로인경우 다시 반복
			}
		}
	}
	
	
	/*
	for (int i = 0; i < vec_string.size(); i++) {
		std::cout << vec_string.at(i) << std::endl;
		
	}
	*/

	std::cout << '\n' << std::endl;
	std::cout << "문자열 변환 끝" << '\n' << std::endl;

	std::cout << '\n' << std::endl;
	std::cout << "변환완료!" << std::endl;

	return vectorString;
}


// #ifdef __cplusplus
// }
// #endif