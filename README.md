主要是增加了bin目录, 里面有对文件的分词脚本.

#构建
1. 按照cppjieba的步骤进行构建.
2.
```bash
cd bin
g++ -I../include -I../deps jieba_cut_file.cpp -o jieba_cut_file

```
