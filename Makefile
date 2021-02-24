######################################################################
# Project FreeRTOS blink template
######################################################################

RTOS_DIR = extern/FreeRTOS

BINARY   = blue_drv8825

RTOS_FILES = ${RTOS_DIR}/heap_4.c ${RTOS_DIR}/list.c ${RTOS_DIR}/port.c ${RTOS_DIR}/tasks.c ${RTOS_DIR}/opencm3.c

SRCFILES   = src/main.cpp ${RTOS_FILES}
LDSCRIPT   = stm32f103c8t6.ld

# In this include all build take place.
include Makefile.incl

CFLAGS    += -I./extern/FreeRTOS -I./src
CXXFLAGS  += -I./extern/FreeRTOS -I./src

libs:
	$(MAKE) -j -C extern/libopencm3 TARGETS=stm32/f1

distclean: clean
	$(MAKE) -C extern/libopencm3 clean

