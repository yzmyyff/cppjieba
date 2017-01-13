#include <fstream>

#include "cppjieba/Jieba.hpp"
using namespace std;


int main(int argc, char** argv) {
  if (argc != 5){
    cout << "jieba_cut_file cppjieba user_dict in_file out_file" << endl;
  }

  const string jieba_path(argv[1]);
  const string dict_path = jieba_path + "dict/jieba.dict.utf8";
  const string hmm_path = jieba_path + "dict/hmm_model.utf8";
  const string idf_path = jieba_path + "dict/idf.utf8";
  const string stopword_path = jieba_path + "dict/stop_words.utf8";
  const string user_dict_path(argv[2]);

  cppjieba::Jieba jieba(dict_path, hmm_path,
		  user_dict_path, idf_path, stopword_path);

  vector<string> words;
  ifstream in(argv[3]);
  ofstream out(argv[4]);
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
