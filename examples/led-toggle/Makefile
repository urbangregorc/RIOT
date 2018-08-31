# name of your application
APPLICATION = LedToggle

# If no BOARD is found in the environment, use this default:
BOARD ?= nucleo-f103rb

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../../

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
CFLAGS += -DDEVELHELP

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 0

FEATURES_REQUIRED += periph_gpio
# Modules to include:
USEMODULE += shell
USEMODULE += shell_commands
USEMODULE += ps



include $(RIOTBASE)/Makefile.include
