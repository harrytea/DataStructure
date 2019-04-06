git指令：
mkdir cd pwd ls(-ah) 

cd~/cd 返回home

cd ..  返回上一级

cd ../.. 返回上两级

cd - <menu> 返回指定目录

rm -rf .git 删除git

git init  git可管理的仓库（初始化git）

vi  编辑

cat 显示整个文件

git add <file>把文件添加给仓库

git add . 目录下的所有文件同时提交

git commit -m "message" 把文件提交给仓库

git status 查看仓库当前的状态

git diff <file>  查看修改的内容

git log
git log --pretty=oneline 查看版本提交历史

git reflog  查看命令历史

git reset --hard HEAD^  退回到上一个版本（HEAD~number）

git reset --hard commit_numb 退回到某个版本

git diff HEAD -- <file> 查看工作区和版本区的区别

git checkout -- <file> 放弃对工作区的修改

git reset HEAD <file> 撤销对暂缓区的add

rm <file> 删除工作区的文件

git rm <file> 删除一个文件

git commit -m "message" 删除版本库中的文件

git checkout -- <file> 恢复文件，从版本库里的版本替换工作区的版本

git remote add origin git@github.com:harrytea/<repos_name> 将本地内容与github关联

git pull -rebase origin master 将github中的文件与本地合并

git push -u origin master 将本地代码上传至github（第一次需要加-u）

git clone git@github.com:harrytea/<repos_name> 克隆仓库到本地

git branch 查看分支

git branch <name> 创建分支

git checkout <name> 切换分支

git checkout -b <name> 创建+切换分支

git merge <name> 合并某分支到当前分支

git branch -d <name> 删除分支