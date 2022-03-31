#include <limits>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <random>


class Input_text {

public:
	
	Input_text();
	std::vector<std::string> open_file();
	void save_file(std::vector<std::string> vec_str);

};



int main() {

	txt a;
	
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
