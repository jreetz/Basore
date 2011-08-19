## \file makefile
##
## \brief Provides the build rules and commands for the project.
##
## \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
##
## To the extent possible under law, the author(s) have dedicated all copyright and related and
## neighboring rights to this software to the public domain worldwide. This software is distributed
## without any warranty.
##
## You should have received a copy of the CC0 Public Domain Dedication along with this software.
## If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

# Build File List
SOURCE := $(shell find $(CURDIR)/src -type f -name "*.c" -or -name "*.cpp")
SOURCE += $(shell find $(CURDIR)/src -type f -name "*.s" -or -name "*.S")
OBJECT := $(addsuffix .o,$(SOURCE))
DEPEND := $(addsuffix .d,$(SOURCE))

# Test File List
TEST_SOURCE := $(shell find $(CURDIR)/test -type f -name "*.c" -or -name "*.cpp")
TEST_SOURCE += $(shell find $(CURDIR)/test -type f -name "*.s" -or -name "*.S")
TEST_OBJECT := $(addsuffix .t,$(TEST_SOURCE))

# Target
TARGET := $(CURDIR)/lib/lib$(LANG).a

# Default Target: all
# Compiles all files and builds library
.PHONY: all
all: includes $(CURDIR)/include/configuration.h $(OBJECT)
	mkdir -p $(dir $(TARGET))
	$(AR) rc $(TARGET) $(OBJECT)

# Target: includes
# Copies all include files to the public include directory
includes: makefile
	mkdir -p $(CURDIR)/include
	cp $(CURDIR)/src/include/c/* $(CURDIR)/include
	cp $(CURDIR)/src/include/platform/* $(CURDIR)/include

# Include Configuration
-include $(CURDIR)/platform/$(ARCH)/configuration.mk
-include $(CURDIR)/platform/$(SYSTEM)/configuration.mk
-include $(CURDIR)/platform/$(COMPILER)/configuration.mk
-include $(CURDIR)/platform/$(ARCH)-$(SYSTEM)/configuration.mk
-include $(CURDIR)/platform/$(ARCH)-$(COMPILER)/configuration.mk
-include $(CURDIR)/platform/$(SYSTEM)-$(COMPILER)/configuration.mk
-include $(CURDIR)/platform/$(ARCH)-$(SYSTEM)-$(COMPILER)/configuration.mk

# Target: configuration
# Outputs all configuration parameters to <configuration.h>
$(CURDIR)/include/configuration.h: makefile
	mkdir -p $(CURDIR)/include
	rm -f $@
	echo '#define __constant            $(ATTRIBUTE_CONSTANT)'                 >> $@
	echo '#define __pure                $(ATTRIBUTE_PURE)'                     >> $@
	echo '#define __noreturn            $(ATTRIBUTE_NORETURN)'                 >> $@
	echo '#define __public              $(ATTRIBUTE_PUBLIC)'                   >> $@
	echo '#define __protected           $(ATTRIBUTE_PROTECTED)'                >> $@
	echo '#define __private             $(ATTRIBUTE_PRIVATE)'                  >> $@

# Target: clean
# Cleans all generated files
.PHONY: clean
clean: makefile
	-$(RM) $(TEST_OBJECT)
	-$(RM) $(OBJECT)
	-$(RM) $(DEPEND)
	-$(RM) -r $(CURDIR)/include
	-$(RM) -r $(CURDIR)/lib
	-$(RM) $(CURDIR)/include/configuration.h

# Target: test
.PHONY: test
test: $(TEST_OBJECT)
	-@rc=0; count=0; rt=0; \
		for file in $(subst $(CURDIR)/,,$^); do \
			echo -n "./$$file"; ./$$file; \
			rt=$$?; \
			if [ $$rt == 0 ]; then \
				echo ": Success"; \
				rc=`expr $$rc + 1`; \
			else \
				echo ": Failure"; \
			fi; \
			count=`expr $$count + 1`; \
		done; \
		echo "Passed $$rc out of $$count tests.";

# C Compiler Flags
CFLAGS := -std=c1x -nostdinc

# C++ Compiler Flags
CPPFLAGS := -std=c++0x -nostdinc++ -Weffc++

# Compiler Flags
ifeq "$(LANG)" "c"
FLAGS := $(CFLAGS)
else
FLAGS := $(CPPFLAGS)
endif

FLAGS += -nodefaultlibs -nostartfiles -Wall -Wextra -Werror -pedantic

# Rule: C/C++ Compilation
%.c.o: %.c makefile
	$(CC) $(FLAGS) -MMD -MP -MT "$*.c.o $*.c.d" \
		-I"$(CURDIR)/include" \
		-I"$(subst $(CURDIR),$(CURDIR)/platform/$(ARCH)-$(SYSTEM)-$(COMPILER),$(<D))" \
		-I"$(subst $(CURDIR),$(CURDIR)/platform/$(SYSTEM)-$(COMPILER),$(<D))" \
		-I"$(subst $(CURDIR),$(CURDIR)/platform/$(ARCH)-$(COMPILER),$(<D))" \
		-I"$(subst $(CURDIR),$(CURDIR)/platform/$(ARCH)-$(SYSTEM),$(<D))" \
		-I"$(subst $(CURDIR),$(CURDIR)/platform/$(COMPILER),$(<D))" \
		-I"$(subst $(CURDIR),$(CURDIR)/platform/$(SYSTEM),$(<D))" \
		-I"$(subst $(CURDIR),$(CURDIR)/platform/$(ARCH),$(<D))" \
		-I"$(<D)" \
		-c -x $(LANG) $< -x none -o $@

# Rule: C++ Compilation

# Rule: Assembly Compilation
%.s.o: %.s makefile
	$(CC) -c $< -o $@

# Rule: C/C++ Test Compilation
%.c.t: %.c makefile
	$(CC) $(FLAGS) \
		-I"$(CURDIR)/include" \
		-x $(LANG) $< -x none $(TARGET) -o $@

# Dependency Resolution
-include $(DEPEND)
