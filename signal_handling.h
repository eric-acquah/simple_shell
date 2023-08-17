#ifndef SIGNAL
#define SIGNAL

signal(SIGINT, sigint_handler);
signal(SIGQUIT, sigquit_handler);

#endif
