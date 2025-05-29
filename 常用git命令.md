检查哪些文件被 Git 跟踪：
git ls-files

检查哪些文件被 Git 忽略：
git status --ignored

停止跟踪特定文件并保留本地副本：
git rm --cached code/t1.cpp

停止跟踪所有文件:
git rm -r --cached .