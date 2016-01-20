subdir = test
all:
	@for dir in $(subdir);\
	do \
	make -C $$dir;\
	done
clean:
	@for dir in $(subdir);\
	do \
	cd $$dir && make clean;\
	cd ..;\
	done
