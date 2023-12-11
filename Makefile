DESTPATH = ${HOME}
LIBINSTPATH = ${DESTPATH}/lib
INCINSTPATH = ${DESTPATH}/include

CC = gcc
LD = gcc

COM_CFLAGS = -std=c11 -Wall -Wextra
OPT_CFLAGS = -flto -O3

RLS_CFLAGS = -DNDEBUG $(COM_CFLAGS) $(OPT_CFLAGS)
DBG_CFLAGS = -DDEBUG -g $(COM_CFLAGS)
LDFLAGS = -flto

.PHONY: all clean release debug test run_test

all: debug release test
	@echo "====== make all ======"

log.o: log.c log.h
	$(CC) $(RLS_CFLAGS) -c $< -o $@

log_dbg.o: log.c log.h
	$(CC) $(DBG_CFLAGS) -c $< -o $@

log_test.o: log_test.c
	$(CC) $(DBG_CFLAGS) -c $< -o $@
		
log_test.out: log_test.o log_dbg.o
	$(LD) -o $@ $^ $(LDFLAGS)
      
test: log_test.out
	@echo "====== make test ======"
    
clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.out
	@echo "====== make clean ======"

release: log.o
	@echo "====== make release ======"

debug: log_dbg.o
	@echo "====== make debug ======"
	
run_test: test
	./log_test.out
	@echo "****** test finished ******"
	@echo "====== make run_test ======"

install: log.o log_dbg.o
	install -d $(LIBINSTPATH)
	install -m 644 log.o ${LIBINSTPATH}
	install -m 644 log_dbg.o ${LIBINSTPATH}
	install -d ${INCINSTPATH}
	install -m 644 log.h ${INCINSTPATH}
	@echo "====== make install ======"
