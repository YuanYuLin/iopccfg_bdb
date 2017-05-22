
TARGET = iopccfg_bdb.elf

CFLAGS += -I$(SDKSTAGE)/usr/include/
CFLAGS += -I$(SDKSTAGE)/usr/include/iopccfg
CFLAGS += -I$(SDKSTAGE)/usr/include/libiopccommon

LDFLAGS += -L$(SDKSTAGE)/lib/ 
LDFLAGS += -L$(SDKSTAGE)/usr/lib/ 
LDFLAGS += -liopccommon
LDFLAGS += -lc -lpthread -lrt -ldl -ldb

SRC = 
SRC += main.c

include Makefile.include.app
