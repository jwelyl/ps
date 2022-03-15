// https://programmers.co.kr/learn/courses/30/lessons/42893
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <unordered_map>

// #include <iostream>

using namespace std;

int p_num;  //  page 개수
unordered_map<string, int> page_map;    //  key : url, value : page index
unordered_map<int, double> link_score;     //  key : page index, value : link score

class Page {    //  page class
public:
    string page_name;                       //  page url
    double base_score;                      //  기본 점수
    int extern_link;                        //  외부 링크 개수
    double matching_score;                  //  매칭 점수
    vector<string> extern_link_arr;         //  외부 링크 목록

    Page() : base_score(0), extern_link(0), matching_score(0) {}
};

vector<Page> p_arr; 

int solution(string word, vector<string> pages) {
    int answer = 0;
    double max_match = -1;
    p_num = pages.size();

    // cout << "page 개수 : " << p_num << '\n';
    p_arr.assign(p_num, Page());

    // cout << "검색어 : " << word << '\n';

    // cout << "\n줄 단위로 읽기\n";
    for(int i = 0; i < p_num; i++) {
        // cout << "page " << i << '\n';

        stringstream ss(pages[i]);
        string tmp;

        while(getline(ss, tmp)) {
            int start;
            string page_link = "";      //  현재 page 링크
            string ex_link = "";        //  외부링크 주소
            bool is_sentence = false;   //  태그로 시작해서 태그로 끝나는가 확인
            string token = "";          //  한 단어
            bool is_word = false;       //  단어 시작 시 true, 끝났을 시 false;
            
            // cout << "문장 : " << tmp << '\n';

            for(int j = 0; j <= tmp.size(); j++) {
                if(('a' <= tmp[j] && tmp[j] <= 'z' || 'A' <= tmp[j] && tmp[j] <= 'Z') && j < tmp.size()) {
                    if(!is_word)   //  단어가 시작된 경우
                        is_word = true;
                    token.push_back(tmp[j]);
                }
                else {  
                    if(is_word) {   //  단어가 끝난 경우
                        if(!strcasecmp(token.c_str(), word.c_str()))  //  검색어와 단어가 일치할 경우
                            p_arr[i].base_score += 1;
                        // cout << "단어 : " << token << '\n';
                        token = "";
                    }
                }
            }

            for(int j = 0; j < tmp.size(); j++) {
                if(tmp[j] == '<') {
                    start = j;
                    is_sentence = true;
                    break;
                }
            }
            if(!is_sentence) continue;

            tmp = tmp.substr(start, tmp.size());

            if(tmp.substr(0, 8) == "<a href=") {    //  외부 링크일 경우
                for(int j = 9; j < tmp.size(); j++) {
                    if(tmp[j] != '\"')
                        ex_link.push_back(tmp[j]);
                    else {
                        p_arr[i].extern_link += 1;
                        // cout << "\n외부 링크 : " << '\"' << ex_link << "\"\n\n";
                        p_arr[i].extern_link_arr.push_back(ex_link);
                        ex_link = "";
                        break;
                    }
                }
            }
            else if(tmp.substr(0, 15) == "<meta property=") {   //  현재 page url
                for(int j = 33; j < tmp.size(); j++) {
                    if(tmp[j] != '\"')
                        page_link.push_back(tmp[j]);
                    else {
                        // cout << "\n현재 페이지 링크 : " << '\"' << page_link << "\"\n\n";
                        p_arr[i].page_name = page_link;
                        page_map[page_link] = i;    //  map에 page link를 key, page index를 value로 하여 삽입
                        page_link = "";
                        break;
                    }
                }
            }
        }

        // cout << "----------------------------------------------------------------\n";
        // cout << "page " << i << "\n";
        // cout << "기본 점수 : " << p_arr[i].base_score << '\n';
        // cout << "외부 링크 수 : " << p_arr[i].extern_link << '\n';
        // cout << "----------------------------------------------------------------\n";
    }
    // cout << "\n\n";

    for(int i = 0; i < p_num; i++) {
        // cout << "현재 페이지 주소 : " << p_arr[i].page_name << '\n';

        // cout << "현재 page에 연결된 링크\n";
        // for(int j = 0; j < p_arr[i].extern_link_arr.size(); j++)
        //     cout << p_arr[i].extern_link_arr[j] << '\n';
        // cout << "=========================================================\n";

        for(int j = 0; j < p_arr[i].extern_link_arr.size(); j++) {
            int to_page;
            
            if(page_map.find(p_arr[i].extern_link_arr[j]) != page_map.end()) {
                to_page = page_map[p_arr[i].extern_link_arr[j]];    //  현재 page에서 링크되는 외부 페이지의 index

                //  to_page index에 해당하는 페이지의 링크 점수 계산
                link_score[to_page] += (p_arr[i].base_score / p_arr[i].extern_link);
            }
        }
    }

    for(int i = 0; i < p_num; i++) {
        // cout << "page " << i << "(" << p_arr[i].page_name << ")의 기본 점수 : " << p_arr[i].base_score << '\n';
        // cout << "page " << i << "(" << p_arr[i].page_name << ")의 링크 점수 : " << link_score[i] << '\n';

        p_arr[i].matching_score = p_arr[i].base_score + link_score[i];
        // cout << "page " << i << "(" << p_arr[i].page_name << ")의 매칭 점수 : " << p_arr[i].matching_score << '\n';

        if(p_arr[i].matching_score > max_match) {
            max_match = p_arr[i].matching_score;
            answer = i;
        }

    }

    return answer;
}