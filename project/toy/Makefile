# makfile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I../h

LDFLAGS        = -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-as



all: toy.elf



#additional rules for files

toy.elf: ${COMMON_OBJECTS} buzzer.o led.o switches.o sirenStateMachine.o brightToDimStateMachine.o dimToBrightStateMachine.o stateMachine.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^



load: toy.elf
	msp430loader.sh toy.elf



clean:
	rm -f *.o *.elf *~
