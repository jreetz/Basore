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
all: $(CURDIR)/include/configuration.h includes files
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

# Include Rule Sets
-include $(CURDIR)/platform/$(ARCH)/rules.mk
-include $(CURDIR)/platform/$(SYSTEM)/rules.mk
-include $(CURDIR)/platform/$(COMPILER)/rules.mk
-include $(CURDIR)/platform/$(ARCH)-$(SYSTEM)/rules.mk
-include $(CURDIR)/platform/$(ARCH)-$(COMPILER)/rules.mk
-include $(CURDIR)/platform/$(SYSTEM)-$(COMPILER)/rules.mk
-include $(CURDIR)/platform/$(ARCH)-$(SYSTEM)-$(COMPILER)/rules.mk

# Target: files
.PHONY: files
files: $(OBJECT)

# Target: configuration
# Outputs all configuration parameters to <configuration.h>
$(CURDIR)/include/configuration.h: makefile
	mkdir -p $(CURDIR)/include
	rm -f $@
	echo '#define __constant                    $(ATTRIBUTE_CONSTANT)'                  >> $@
	echo '#define __pure                        $(ATTRIBUTE_PURE)'                      >> $@
	echo '#define __noreturn                    $(ATTRIBUTE_NORETURN)'                  >> $@
	echo '#define __public                      $(ATTRIBUTE_PUBLIC)'                    >> $@
	echo '#define __protected                   $(ATTRIBUTE_PROTECTED)'                 >> $@
	echo '#define __private                     $(ATTRIBUTE_PRIVATE)'                   >> $@
	echo '#define _BASORE_ptrdiff_t             $(TYPE_POINTER_DIFFERENCE)'             >> $@
	echo '#define _BASORE_size_t                $(TYPE_SIZE)'                           >> $@
	echo '#define _BASORE_max_align_t           $(TYPE_MAXIMUM_ALIGNMENT)'              >> $@
	echo '#define _BASORE_wchar_t               $(TYPE_WIDE_CHARACTER)'                 >> $@
	echo '#define _BASORE_offsetof              $(MACRO_OFFSETOF)'                      >> $@
	echo '#define _BASORE_CHAR_UNSIGNED         $(CONDITION_CHAR_UNSIGNED)'             >> $@
	echo '#define _BASORE_CHAR_BIT              $(LIMIT_BIT)'                           >> $@
	echo '#define _BASORE_SCHAR_MAX             $(LIMIT_CHAR)'                          >> $@
	echo '#define _BASORE_SHRT_MAX              $(LIMIT_SHORT)'                         >> $@
	echo '#define _BASORE_INT_MAX               $(LIMIT_INT)'                           >> $@
	echo '#define _BASORE_LONG_MAX              $(LIMIT_LONG)'                          >> $@
	echo '#define _BASORE_LLONG_MAX             $(LIMIT_LONG_LONG)'                     >> $@
	echo '#define _BASORE_va_list               $(TYPE_VA_LIST)'                        >> $@
	echo '#define _BASORE_va_start              $(MACRO_VA_BEGIN)'                      >> $@
	echo '#define _BASORE_va_end                $(MACRO_VA_END)'                        >> $@
	echo '#define _BASORE_va_arg                $(MACRO_VA_ARG)'                        >> $@
	echo '#define _BASORE_va_copy               $(MACRO_VA_COPY)'                       >> $@
	echo '#define _BASORE_HAS_INT8              $(CONDITION_INT8)'                      >> $@
	echo '#define _BASORE_HAS_INT16             $(CONDITION_INT16)'                     >> $@
	echo '#define _BASORE_HAS_INT32             $(CONDITION_INT32)'                     >> $@
	echo '#define _BASORE_HAS_INT64             $(CONDITION_INT64)'                     >> $@
	echo '#define _BASORE_HAS_UINT8             $(CONDITION_UINT8)'                     >> $@
	echo '#define _BASORE_HAS_UINT16            $(CONDITION_UINT16)'                    >> $@
	echo '#define _BASORE_HAS_UINT32            $(CONDITION_UINT32)'                    >> $@
	echo '#define _BASORE_HAS_UINT64            $(CONDITION_UINT64)'                    >> $@
	echo '#define _BASORE_int8_t                $(TYPE_INT8)'                           >> $@
	echo '#define _BASORE_int16_t               $(TYPE_INT16)'                          >> $@
	echo '#define _BASORE_int32_t               $(TYPE_INT32)'                          >> $@
	echo '#define _BASORE_int64_t               $(TYPE_INT64)'                          >> $@
	echo '#define _BASORE_uint8_t               $(TYPE_UINT8)'                          >> $@
	echo '#define _BASORE_uint16_t              $(TYPE_UINT16)'                         >> $@
	echo '#define _BASORE_uint32_t              $(TYPE_UINT32)'                         >> $@
	echo '#define _BASORE_uint64_t              $(TYPE_UINT64)'                         >> $@
	echo '#define _BASORE_int_least8_t          $(TYPE_INT_LEAST8)'                     >> $@
	echo '#define _BASORE_int_least16_t         $(TYPE_INT_LEAST16)'                    >> $@
	echo '#define _BASORE_int_least32_t         $(TYPE_INT_LEAST32)'                    >> $@
	echo '#define _BASORE_int_least64_t         $(TYPE_INT_LEAST64)'                    >> $@
	echo '#define _BASORE_uint_least8_t         $(TYPE_UINT_LEAST8)'                    >> $@
	echo '#define _BASORE_uint_least16_t        $(TYPE_UINT_LEAST16)'                   >> $@
	echo '#define _BASORE_uint_least32_t        $(TYPE_UINT_LEAST32)'                   >> $@
	echo '#define _BASORE_uint_least64_t        $(TYPE_UINT_LEAST64)'                   >> $@
	echo '#define _BASORE_int_fast8_t           $(TYPE_INT_FAST8)'                      >> $@
	echo '#define _BASORE_int_fast16_t          $(TYPE_INT_FAST16)'                     >> $@
	echo '#define _BASORE_int_fast32_t          $(TYPE_INT_FAST32)'                     >> $@
	echo '#define _BASORE_int_fast64_t          $(TYPE_INT_FAST64)'                     >> $@
	echo '#define _BASORE_uint_fast8_t          $(TYPE_UINT_FAST8)'                     >> $@
	echo '#define _BASORE_uint_fast16_t         $(TYPE_UINT_FAST16)'                    >> $@
	echo '#define _BASORE_uint_fast32_t         $(TYPE_UINT_FAST32)'                    >> $@
	echo '#define _BASORE_uint_fast64_t         $(TYPE_UINT_FAST64)'                    >> $@
	echo '#define _BASORE_intptr_t              $(TYPE_INTPTR)'                         >> $@
	echo '#define _BASORE_uintptr_t             $(TYPE_UINTPTR)'                        >> $@
	echo '#define _BASORE_intmax_t              $(TYPE_INTMAX)'                         >> $@
	echo '#define _BASORE_uintmax_t             $(TYPE_UINTMAX)'                        >> $@
	echo '#define _BASORE_INT8_MAX              $(LIMIT_INT8)'                          >> $@
	echo '#define _BASORE_INT16_MAX             $(LIMIT_INT16)'                         >> $@
	echo '#define _BASORE_INT32_MAX             $(LIMIT_INT32)'                         >> $@
	echo '#define _BASORE_INT64_MAX             $(LIMIT_INT64)'                         >> $@
	echo '#define _BASORE_UINT8_MAX             $(LIMIT_UINT8)'                         >> $@
	echo '#define _BASORE_UINT16_MAX            $(LIMIT_UINT16)'                        >> $@
	echo '#define _BASORE_UINT32_MAX            $(LIMIT_UINT32)'                        >> $@
	echo '#define _BASORE_UINT64_MAX            $(LIMIT_UINT64)'                        >> $@
	echo '#define _BASORE_INT_LEAST8_MAX        $(LIMIT_INT_LEAST8)'                    >> $@
	echo '#define _BASORE_INT_LEAST16_MAX       $(LIMIT_INT_LEAST16)'                   >> $@
	echo '#define _BASORE_INT_LEAST32_MAX       $(LIMIT_INT_LEAST32)'                   >> $@
	echo '#define _BASORE_INT_LEAST64_MAX       $(LIMIT_INT_LEAST64)'                   >> $@
	echo '#define _BASORE_UINT_LEAST8_MAX       $(LIMIT_UINT_LEAST8)'                   >> $@
	echo '#define _BASORE_UINT_LEAST16_MAX      $(LIMIT_UINT_LEAST16)'                  >> $@
	echo '#define _BASORE_UINT_LEAST32_MAX      $(LIMIT_UINT_LEAST32)'                  >> $@
	echo '#define _BASORE_UINT_LEAST64_MAX      $(LIMIT_UINT_LEAST64)'                  >> $@
	echo '#define _BASORE_INT_FAST8_MAX         $(LIMIT_INT_FAST8)'                     >> $@
	echo '#define _BASORE_INT_FAST16_MAX        $(LIMIT_INT_FAST16)'                    >> $@
	echo '#define _BASORE_INT_FAST32_MAX        $(LIMIT_INT_FAST32)'                    >> $@
	echo '#define _BASORE_INT_FAST64_MAX        $(LIMIT_INT_FAST64)'                    >> $@
	echo '#define _BASORE_UINT_FAST8_MAX        $(LIMIT_UINT_FAST8)'                    >> $@
	echo '#define _BASORE_UINT_FAST16_MAX       $(LIMIT_UINT_FAST16)'                   >> $@
	echo '#define _BASORE_UINT_FAST32_MAX       $(LIMIT_UINT_FAST32)'                   >> $@
	echo '#define _BASORE_UINT_FAST64_MAX       $(LIMIT_UINT_FAST64)'                   >> $@
	echo '#define _BASORE_INTPTR_MAX            $(LIMIT_INTPTR)'                        >> $@
	echo '#define _BASORE_UINTPTR_MAX           $(LIMIT_UINTPTR)'                       >> $@
	echo '#define _BASORE_INTMAX_MAX            $(LIMIT_INTMAX)'                        >> $@
	echo '#define _BASORE_UINTMAX_MAX           $(LIMIT_UINTMAX)'                       >> $@
	echo '#define _BASORE_SIZE_MAX              $(LIMIT_SIZE)'                          >> $@
	echo '#define _BASORE_WCHAR_MAX             $(LIMIT_WIDE_CHARACTER)'                >> $@
	echo '#define _BASORE_WINT_MAX              $(LIMIT_WIDE_INT)'                      >> $@
	echo '#define _BASORE_SIG_ATOMIC_MAX        $(LIMIT_SIG_ATMOIC)'                    >> $@
	echo '#define _BASORE_div_t                 $(TYPE_DIVISION)'                       >> $@
	echo '#define _BASORE_ldiv_t                $(TYPE_LONG_DIVISION)'                  >> $@
	echo '#define _BASORE_lldiv_t               $(TYPE_LONG_LONG_DIVISION)'             >> $@

