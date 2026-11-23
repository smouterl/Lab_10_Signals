CC = gcc
CFLAGS = -Wall -Wextra

PROGRAMS = signal_handler signal_alarm signal_segfault signal_sigaction recv_signal send_signal

.PHONY: all clean

all: $(PROGRAMS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)
