TARGRT := main
HEADPATH := ./inc
SRCPATH := ./src
LIBPATH := /home/china/arm_libs/lib
LIBNAME := jpeg

#获取所有的.c文件
DEREND := $(wildcard $(SRCPATH)/*.c)

$(TARGRT) : $(DEREND)
	arm-linux-gcc $^ -o $@ -I$(HEADPATH) -L$(LIBPATH) -l$(LIBNAME) -pthread -lm


clean:
	rm -rf $(TARGRT)