# Target: clean
# Cleans all generated files
.PHONY: clean
clean: makefile
	-$(RM) $(shell find $(CURDIR) -type f -name "*.t")
	-$(RM) $(shell find $(CURDIR) -type f -name "*.o")
	-$(RM) $(shell find $(CURDIR) -type f -name "*.d")
	-$(RM) -r $(CURDIR)/include
	-$(RM) -r $(CURDIR)/lib

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
CPPFLAGS := -std=c++0x -nostdinc++ -Weffc++ -fabi-version=0

# Compiler Flags
ifeq "$(LANG)" "c"
FLAGS := $(CFLAGS)
else
FLAGS := $(CPPFLAGS)
endif

FLAGS += -nodefaultlibs -nostartfiles -Wall -Wextra -pedantic -O3 -fno-builtin \
    -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn

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
		$(if $($(findstring $(CURDIR)/platform/$(ARCH)-$(SYSTEM)-$(COMPILER)/,$(<D))_INCLUDE),\
		    -I"$($(findstring $(CURDIR)/platform/$(ARCH)-$(SYSTEM)-$(COMPILER)/,$(<D))_INCLUDE)") \
		$(if $($(findstring $(CURDIR)/platform/$(SYSTEM)-$(COMPILER)/,$(<D))_INCLUDE),\
		    -I"$($(findstring $(CURDIR)/platform/$(SYSTEM)-$(COMPILER)/,$(<D))_INCLUDE)") \
		$(if $($(findstring $(CURDIR)/platform/$(ARCH)-$(COMPILER)/,$(<D))_INCLUDE),\
		    -I"$($(findstring $(CURDIR)/platform/$(ARCH)-$(COMPILER)/,$(<D))_INCLUDE)") \
		$(if $($(findstring $(CURDIR)/platform/$(ARCH)-$(SYSTEM)/,$(<D))_INCLUDE),\
		    -I"$($(findstring $(CURDIR)/platform/$(ARCH)-$(SYSTEM)/,$(<D))_INCLUDE)") \
		$(if $($(findstring $(CURDIR)/platform/$(COMPILER)/,$(<D))_INCLUDE),\
		    -I"$($(findstring $(CURDIR)/platform/$(COMPILER)/,$(<D))_INCLUDE)") \
		$(if $($(findstring $(CURDIR)/platform/$(SYSTEM)/,$(<D))_INCLUDE),\
		    -I"$($(findstring $(CURDIR)/platform/$(SYSTEM)/,$(<D))_INCLUDE)") \
		$(if $($(findstring $(CURDIR)/platform/$(ARCH)/,$(<D))_INCLUDE),\
		    -I"$($(findstring $(CURDIR)/platform/$(ARCH)/,$(<D))_INCLUDE)") \
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
