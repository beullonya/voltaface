#include <limits>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <random>


class CSVreader {

public	:
	std::stringstream readcsv();
	std::vector<std::vector<std::string>> csvpath(std::stringstream &csv_str);
};

// csv파일 읽기
std::stringstream CSVreader::readcsv() {

	std::cout << "CSV 파일 읽는 중" << std::endl;
	std::stringstream csv_str;

	std::ifstream file;
	file.open("contents.csv");


	csv_str << (file.rdbuf());
	std::cout << csv_str.str();

	std::cout << std::endl;
	std::cout << "csv저장중" << std::endl;
	std::cout << std::endl;

	return csv_str;
}


std::vector<std::vector<std::string>> CSVreader::csvpath(std::stringstream &csv_str) {
	//CSV 2차원 벡터로 파싱

	std::vector<std::vector<std::string>> csv_mat;
	std::vector<std::string> csv_string;
	std::string buffer;


	int i = 0;
	csv_mat.push_back(csv_string);
	while (getline(csv_str, buffer, ',') ) {  // 2차원 벡터로 파싱 ',' 쉼표에 따라서 1차원 벡터 (col)
		
		if (buffer.find("\n") != std::string::npos) { // '\n' 개행문자 진입시 2차원 벡터 (row)
			buffer.erase(std::remove(buffer.begin(), buffer.end(), '\n'), buffer.end()); // 개행문자 제거
			csv_mat.push_back(csv_string);
			i++;
		}
		csv_mat[i].push_back(buffer);
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


	return csv_mat;
}

// 


// 문자열 변환 기능
class txt {

public:


	std::vector<std::string> change_text(std::vector<std::string>& vec_string, std::vector<std::vector<std::string>> csv_mat);

	void checkstring(std::vector<std::string> &input_txt);

};


std::vector<std::string> txt::change_text(std::vector<std::string>& vec_string, std::vector<std::vector<std::string>> csv_mat) {
	
	std::cout << "		<< 변환 중 >>"  << std::endl;
	
	std::string bin_space = "\0";
	std::string bin_enter = "\n";

	// 난수 생성
	
	
	
	for (int i = 0; i < vec_string.size(); i++) {
		for (int j = 0; j < csv_mat.size(); j++) {
			bool is_changed = false;

			for (int k = 0; k < csv_mat[j].size(); k++) {
				if (is_changed == false) { // 변환이 되었는지 확인

					if (vec_string[i].find((std::string)csv_mat[j][k]) != std::string::npos) {
						if (csv_mat[j][k].compare(bin_space) == 0 || csv_mat[j][k].compare(bin_enter) == 0)	{
							break; }

						std::vector<std::string> compare_array;
						int count = 0;

						for (int n = 0; n < csv_mat[j].size(); n++) {

							if (csv_mat[j][n].compare(bin_space) == 0 || csv_mat[j][k].compare(bin_enter) == 0) {
								break;	}

							if (k != n) {
								compare_array.push_back(csv_mat[j][n]);
								count++;
							}					
						}


						if (count - 1 == 0) {
							vec_string.at(i).replace(vec_string.at(i).find((std::string)csv_mat[j][k]), ((std::string)csv_mat[j][k]).length(), (std::string)compare_array[0]);
							is_changed = true;
						}

						else if (count - 1 > 0) {

							std::random_device rd;
							std::mt19937 gen(rd());
							std::uniform_int_distribution<int> dis(0, count - 1); // 오버플로우 되지 않게 -1 함.
							//난수 범위 CSV안에있는 원소 갯수만큼 count로할당

							vec_string.at(i).replace(vec_string.at(i).find((std::string)csv_mat[j][k]), ((std::string)csv_mat[j][k]).length(), (std::string)compare_array[dis(gen)]);

							is_changed = true;
						}

						compare_array.clear();
						std::vector<std::string>().swap(compare_array);

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

	return vec_string;
}

void txt::checkstring(std::vector<std::string> &input_txt) {

	void change_text(std::vector<std::string> &input_txt, std::vector<std::string> const& object, std::vector<std::string> const& chan_txt);
}



// 


class Input_text {

public:
	
	Input_text();
	std::vector<std::string> open_file();
	void save_file(std::vector<std::string> vec_str);

};



int main() {

	txt a;
	CSVreader C;
	Input_text num;

	std::stringstream str;
	str = C.readcsv();
	
	std::vector<std::vector<std::string>>csv_mat;
	csv_mat = C.csvpath(str);

	std::cout << " << 텍스트 변환 프로그램 >>" << std::endl;
	
	std::vector<std::string> vec_string;
	vec_string = num.open_file();


	a.change_text(vec_string, csv_mat);
	num.save_file(vec_string);

	std::cout << "완료되었습니다" << std::endl;

	system("pause");
	return 0;
}


Input_text::Input_text() {
	
}

std::vector<std::string> Input_text::open_file() {


	char* name = (char*)malloc(30);
	memset(name, 0, 30);

	int size;

	std::cout << "읽을 파일의 이름을 입력하세요 예))'test.txt' " << std::endl;
	std::cin >> name;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "파일 여는 중" << std::endl;

	FILE* fp = fopen(name, "rt");

	fseek(fp, 0, SEEK_END);							//파일포인터를 끝으로 이동
	size = ftell(fp);								//현재 파일포인터 위치값을 size에 할당

	fseek(fp, 0, SEEK_SET);						 // 파일포인터 위치를 0에 셋팅

	char* file_text = (char*)malloc(size + 1);	 // fp 파일 크기만큼 동적할당

	memset(file_text, 0, size + 1);



	std::cout << fp << std::endl;

	fread(file_text, size + 1, 1, fp);

	std::cout << std::endl;


	fclose(fp);
	free(name);



	// 스트링 파일로 변환 char -> \n 부분을 벡터 요소로 구분.

	std::string str(file_text);				//char 문자열을 string으로 변환

	std::cout << str << std::endl;

	std::vector<std::string> vec_string;					// 벡터 문자열 선언
	std::string temp;									// 스트링 문자열 선언


	std::cout << std::endl;

	std::stringstream ss(str);				// stringstream 문자열안에 string으로 변환시킨 str문자열 할당하기




	int i = 0;

	while (getline(ss, temp, '\n')) {  // 2차원 벡터로 파싱 ',' 쉼표에 따라서 1차원 벡터 (col)

		vec_string.push_back(temp);
	}

										 // ss 에 있는 문자열을 getiline으로
											 //'\n' 개행문자가 있을 때마다 쪼개서 벡터에 할당

	std::cout << "2차원 벡터로 변환 출력" << std::endl;
	std::cout << std::endl;


	for (int i = 0; i < vec_string.size(); i++) {
			std::cout << vec_string.at(i) << '\n';
		}
		


	free(file_text);
	
	std::cout << std::endl;
	std::cout << std::endl;

	return vec_string;
}


void Input_text::save_file(std::vector<std::string> vec_string){

	// 파일 저장시키기
	std::cout << '\n' << std::endl;
	std::cout << "파일 저장 진행중" << std::endl;

	std::ofstream writefile;
	writefile.open("replaced.txt");

	if (writefile.is_open()) {
		for (int i = 0; i < vec_string.size(); i++) {
				writefile.write((vec_string.at(i)).c_str(), (vec_string.at(i)).size());
				writefile.write("\n", 1);
			
		}
	}

	writefile.close();

	std::cout << '\n' << std::endl;
	std::cout << "파일이 저장되었습니다." << std::endl;


}


