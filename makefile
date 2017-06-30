#终级目标
target=app
#makefile 中自己维护的变量$<当前规则依赖中的第一个，当前规则的$@目标 
#makefile中的函数使用
#wildcard函数主要的作用是根据路径去查找.c文件 然后赋值给 src变量
src=$(wildcard ./*.c)
#patsubst 函数把.c的文件替换到.o文件
#把src变量中.c文件替换到.o
obj=$(patsubst ./%.c,./%.o,$(src))
$(target):$(obj)
	gcc $(obj) -o $(target)
%.o:%.c
	gcc -c $< -o $@

#make clean  删除当前目录的.o文件与终级文件
.PHONY:clean	
clean:
	rm -rf $(obj) $(target)
#如果在clean 内部使用了别的命令 在命令前加上 - 则表示如果该命令失败了则再往下执行
