
TARGET = iopccfg_bdb.elf

CFLAGS += -I$(SDKSTAGE)/usr/include/
CFLAGS += -I$(SDKSTAGE)/usr/include/iopccfg
CFLAGS += -I$(SDKSTAGE)/usr/include/iopccommon

LDFLAGS += -L$(SDKSTAGE)/usr/lib/ 
LDFLAGS += -lc -lpthread -lrt
LDFLAGS += -liopccommon

SRC = 
SRC += main.c

include Makefile.include.app
