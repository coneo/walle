subdir = net

all:
	@for dir in $(subdir);\
	do \
	make -C $$dir;\
	done

test:
	@for dir in $(subdir);\
	do \
	make test -C $$dir;\
	done

clean:
	@for dir in $(subdir);\
	do \
	cd $$dir && make clean;\
	cd ..;\
	done
