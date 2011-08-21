## \file rules.mk
##
## \brief Provides the generic build rules for the platform supplemental libraries.
##
## \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
##
## To the extent possible under law, the author(s) have dedicated all copyright and related and
## neighboring rights to this software to the public domain worldwide. This software is distributed
## without any warranty.
##
## You should have received a copy of the CC0 Public Domain Dedication along with this software.
## If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

# Directory
DIR 		:= $(dir $(word $(shell echo $$[$(words $(MAKEFILE_LIST)) - 1]), $(MAKEFILE_LIST)))

# Generated Build Parameters
NAME		:= lib/lib$(patsubst $(CURDIR)/platform/%/,%,$(DIR)).a

# Stored Build Parameters
$(DIR)_INCLUDE		:= $(INCLUDE)

# Build File List
PLATFORM_SOURCE := $(shell find $(DIR)src -type f -name "*.c" -or -name "*.cpp")
PLATFORM_SOURCE += $(shell find $(DIR)src -type f -name "*.s" -or -name "*.S")

# Add to globals
OBJECT += $(addsuffix .o,$(PLATFORM_SOURCE))
DEPEND += $(addsuffix .d,$(PLATFORM_SOURCE))
