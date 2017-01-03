#include <fstream>

#include "cppjieba/Jieba.hpp"
using namespace std;

const string JIEBA_PATH = "/home/rukuang/github/cppjieba/";
const string DICT_PATH = JIEBA_PATH + "dict/jieba.dict.utf8";
const string HMM_PATH = JIEBA_PATH + "dict/hmm_model.utf8";
const string IDF_PATH = JIEBA_PATH + "dict/idf.utf8";
const string STOP_WORD_PATH = JIEBA_PATH + "dict/stop_words.utf8";

int main(int argc, char** argv) {
  user_dict_path = argv[1]

  cppjieba::Jieba jieba(DICT_PATH, HMM_PATH,
		  user_dict_path, IDF_PATH, STOP_WORD_PATH);

  vector<string> words;
  ifstream in("/home/rukuang/data/novels.sent");
  ofstream out("/home/rukuang/data/novels.only_cut_word");
  string line;
  int num_line = 0;

  while (getline(in, line)) {
    jieba.Cut(line, words, true);
    out << limonp::Join(words.begin(), words.end(), " ") << endl;
    num_line++;

    if (num_line % 1000000 == 0) {
      cout << "已经处理" << num_line / 1000000 << "百万行." << endl;
    }
  }

  return EXIT_SUCCESS;
}
