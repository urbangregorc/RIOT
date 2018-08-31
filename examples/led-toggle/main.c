/*
 * LED TURN ON/OFF FROM SHELL
 * Runs on NUCLEO-F103RB board
 * @Make coomand : make BOARD=nucleo-f103rb all flash term
 * @Description : User can with writing led0 command in shell toggle LED LD2 on Nucleo-f103rb board.
 *
 * */
#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "led.h"
#include "board.h"
#include "periph_conf.h"
//For this include to work one needs to add FEATURES_REQUIRED += periph_gpio
#include "periph/gpio.h"

int echo(int argc, char **argv)
{
	printf("Number of arguments: %d\r\n", argc);
    if(argc > 1)
	{
		printf("First argument: %s\n\r", argv[1]);
	}
    printf("This is end of ECHO function\n\r");
    return 0;
}

int toggle(int argc, char **argv)
{
	if(argc > 1)
	{
		printf("First argument: %s\n\r", argv[1]);
	}
	LED_TOGGLE(0);
	printf("My LED has been toggled \r\n");
	return 0;
}


static const shell_command_t commands[] = {
    { "echo", "Prints first argument", echo },
	{ "led0", "Toggles LED0", toggle },
    { NULL, NULL, NULL }
};

int main(void)
{
    puts("This is Task-02");
    //Initialize PA5 - LED2 on nucleo
    gpio_init(GPIO_PIN(0,5), GPIO_OUT);
    //Turon LED
    gpio_set(GPIO_PIN(0,5));


    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
